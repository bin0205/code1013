#include <stdio.h>

int is_leap(int y);
int month_days(int m,int y);

int main(void)
{
	int year,month;
	int sumdays = 0;
	int firstweek;

	while(1)
	{
		printf("请输入90年后的日期(y/m):");
		scanf("%d/%d",&year,&month);
		if(year >= 1990 && month >= 1 && month <= 12)
			break;
	}
	for(int y = 1990;y < year;y++)
	{
		sumdays += (365+is_leap(y));
	}
	for(int m = 1;m < month; m++)
	{
		sumdays += month_days(m,year);
	}
	sumdays++;

	firstweek = sumdays % 7;
	printf("星期%d\n",firstweek);


	return 0;
}

int is_leap(int y)
{
	if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return 1;
	return 0;
}

int month_days(int m,int y)
{
	int sumdays = 0;

	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		sumdays = 31;
	}
	else if(m == 4 || m == 6 || m == 9 || m == 11)
	{
		sumdays = 30;
	}
	else
	{
		sumdays = 28+is_leap(y);
	}
	return sumdays;

}
