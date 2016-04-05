# include "mystack.h"



//检查是否为空栈
int IsEmpty_Stack(Stack S)
{
	return NULL == S->Next;
}

//创建栈，创建栈头
Stack CreateStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct Node_Stack));

	if(NULL == S)
	{
		char cm[MAX_STRINGLENGTH+1];
		sprintf_s(cm,MAX_STRINGLENGTH,"Fetal error in function CreatStack!");
		ErrorHand(ERROR, cm);
	}

	S->Next = NULL;
	MakeEmpty_Stack(S);
	return S;
}
void DisposeStack(Stack S)
{
	MakeEmpty_Stack(S);
}

//清空栈，调用pop
void MakeEmpty_Stack(Stack S)
{
	if(NULL == S)
	{
		char cm[MAX_STRINGLENGTH+1];
		sprintf_s(cm,MAX_STRINGLENGTH,"Must use CreatStack first!");
		ErrorHand(ERROR, cm);
	}
	else
	{
		while ( !IsEmpty_Stack(S))
		{
			Pop(S);
		}
	}
	return;
}

//入栈，插入位置表头之后
void Push(ElementType X, Stack S)
{
	Stack stmp;
	stmp = (Stack)malloc(sizeof(struct Node_Stack));

	if(NULL == stmp)
	{
		char cm[MAX_STRINGLENGTH+1];
		sprintf_s(cm,MAX_STRINGLENGTH,"Fetal error in function Push!");
		ErrorHand(ERROR, cm);
	}

	stmp->Element = X;
	stmp->Next = S->Next;
	S->Next = stmp;
	return;
}

//返回栈顶元素，注意判断是否为空
ElementType Top(Stack S)
{
	if(!IsEmpty_Stack(S))
		return S->Next->Element;
	else
	{
		char cm[MAX_STRINGLENGTH+1];
		sprintf_s(cm,MAX_STRINGLENGTH,"Empty Stack!");
		ErrorHand(ERROR, cm);
		return 0;
	}
}

//销毁栈顶结点
void Pop(Stack S)
{
	Stack stmp;

	if(IsEmpty_Stack(S))
	{
		char cm[MAX_STRINGLENGTH+1];
		sprintf_s(cm,MAX_STRINGLENGTH,"Empty Stack!");
		ErrorHand(ERROR, cm);
	}
	else
	{		
		stmp = S->Next;
		S->Next = S->Next->Next;
		free(stmp);
	}
	
	return;
}
