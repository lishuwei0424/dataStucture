#include <iostream>

using namespace std;

struct  ListNode 
{ 
	double value;
	ListNode *next;
};


class List
{
public:
	List();
	~List();
	void CreateList();                                    //创建链表
	void Insert(double data, int index, bool flag = true);//链表插入
	void Delete(double index);                            //删除链表
	void printList();                                     //打印链表
	void getData(int index);                              //得到链表节点数据
	void exchange(int index1, int index2);                //交换数据
	int  getLength();                                     //得到链表的长度
private:
	ListNode *head;//头结点
};

List::List()
{
	head = new ListNode();
	head->next = NULL;
	cout << "链表创建成功" << endl;
}

List::~List()
{
	ListNode *p = head,*s;
	while (p->next!=nullptr)
	{
		s = p->next;
		p = s->next;
		delete s;
	}

	delete  p;
	delete  head;
}

void List::CreateList()
{
	cout << "开始创建链表" << endl;
	double data_num;
	cin >> data_num;
	for (int i = 0; i < data_num; i++)
	{
		cout << "第"<<i+1<<"节点"<< endl;
		double  data;
		cin >> data;
		Insert(data, getLength(), false);
	}
	cout << "链表创建完成" << endl;
}

void List::Insert(double data, int index, bool flag)
{
	ListNode *p = head, *s;

	if (index < 0)
	{
		cout << "请输入index大于0的数" << endl;
	}
	if (getLength()-1 < index)
	{
		//p = p->next;
		while(p->next!= NULL)
		{  
			p = p-> next;
		}

		s = new ListNode();
		s->value = data;
		s->next = NULL;
		p->next = s;	
		cout << "现将数据" << data << "插入链表尾部！" << endl;
	}
	else
	{    
		p = p->next;
		for (int i = 0; i < index-1; i++)
		{
			p = p->next;
		}

		s = new ListNode();
		s->value = data;
		s->next = p->next;
		p->next = s;
		cout << "现将数据" << data << "插入链表"<<index<<":" << endl;
	}
}

void  List::Delete(double index)
{
	ListNode *p = head, *s;
	p = p->next;
	for (int i = 0; i < index - 1; i++)
	{
		p = p->next;
	}

	s = p->next;
	p->next = s->next;

	delete s;
}

void List::printList()
{
	ListNode *p = head;
	
	if (p->next == NULL)
	{
		cout << "这是个空节点" << endl;
	}
	int i = 1;
	p = p->next; 
	while (p != NULL)
	{
		cout << "第" << i << "节点:" << p->value << endl;
		i++;
		p = p->next;
	}
	cout << endl;
}

void List::getData(int index)
{
	ListNode *p = head, *s;
	if (index < 0 || index > getLength()-1)
	{
		cout << "待获取元素不在链表中" << endl;
		return;
	}

	p = p->next;
	int i = 0;
	for (i = 0; i < index - 1; i++)
	{
		p = p->next;
	}

	cout << "第"<<i<<"节点:" << p->value<< endl;
}

void List::exchange(int index1, int index2)
{
	ListNode *p = head, *s1,*s2;
	s1 = new  ListNode();
	s2 = new  ListNode();

	int min = (index1 > index2) ? index2: index1;
	int max = (index2 > index1) ? index2 : index1;

	p = p->next;
	for (size_t i = 0; i < getLength(); i++)
	{
		if (i == min)
		{
			s1 = p;
		}

		if (i == max)
		{
			s2 = p;
		}
		p = p->next;
	}

	double data=s2->value;
	s2->value = s1->value;
	s1->value = data;
	cout << "第" << index1 << "个元素和" << "第" << index2 << "个元素交换成功" << endl;
}

int List::getLength()
{
	int len = 0;
	ListNode *p = head;

	while(p->next!=NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

int main(char argc, int argv[])
{
	List list;
	list.CreateList();
	list.printList();
	list.Insert(10, 2);
	list.Insert(20, 5);
	list.printList();
	list.Delete(2);
	list.printList();
	list.getData(1);
	list.getData(2);
	list.getData(3);
	list.getData(4);
	list.getData(10);
	list.exchange(1, 2);
	list.printList();
	list.exchange(4, 3);
	list.printList();

	getchar();
	return 0;
}