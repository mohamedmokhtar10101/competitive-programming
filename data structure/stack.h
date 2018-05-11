#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdlib.h>
//#define Stack_array_Based
typedef void * StackElement;
#ifdef Stack_array_Based
#define MAXSTACK 100
typedef struct stack
{
int top;
StackElement arr[MAXSTACK];
} Stack;
void initializeStack(Stack * ps) // postconditions stack is intialized
{
     ps->top = 0;
}
void push(StackElement e , Stack * ps) // preconditions stack is intialized and not full , postconditions the element is pushed  into the stack
{
    ps->arr[ ps->top++ ] = e;
}
StackElement pop(Stack * ps) // preconditions stack is intialized and not empty , postcontitions the element is poped from the stack into the element provided
{
     return ps->arr[ --ps->top ];
}
StackElement stackTop(Stack * ps) // preconditions stack ins intilized and not empty , postconditions  returns the top element of the stack
{
    return ps->arr[ ps->top-1 ];
}
int stackSize(Stack * ps) // preconditions stack is intialized , postconditions return the size of the stack
{
    return ps->top;
}
int stackFull(Stack * ps) // postconditions stack is intialized
{
    return ps->top >= MAXSTACK;
}
int stackEmpty(Stack * ps)
{
    return !ps->top;
}

void clearStack(Stack * ps) // postcondition stack is cleared
{
    ps->top = 0;
}
void traverseStack(Stack * ps, void (*display)(StackElement)) // preconditions stack is not empty , postconditions  pass every stack element to the function pointer provided by the user
{
    int counter;
    for(counter = ps->top-1; counter >= 0 ;counter--)
    {
        (*display)(ps->arr[ counter ]);
    }

}
#else
typedef struct stackNode
{
    StackElement e;
    struct stackNode * next;
}StackNode;
typedef struct stack
{
    StackNode * top;
    int size;
}Stack;
void initializeStack(Stack * ps) // postconditions stack is intialized
{
    ps->top = NULL;
    ps->size = 0;
}
void push(StackElement e , Stack * ps) // preconditions stack is intialized and not full , postconditions the element is pushed  into the stack
{
    StackNode * pNewNode = malloc(sizeof(StackNode));
    pNewNode->e = e;
    pNewNode->next = ps->top;
    ps->top = pNewNode;
    ps->size++;
}
StackElement pop(Stack * ps) // preconditions stack is intialized and not empty , postcontitions the element is poped from the stack into the element provided
{
    StackElement e = ps->top->e;
    StackNode * pNode = ps->top;
    ps->top = ps->top->next;
    free(pNode);
    ps->size--;
    return e;
}
StackElement stackTop(Stack * ps) // preconditions stack ins intilized and not empty , postconditions  returns the top element of the stack
{
    return ps->top->e;
}
int stackSize(Stack * ps) // preconditions stack is intialized , postconditions return the size of the stack
{
    return ps->size;
}
int stackFull(Stack * ps) // postconditions stack is intialized
{
    return 0;
}
int stackEmpty(Stack * ps)
{
    return !ps->top;
}
void clearStack(Stack * ps) // postcondition stack is cleared
{
    StackNode * pNode;
    pNode = ps->top ;
    while(pNode != NULL)
    {
        pNode = pNode->next;
        free(ps->top);
        ps->top = pNode;
    }
    ps->size = 0;
}
void traverseStack(Stack * ps, void (*display)(StackElement)) // preconditions stack is not empty , postconditions  pass every stack element to the function pointer provided by the user
{
    StackNode * pNode;
    for(pNode = ps->top ; pNode != NULL;pNode = pNode->next)
    {
        (*display)(pNode->e);
    }
}
#endif // Stack_array_Based






#endif // STACK_H_INCLUDED
