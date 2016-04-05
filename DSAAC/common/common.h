#ifndef __COMMON_H__
#define __COMMON_H__

# include <stdio.h>
# include <stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#define ElementType int
#define MAX_STRINGLENGTH 500

typedef enum
{
	RET_OK,
	RET_ERROR
}RetCode_EN;

typedef enum
{
	MESSAGE,
	WARNING,
	ERROR
}Type_Message;

void ErrorHand(Type_Message m, char* cm);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif