#include  <stdio.h>
#include  <stdlib.h>

//#define  swap(a,b)   (a=a^b,b=a^b，a=a^b）
int main()
{
	int array[6] = { 20,40,30,10,60,50 };
	int  size = sizeof(array) / sizeof(array[0]);

	//冒泡排序：从小到大
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = 0; j <i; j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j]=array[j]+array[j + 1];
				array[j+1] = array[j] - array[j + 1];
				array[j] = array[j] - array[j + 1];
			}
		}
	}

	for (int j = 0; j < size; j++)
	{
		printf("%d",array[j]);
	}

	system("pause");
}