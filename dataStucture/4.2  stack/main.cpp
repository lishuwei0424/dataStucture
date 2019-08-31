#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

/*******************************************************
	ջ�Ĳ�����(��������)
	�����Ĳ�����
	1.����ջ
	2.����ջ
	3.����ջ
	4.����ջ��Ԫ��
	5.����ջ��Ԫ�أ�����ɾ��
********************************************************/

struct node
{
	int value;
	struct node *next;
};
static struct node  *phead = NULL;  //������

//��������
static struct node* create_node(int value)
{
	struct node *pnode = (struct node*)malloc(sizeof(struct node));

	if (!pnode)
	{
		printf("�����ڴ�ʧ��");
		return NULL;
	}

	pnode->value = value;
	pnode->next = NULL;


	return pnode;
}

//���ٶ���
static int destroy_single_link()
{
	struct  node *p = phead, *s = NULL;

	while (p)
	{
		s = p;
		p = p->next;

		free(s);
	}


	return 0;
}

// ��val���ӵ����е�ĩβ
static void add(int val)
{
	if (!phead)
	{
		phead = create_node(val);
		return;
	}


	struct node *pnode = create_node(val);
	struct node *p = phead;
	while (p->next)
	{
		p = p->next;
	}

	p->next = pnode;
}

//��ȡջ��Ԫ��
int front()
{
	struct  node *p = phead;

	while (p->next)
	{
		p = p->next;
	}

	return  p->value;
}

//��ȡ����Ԫ��,����ɾ��
int pop()
{
	struct  node *p = phead, *s;
	s = new struct node();

	while (p->next)
	{
		s = p;
		p = p->next;
	}

	s->next = NULL;
	int  value = p->value;

	return  value;
}

//�ж϶����Ƿ�Ϊ��
bool is_empty()
{
	return  phead == NULL;
}


static int size()
{
	struct  node *p = phead;

	int count = 0;
	while (p)
	{
		count++;
		printf("%d  ", p->value);
		p = p->next;
	}

	return count;
}


void  print_queue()
{
	struct  node *p = phead;
	int count = 0;
	while (p)
	{
		printf("%d  ", p->value);
		p = p->next;
	}
}
int main()
{
	//��Ԫ��
	add(10);
	add(20);
	add(30);

	//��ȡ����Ԫ��
	int  temp = front();
	printf("temp=%d", temp);

	print_queue();

	//��ȡ��Ԫ�أ�����ɾ��
	temp = pop();
	printf("temp=%d", temp);

	add(40);

	print_queue();

	size();
	printf("temp=%d", size());

	// ���ٶ���
	destroy_single_link();


	system("pause");
}