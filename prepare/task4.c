#include <stdio.h>

int main(void)
{
	int n;
	int res = 0;

	printf("请输入一个整数：");
	scanf("%d",&n);

	for(int i = 0;i <= n;i++)
	{
		res += i;//res = res + n;
	}

	printf("结果：%d\n",res);

	return 0;
}
