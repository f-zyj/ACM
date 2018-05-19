#include  <stdio.h>

int main ()
{
	int m, n, temp, r, p;
	
	printf("请输入两个正整数（中间用空格间隔）：");

	scanf("%d%d", &m, &n);

	if (m<n)
	{
		temp=m;

		m=n;

		n=temp;
	}

	p=m*n;

	while (n != 0)
	{
		r=m%n;

		m=n;

		n=r;
	}

	printf("你输入的两个数的最大公约数是：%d\n", m);

	printf("你输入的两个数的最大公倍数是：%d\n", p/m);

	return 0;
}