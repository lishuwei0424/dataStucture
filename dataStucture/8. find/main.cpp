#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main()
{
	int array[100];
	int value = 8;

	memset(array, 0, sizeof(int));
	for (int i = 0; i < 100; i++)
	{
		array[i] = i;
	}
	int mid = 0;
	int low = 0,high= sizeof(array) / sizeof(array[0])-1;
	while(low<=high)
	{   
		mid=(low + high)/2;
		if (array[mid] == value)
		{
			break;
		}
		
		if (array[mid] > value)
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
    
	printf("%d", array[mid]);

	system("pause");
}


