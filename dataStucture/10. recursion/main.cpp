#include <stdio.h>
#include <stdlib.h>

// 阶乘问题： https://www.jianshu.com/p/fb27841c8621
//问题解决： 跳楼梯，兔子生娃

//求和
int sum(int n)
{
	if (n > 0)
	{
		return  n + sum(n-1);
	}
	else
	{
		return 0;
	}
}

//求阶乘
int recursionMulity(int n)
{
	if (n > 1)
	{
		return  n* recursionMulity(n-1);
	}
	else
	{
		return 1;
	}
}

//斐波那契数列
int   Fibonacci_recu(int n)
{
	if (n <0)
	{
		return 0;
	}

	if (1==n)
	{
		return 1;
	}
    
	return  Fibonacci_recu(n - 1) + Fibonacci_recu(n - 2);

}

//斐波那契数列
int   Fibonacci(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}

	int frist = 0, second = 1;
	int N = 0;
	for (int i = 2; i <= n; i++)
	{
		N=frist + second;
		frist = second;
		second = N;
	}

	return N;
}

int main()
{
	printf("%d\n", recursionMulity(5));
	printf("%d\n", sum(5));

	printf("%d\n", Fibonacci(20));
	printf("%d\n", Fibonacci_recu(20));

	system("pause");
}


