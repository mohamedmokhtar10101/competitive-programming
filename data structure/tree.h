#include "stack.h"
#include<stdlib.h>
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
typedef double TreeElement;

typedef struct treeNode
{
TreeElement e;
struct treeNode * left;
struct treeNode * right;
} TreeNode;
typedef struct tree
{
    int size;
    int depth;
    TreeNode * root;
} Tree;
void initializeTree(Tree * pt)
{
    pt->size = 0;
    pt->depth = 0;
    pt->root = NULL;
}
int treeEmpty(Tree * pt)
{
    return !pt->size;
}
int treeFull(Tree * pt)
{
    return 0;
}
int treeSize(Tree * pt)
{
    return pt->size;
}
int treeDepth(Tree * pt)
{
    return pt->depth ;
}
static int treeSizeRecAux(TreeNode * pt)
{
    if(!pt)
        return 0;

    return  1 + treeSizeRecAux(pt->left) + treeSizeRecAux(pt->right);
}
int treeSizeRec(Tree *pt)
{
    return treeSizeRecAux(pt->root);
}
static int treeDepthRecAux(TreeNode * pt)
{
    if(!pt)
        return 0;
    int a = treeDepthRecAux(pt->left);
    int b = treeDepthRecAux(pt->right);
    return a > b ? a + 1 : b + 1;
}
int treeDepthRec(Tree *pt)
{
    return treeDepthRecAux(pt->root);
}
static void insertBSTRecAux(int * depth , TreeNode ** pt , TreeElement e)
{
    if(*pt == NULL)
    {
        *pt = malloc(sizeof(TreeNode));
        (*pt)->e = e;
        (*pt)->left = NULL;
        (*pt)->right = NULL;
    }
    else if (e < (*pt)->e)
        insertBSTRecAux(depth , &(*pt)->left , e);
    else
        insertBSTRecAux(depth , &(*pt)->right , e);
    (*depth)++;
}
void insertBSTRec(Tree * pt , TreeElement e)
{
    int depth = 0;
    insertBSTRecAux(&depth , &pt->root , e);
    pt->depth = pt->depth > depth ? pt->depth : depth;
    pt->size++;
}
void insertBST(Tree * pt , TreeElement e)
{
    TreeNode ** t = &pt->root;
    int depth = 0;

    while(*t)
    {
        if(e < (*t)->e)
            t = &(*t)->left;
        else
            t = &(*t)->right;
     depth++;
    }
    depth++;
    *t = malloc(sizeof(TreeNode));
    (*t)->e = e;
    (*t)->left = NULL;
    (*t)->right = NULL;
    pt->size ++;
    pt->depth = pt->depth > depth ? pt->depth : depth;

}
static void deleteTreeNode(TreeNode ** pt )
{

   TreeNode * hold;
   TreeNode *hold2;
   TreeNode ** temp;
   if((*pt)->left == NULL)
   {
       hold = (*pt)->right;
       free(*pt);
       *pt = hold;

   }
   else  if((*pt)->right == NULL)
   {
       hold = (*pt)->left;
       free(*pt);
       *pt = hold;
   }
   else
   {
        if((*pt)->left->right == NULL)
        {
            free(*pt);
            *pt = (*pt)->left;
        }

        else
        {
            temp = &(*pt)->left;

            while((*temp)->right != NULL)
            {
                hold =  *temp;
                temp = &(*temp)->right;
            }
              hold2 = (*temp)->left;
            (*temp)->left = (*pt)->left;
            (*temp)->right = (*pt)->right;
            free(*pt);
            *pt = *temp;
            hold->right = hold2;

        }
   }

}
void deleteFromTree(Tree * pt , TreeElement e)
{
    TreeNode ** t = &pt->root;
   // TreeNode * previous = t;
    while(*t)
    {
        if((*t)->e == e)
            break;
        else if (e < (*t)->e)
            t = &(*t)->left;
        else
            t = &(*t)->right;
    }
    deleteTreeNode(t);

    pt->size--;


}
int findBST(Tree * pt , TreeElement e)
{
    TreeNode * t = pt->root;

    while(t)
    {
        if(e == t->e)
           return t->e;
        else if(e < t->e)
            t = t->left;
        else
            t = t->right;
    }
    return -1;
}

static int findBSTRecAux(TreeNode * pt , TreeElement e)
{
    if(!pt)
        return -1;
    else if(e == pt->e)
        return pt->e;
    else if(e < pt->e)
        return findBSTRecAux(pt->left , e);
    else
        return findBSTRecAux(pt->right , e);


}
int findBSTRec(Tree * pt , TreeElement e)
{
    return findBSTRecAux(pt->root , e);
}
static void inOrderTraverseRecAux(TreeNode * pt , void (*display)(TreeElement))
{
    if(pt != NULL)
    {
        inOrderTraverseRecAux(pt->left , display);
        (*display)(pt->e);
        inOrderTraverseRecAux(pt->right , display);
    }
}
static void inOrderTraverseAux(Tree * pt , void (*display)(TreeElement))
{
    Stack s;
    int i = 0;
    int j = 0;
    int size = pt->size;
    TreeElement e;
     void * p = pt->root;

       initializeStack(&s);
       for(i = 0; i < size ;i++)
        {

           push(p , &s);
           p = ((TreeNode *)p)->left;
           if(p == NULL)
           {
               while(!stackEmpty(&s) && j!= 2)
               {
                   p = pop(&s);
                   e = ((TreeNode *)p)->e;
                   (*display)(e);
                   j++;
               }
               j = 0;
               p =((TreeNode *)p)->right;
           }
        }

}
static void inOrderTraverseAux2(Tree * pt , void (*display)(TreeElement))
{
    Stack s;
    TreeElement e;
     void * p = pt->root;
     if(p != NULL)
     {

       initializeStack(&s);

        do
        {
           while(p != NULL)
           {
                push(p , &s);
                p = ((TreeNode *)p)->left;
           }

           if(!stackEmpty(&s))
           {
               p = pop(&s);
               e = ((TreeNode *)p)->e;
               (*display)(e);
               p =((TreeNode *)p)->right;
           }

        }while(!stackEmpty(&s) || p);

     }

}
static void preOrderTraverseRecAux(TreeNode * pt , void (*display)(TreeElement))
{
    if(pt != NULL)
    {
        (*display)(pt->e);
        preOrderTraverseRecAux(pt->left , display);
        preOrderTraverseRecAux(pt->right , display);
    }
}static void postOrderTraverseRecAux(TreeNode * pt , void (*display)(TreeElement))
{
    if(pt != NULL)
    {
        postOrderTraverseRecAux(pt->left , display);
        postOrderTraverseRecAux(pt->right , display);
        (*display)(pt->e);
    }
}
static void clearTreeAux(TreeNode * pt)
{
    if(pt)
    {
        clearTreeAux(pt->left);
        clearTreeAux(pt->right);
        free(pt);
    }

}
void inOrderTraverseRec(Tree * pt , void (*display)(TreeElement))
{
    inOrderTraverseRecAux(pt->root , display);
}
void inOrderTraverse(Tree * pt , void (*display)(TreeElement))
{
    inOrderTraverseAux2(pt , display);
}
void preOrderTraverseRec(Tree * pt , void (*display)(TreeElement))
{
    preOrderTraverseRecAux(pt->root , display);

}

void postOrderTraverseRec(Tree* pt , void (*display)(TreeElement))
{
     postOrderTraverseRecAux(pt->root , display);
}
void clearTree(Tree *pt)
{
    clearTreeAux(pt->root);
    pt->size = 0;
    pt->root = NULL;

}
#endif // TREE_H_INCLUDED
