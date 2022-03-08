#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct stack{
    int* data;
    int top;
    int size;
}stack;

void push(stack* stack1,int data){
    if(NULL == stack1){
        printf("stack does not exist!!");
        exit(EXIT_FAILURE);
    }
    if(stack1->top != stack1->size){
        stack1->data[stack1->top] = data;
        stack1->top++;
    }
    else{
        printf("stack overflow!!");
        exit(EXIT_FAILURE);
    }
}

stack* createStack(stack* stack1){
    stack1 = (stack*)malloc(sizeof(stack));
    if(NULL == stack1){
        printf("stack can not allocated!!");
        exit(EXIT_FAILURE);
    }
    stack1->data = malloc(sizeof(int)*STACK_SIZE);
}

int main() {

    stack* stack1;

    return 0;
}
