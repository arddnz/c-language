#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE  10
#define EMPTY   -1

#define TRUE    1
#define FALSE   0

typedef int BOOL;

typedef struct tagStack {
    int* pData;// For pData part of the Stack ADT
    int size;// Size of the data part
    int sp;// The indicator for the new entries and removal
}STACK;


STACK* CreateStack(int size);
void DestroyStack(STACK* stack);

BOOL Push(STACK* pStack, int data);
BOOL IsFull(STACK* pStack);

BOOL Pop(STACK* pStack, int* pData);
BOOL Peek(STACK* pStack, int* pData);
BOOL IsEmpty(STACK* pStack);

STACK* CreateStack(int size)
{
    STACK* pStack = NULL;

    pStack = (STACK*)malloc(sizeof(STACK));
    if (NULL == pStack) {
        fprintf(stderr, "Cannot allocate memory for the STACK structure...");
        exit(EXIT_FAILURE);
    }
    pStack->pData = ( int*)malloc(sizeof(int) * size);
    if (NULL == pStack->pData) {
        fprintf(stderr, "Cannot allocate memory for the stack DATA ...");
        exit(EXIT_FAILURE);
    }
    pStack->size = size;
    // APPLY SECOND ASSUMPTION!
    pStack->sp = EMPTY;// SP points first data top REMOVE

    return pStack;
}

void DestroyStack(STACK* pStack)
{
    if (NULL != pStack) {
        free(pStack->pData);
        free(pStack);
    }
}

BOOL Push(STACK* pStack, int data)
{
    if (NULL != pStack) {
        if (TRUE == IsFull(pStack)) {
            printf("Stack OVERFLOW");
            return FALSE;
        }
        ++pStack->sp;
        pStack->pData[pStack->sp] = data;
        return TRUE;
    }
    return FALSE;
}

BOOL IsFull(STACK* pStack)
{
    return (pStack->sp == pStack->size) ? TRUE : FALSE;
}


BOOL Pop(STACK* pStack, int* pData)
{
    if (NULL != pStack) {
        if (TRUE == IsEmpty(pStack)) {
            printf("Stack UNDERFLOW\n");
            return FALSE;
        }

        *pData = pStack->pData[pStack->sp];
        --pStack->sp;
        return TRUE;
    }
    return FALSE;
}

BOOL Peek(STACK* pStack, int* pData)
{
    if (NULL != pStack) {
        if (TRUE == IsEmpty(pStack)) {
            printf("Stack UNDERFLOW\n");
            return FALSE;
        }

        *pData = pStack->pData[pStack->sp];
        return TRUE;
    }
    return FALSE;
}

BOOL IsEmpty(STACK* pStack)
{
    return (pStack->sp == EMPTY) ? TRUE : FALSE;
}



int main(int argc, char** argv)
{
    STACK* pStack1;
    int i, data;

    pStack1 = CreateStack(STACK_SIZE);


    for (i = 0; i < STACK_SIZE; ++i)
        if (FALSE == Push(pStack1, i + 1))
            printf("Can NOT PUSH data %d\n", i + 1);

    if (TRUE == Peek(pStack1, &data))
        printf("PEEKed data from stack : %d\n", data);

    for (i = 0; i < STACK_SIZE; ++i)
        if (TRUE == Pop(pStack1, &data))
            printf("POPed data from stack : %d\n", data);

    DestroyStack(pStack1);

    return EXIT_SUCCESS;
}