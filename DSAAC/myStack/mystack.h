#ifndef __MYSTACK_H__
#define __MYSTACK_H__

# include "common.h"

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */


typedef struct Node_Stack
{
	ElementType Element;
	struct Node_Stack *Next;
} *Stack;


int IsEmpty_Stack(Stack S);
Stack CreateStack();
void DisposeStack(Stack S);
void MakeEmpty_Stack(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif