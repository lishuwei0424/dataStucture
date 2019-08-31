#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

/*
	栈的操作：
	包含的操作：
	1.创建栈
	2.销毁栈
	3.插入栈
	4.返回栈首元素
	5.返回栈首元素，并且删掉
*/

static int  *array = NULL;
static int  count;        //队列实际大小

//创建队列
int create_stack(int capacity)
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
void free_stack()
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
int peek()
{
	return array[count-1];
}

//获取队首元素,并且删除
int pop()
{
	int value = array[count - 1];
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
	create_stack(12);   //创建队列

	//放元素
	push(10);
	push(20);
	push(30);

	//获取队首元素
	int  temp = peek();
	printf("temp=%d", temp);

	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d  ", array[i]);
	}

	//获取队元素，并且删除
	temp = pop();
	printf("temp=%d", temp);

	push(40);

	for (int i = count-2; i >=0; i--)
	{
		printf("%d  ", array[i]);
	}

	free_stack();

	system("pause");
}