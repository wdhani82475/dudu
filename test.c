#继续完成
#include<stdio.h>
#include<string.h>
int main()
{
	char sz1[4] = {'a','b','c','d'};
	char sz2[10];
	strncpy(sz2,sz1,10);
	printf("%c\n",sz2[8]);
	return 0;
}
