# include "mylist.h"

struct Node
{
	ElementType Element;
	Position Next;
};

//清空列表
List MakeEmpty(List L)
{
	DeleteList(L);
	return L;
}

// 测试是否为空表，O(1)
int IsEmpty(List L)
{
	return NULL == L->Next;
}

// 测试p是否为表中最后一个结点，O(1)
int IsLast(Position p, List L)
{
	return NULL == p->Next;
}

//找到第一个X的位置，没有返回NULL，O(N)
Position Find(ElementType X, List L)
{
	Position p;
	p = L->Next;
	while( (NULL != p) && (p->Element != X) )
	{
		p = p->Next;
	}

	return p;
}

//删除第一次出现的X，没有X则什么都不做，O(N)
void DeleteFirstX(ElementType X, List L)
{
	Position p, pTmp;
	p = FindPrevious(X, L);
	
	//不是表尾，则找到了，删除之
	if( !IsLast(p, L) )
	{
		pTmp = p->Next;
		p->Next = p->Next->Next;
		free(pTmp);
	}
	return;
}

//假设存在表头，找不到则返回表尾，O(N)
Position FindPrevious(ElementType X, List L)
{
	Position p;
	p = L;
	while( NULL != p->Next && p->Next->Element != X)
		p = p->Next;

	return p;
}

//插入位置为p之后
//假设p的位置的确在表L中
//假设P不为NULL
//没有使用到L，但是其他实现可能需要L，为了以后修改做准备，又可以不修改接口，O(1)
void Insert(ElementType X, List L, Position p)
{
	Position pTmp;

	pTmp = (Position)malloc(sizeof(struct Node));
	if(NULL == pTmp)
	{
		char cm[MAX_STRINGLENGTH];
		sprintf(cm,"Fetal error in function Insert!");
		ErrorHand(ERROR, cm);
	}

	//Normal case
	pTmp->Element = X;
	pTmp->Next = p->Next;
	p->Next = pTmp;

	return;
}

//删除链表所有结点，除了头结点
void DeleteList(List L)
{
	Position p,pTmp;
	p = L->Next;

	//表头置空
	L->Next = NULL;

	while(NULL != p)
	{
		pTmp = p->Next;
		free(p);
		p = pTmp;
	}

	return;
}

//返回L，空表就是NULL
Position Header(List L)
{
	return L;
}

//返回第一个结点，没有就是NULL
Position First(List L)
{
	return L->Next;
}

//假设p在表中，且不是NULL
ElementType Retrieve(Position p)
{
	return p->Element;
}
