#include  <stdio.h>
#include  <stdlib.h>

//#define  swap(a,b)   (a=a^b,b=a^b，a=a^b）

void quicksort(int *array, int l,int r)
{
	if (l<r)
	{
		int i, j, x;
		i = l;
		j = r;
		x = array[i];

		while (i<j)
		{
			while (i < j&&array[j] > x)
			{
				j--;
			}

			if (i < j)
			{
				array[i] = array[j];
			}

			while (i < j&&array[i] < x)
			{
				i++;
			}

			if (i < j)
			{
				array[j] = array[i];

			}
		}

		array[j] = x;

		quicksort(array,l,i-1);
		quicksort(array, i+1, r);
	}
}

int main()
{
	int array[6] = { 20,40,30,10,60,50 };
	int  size = sizeof(array) / sizeof(array[0]);

	printf("before:");
	for (int j = 0; j < size; j++)
	{
		printf("%d\n", array[j]);
	}
	//快速排序：从小到大
	quicksort(array,0,size-1);

	printf("after:");
	for (int j = 0; j < size; j++)
	{
		printf("%d\n", array[j]);
	}

	system("pause");
}