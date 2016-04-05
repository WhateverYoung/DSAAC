# include "mystack.h"



//����Ƿ�Ϊ��ջ
int IsEmpty_Stack(Stack S)
{
	return NULL == S->Next;
}

//����ջ������ջͷ
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

//���ջ������pop
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

//��ջ������λ�ñ�ͷ֮��
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

//����ջ��Ԫ�أ�ע���ж��Ƿ�Ϊ��
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

//����ջ�����
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
