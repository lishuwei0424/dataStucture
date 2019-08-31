#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

/*
	ջ�Ĳ�����
	�����Ĳ�����
	1.����ջ
	2.����ջ
	3.����ջ
	4.����ջ��Ԫ��
	5.����ջ��Ԫ�أ�����ɾ��
*/

static int  *array = NULL;
static int  count;        //����ʵ�ʴ�С

//��������
int create_stack(int capacity)
{
	array = (int*)malloc(capacity * sizeof(int));

	if (!array)
	{
		printf("�����ڴ�ʧ��");
		return 0;
	}

	count = 0;

	return 1;
}

//���ٶ���
void free_stack()
{
	if (array)
	{
		free(array);
		array = NULL;
	}
}

//���Ӷ���Ԫ�ص���β
void push(int a)
{
	array[count] = a;
	count++;
}

//��ȡ����Ԫ��
int peek()
{
	return array[count-1];
}

//��ȡ����Ԫ��,����ɾ��
int pop()
{
	int value = array[count - 1];
	count--;
	return  value;
}

//�ж϶����Ƿ�Ϊ��
bool is_empty()
{
	return count == 0;
}


int main()
{
	create_stack(12);   //��������

	//��Ԫ��
	push(10);
	push(20);
	push(30);

	//��ȡ����Ԫ��
	int  temp = peek();
	printf("temp=%d", temp);

	for (int i = count - 1; i >= 0; i--)
	{
		printf("%d  ", array[i]);
	}

	//��ȡ��Ԫ�أ�����ɾ��
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