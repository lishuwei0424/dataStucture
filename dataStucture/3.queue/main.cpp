#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

/*
	队列：
	包含的操作：
	1.创建队列
	2.销毁队列
	3.插入队列
	4.返回队首元素
	5.返回队首元素，并且删掉
*/

static int  *array = NULL; 
static int  count;        //队列实际大小

//创建队列
int create_queue(int capacity)
{
	array = (int*)malloc(capacity * sizeof(int));

	if (!array)
	{
		printf("分配内存失败");
		return 0;
	}

	count = 0;

	return 1;
}

//销毁队列
void free_queue()
{
	if (array)
	{
		free(array);
		array = NULL;
	}
}

//增加队列元素到队尾
void push(int a)
{
	array[count] = a;
	count++;
}

//获取队首元素
int front()
{
	return array[0];
}

//获取队首元素,并且删除
int pop()
{
	int value= array[0];

	int i = 1;
	while (i < count )
	{
		array[i - 1] = array[i];
		i++;
	}

	count--;
	return  value;
}

//判断队列是否为空
bool is_empty()
{
	return count == 0;
}

int main()
{
	create_queue(12);   //创建队列

    //放元素
	push(10);
	push(20);
	push(30);

	//获取队首元素
	int  temp=front();
	printf("temp=%d",temp);

	for (int i = 0; i < count; i++)
	{
		printf("%d  ", array[i]);
	}

	//获取队元素，并且删除
	temp = pop();
	printf("temp=%d", temp);

	push(40);

	for (int i = 0; i < count; i++)
	{
		printf("%d  ", array[i]);
	}

	free_queue();

	system("pause");
}