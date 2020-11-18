#include <stdio.h>

int main(void)
{
	int var;
	scanf("%d",&var);

	if(var % 2 == 0)
		printf("%d 是一个偶数\n",var);
	else
		printf("%d 是一个奇数\n",var);


	return 0;
}
