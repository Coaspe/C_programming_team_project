#include "common.h"

int rand_x(void)
{
	return (rand() % XAXIS);
}
int rand_y(void)
{
	return (rand() % YAXIS);
}
int rand_t(void)
{
	return (rand() % 4) + 2;
}