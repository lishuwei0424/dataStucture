#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

/*******************************************************
	栈的操作：(链表操作)
	包含的操作：
	1.创建栈
	2.销毁栈
	3.插入栈
	4.返回栈首元素
	5.返回栈首元素，并且删掉
********************************************************/

struct node
{
	int value;
	struct node *next;
};
static struct node  *phead = NULL;  //队列首

//创建队列
static struct node* create_node(int value)
{
	struct node *pnode = (struct node*)malloc(sizeof(struct node));

	if (!pnode)
	{
		printf("分配内存失败");
		return NULL;
	}

	pnode->value = value;
	pnode->next = NULL;


	return pnode;
}

//销毁队列
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

// 将val添加到队列的末尾
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

//获取栈顶元素
int front()
{
	struct  node *p = phead;

	while (p->next)
	{
		p = p->next;
	}

	return  p->value;
}

//获取队首元素,并且删除
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

//判断队列是否为空
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
	//放元素
	add(10);
	add(20);
	add(30);

	//获取队首元素
	int  temp = front();
	printf("temp=%d", temp);

	print_queue();

	//获取队元素，并且删除
	temp = pop();
	printf("temp=%d", temp);

	add(40);

	print_queue();

	size();
	printf("temp=%d", size());

	// 销毁队列
	destroy_single_link();


	system("pause");
}