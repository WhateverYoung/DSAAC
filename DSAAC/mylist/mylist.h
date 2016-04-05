#ifndef __MYLIST_H__
#define __MYLIST_H__

# include "common.h"

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#define ElementType int
#define MAX_STRINGLENGTH 500

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position p, List L);
Position Find(ElementType X, List L);
void DeleteFirstX(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position p);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
ElementType Retrieve(Position p);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif