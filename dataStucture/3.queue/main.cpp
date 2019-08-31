#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

/*
	���У�
	�����Ĳ�����
	1.��������
	2.���ٶ���
	3.�������
	4.���ض���Ԫ��
	5.���ض���Ԫ�أ�����ɾ��
*/

static int  *array = NULL; 
static int  count;        //����ʵ�ʴ�С

//��������
int create_queue(int capacity)
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
void free_queue()
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
int front()
{
	return array[0];
}

//��ȡ����Ԫ��,����ɾ��
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

//�ж϶����Ƿ�Ϊ��
bool is_empty()
{
	return count == 0;
}

int main()
{
	create_queue(12);   //��������

    //��Ԫ��
	push(10);
	push(20);
	push(30);

	//��ȡ����Ԫ��
	int  temp=front();
	printf("temp=%d",temp);

	for (int i = 0; i < count; i++)
	{
		printf("%d  ", array[i]);
	}

	//��ȡ��Ԫ�أ�����ɾ��
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