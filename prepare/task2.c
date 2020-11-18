/*
 1. 读入两个整型数，比较其大小
 2. 读入一个三位整型数,判断其是否为对称整型数.
 111 121 123
 */

#include <stdio.h>


int main(void)
{
	int n;
	printf("请输入一个三位整型数：");
	scanf("%d",&n);

	if(n < 100 || n > 1000)
		printf("不符合要求\n");
	else 
	{
		if(n / 100 == n % 10)
			printf("%d 是一个对称数\n",n);
		else
			printf("%d 不是\n",n);
	}

	return 0;
}
