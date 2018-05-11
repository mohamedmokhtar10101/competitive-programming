#include<stdlib.h>
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
typedef int ListElement;
#define List_array_Based
#define MAXLIST 100
#ifdef List_array_Based
typedef struct list
{
int size;
ListElement arr[MAXLIST];
} List;
void initializeList(List * pl)
{
    pl->size = 0;
}
void insertList(int position , ListElement e , List * pl) // preconditions  position must be >= 0 and <= size  , posconditions the element will be inserted in the right position
{
    int i;
    for(i = pl->size -1;i >= position ;i--)
    {
        pl->arr[ i + 1 ] = pl->arr[ i ];
    }
    pl->arr[ position ] = e;
    pl->size++;
}
ListElement deleteList(int position , List * pl) // preconditions position must be >= 0 and < size , postconditions the element will be deleted from the list
{

    int i;
    ListElement e = pl->arr[ position ];
    for(i = position +1  ; i < pl->size; i++)
    {
        pl->arr[ i - 1 ] = pl->arr[ i ];
    }
    pl->size--;
    return e;
}
ListElement retrieveList(int position , List * pl)
{
    return pl->arr[ position];
}
void replaceList(int position , ListElement e , List * pl)
{
    pl->arr[ position ] = e;
}
void clearList(List *pl)
{
    pl->size = 0;
}
void traverseList(List * pl , void (*display)(ListElement))
{
    int i;
    for(i = 0 ; i < pl->size ; i++)
        (*display)(pl->arr[ i ]);
}
int listEmpty(List * pl)
{
    return !pl->size;
}
int listFull(List * pl)
{
    return pl->size == MAXLIST;
}
int listSize(List * pl)
{
    return pl->size;
}
int binarySearch(ListElement e , List *pl)
{
    int middle ;
    int begin = 0;
    int end = pl->size-1;
    while(begin <= end)
    {
        middle = (begin + end ) / 2;
        if(pl->arr[ middle ] == e)
            return middle;
        else if(e < pl->arr[ middle ])
            end = middle - 1;
        else
            begin = middle + 1;
    }
    return -1;
}
#else
typedef struct listNode
{
ListElement e;
struct listNode * next;
} ListNode;
typedef struct list
{
int size;
ListNode * head;
} List;
void initializeList(List * pl)
{
    pl->size = 0;
    pl->head = 0;
}
void insertList(int position , ListElement e , List * pl) // preconditions  position must be >= 0 and <= size  , posconditions the element will be inserted in the right position
{
    ListNode * pNewNode = malloc(sizeof(ListNode));
    pNewNode->e = e;
    pNewNode->next = NULL;
    if(position == 0){
        pNewNode->next = pl->head;
        pl->head = pNewNode;
    }
    else
    {
     int i;
     ListNode * begin ;
     for(begin = pl->head ,i = 0;i < position-1 ;i++,begin = begin->next);
     pNewNode->next = begin->next;
     begin->next = pNewNode;
    }
    pl->size++;
}
ListElement deleteList(int position , List * pl) // preconditions position must be >= 0 and < size , postconditions the element will be deleted from the list
{
    ListElement e;
    ListNode * tmp;
    if(position == 0)
    {
       tmp = pl->head;
       e = pl->head->e;
       pl->head = pl->head->next;
    }
    else
    {
     int i;
     ListNode * begin ;
    for(begin = pl->head ,i = 0;i < position-1 ;i++,begin = begin->next);
    tmp = begin->next;
    e = begin->next->e;
    begin->next = begin->next->next;
    }
    free(tmp);
    pl->size--;
    return e;
}
ListElement retrieveList(int position , List * pl)
{
    int i;
    ListNode * begin;
    for(begin = pl->head , i=0; i< position ; i++,begin = begin->next);
    return  begin->e ;
}
void replaceList(int position , ListElement e , List * pl)
{
    int i;
    ListNode * begin;
    for(begin = pl->head , i=0;i< position ; i++,begin = begin->next);
    begin->e = e;
}
void clearList(List * pl)
{
    ListNode * tmp;
    while(pl->head != NULL)
    {
        tmp = pl->head->next;
        free(pl->head);
        pl->head = tmp;
    }
    pl->size = 0;
}
void traverseList(List * pl , void (*display)(ListElement))
{
    ListNode * begin;
    for(begin = pl->head ; begin != NULL ; begin = begin->next)
        (*display)(begin->e);
}
int listEmpty(List * pl)
{
    return !pl->size;
}
int listFull(List * pl)
{
    return 0;
}
int listSize(List * pl)
{
    return pl->size;
}
#endif // Queue_array_Based
void insertOrder(ListElement e , List *pl)
{
    int current ;
    int size = listSize(pl);
    ListElement tmp;
    for(current = 0 ; current < size; current++)
    {
        tmp = retrieveList(current , pl);
        if(e <= tmp)
            break;
    }
    insertList(current , e , pl);
}
#endif // LINKEDLIST_H_INCLUDED
