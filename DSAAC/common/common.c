# include "common.h"

void ErrorHand(Type_Message m, char* cm)
{
	switch(m)
	{
	case(MESSAGE):
		printf("Mesaage: %s \n",cm);
		break;
	case(WARNING):
		printf("Warning: %s \n",cm);
		break;
	case(ERROR):
		printf("Error: %s \n",cm);
		exit(EXIT_FAILURE);
	default:
		exit(EXIT_FAILURE);
	}
	return;
}