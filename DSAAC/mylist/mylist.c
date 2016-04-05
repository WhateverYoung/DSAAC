# include "mylist.h"

struct Node
{
	ElementType Element;
	Position Next;
};

//����б�
List MakeEmpty(List L)
{
	DeleteList(L);
	return L;
}

// �����Ƿ�Ϊ�ձ�O(1)
int IsEmpty(List L)
{
	return NULL == L->Next;
}

// ����p�Ƿ�Ϊ�������һ����㣬O(1)
int IsLast(Position p, List L)
{
	return NULL == p->Next;
}

//�ҵ���һ��X��λ�ã�û�з���NULL��O(N)
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

//ɾ����һ�γ��ֵ�X��û��X��ʲô��������O(N)
void DeleteFirstX(ElementType X, List L)
{
	Position p, pTmp;
	p = FindPrevious(X, L);
	
	//���Ǳ�β�����ҵ��ˣ�ɾ��֮
	if( !IsLast(p, L) )
	{
		pTmp = p->Next;
		p->Next = p->Next->Next;
		free(pTmp);
	}
	return;
}

//������ڱ�ͷ���Ҳ����򷵻ر�β��O(N)
Position FindPrevious(ElementType X, List L)
{
	Position p;
	p = L;
	while( NULL != p->Next && p->Next->Element != X)
		p = p->Next;

	return p;
}

//����λ��Ϊp֮��
//����p��λ�õ�ȷ�ڱ�L��
//����P��ΪNULL
//û��ʹ�õ�L����������ʵ�ֿ�����ҪL��Ϊ���Ժ��޸���׼�����ֿ��Բ��޸Ľӿڣ�O(1)
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

//ɾ���������н�㣬����ͷ���
void DeleteList(List L)
{
	Position p,pTmp;
	p = L->Next;

	//��ͷ�ÿ�
	L->Next = NULL;

	while(NULL != p)
	{
		pTmp = p->Next;
		free(p);
		p = pTmp;
	}

	return;
}

//����L���ձ����NULL
Position Header(List L)
{
	return L;
}

//���ص�һ����㣬û�о���NULL
Position First(List L)
{
	return L->Next;
}

//����p�ڱ��У��Ҳ���NULL
ElementType Retrieve(Position p)
{
	return p->Element;
}
