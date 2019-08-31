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
	void CreateList();                                    //��������
	void Insert(double data, int index, bool flag = true);//�������
	void Delete(double index);                            //ɾ������
	void printList();                                     //��ӡ����
	void getData(int index);                              //�õ�����ڵ�����
	void exchange(int index1, int index2);                //��������
	int  getLength();                                     //�õ�����ĳ���
private:
	ListNode *head;//ͷ���
};

List::List()
{
	head = new ListNode();
	head->next = NULL;
	cout << "�������ɹ�" << endl;
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
	cout << "��ʼ��������" << endl;
	double data_num;
	cin >> data_num;
	for (int i = 0; i < data_num; i++)
	{
		cout << "��"<<i+1<<"�ڵ�"<< endl;
		double  data;
		cin >> data;
		Insert(data, getLength(), false);
	}
	cout << "���������" << endl;
}

void List::Insert(double data, int index, bool flag)
{
	ListNode *p = head, *s;

	if (index < 0)
	{
		cout << "������index����0����" << endl;
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
		cout << "�ֽ�����" << data << "��������β����" << endl;
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
		cout << "�ֽ�����" << data << "��������"<<index<<":" << endl;
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
		cout << "���Ǹ��սڵ�" << endl;
	}
	int i = 1;
	p = p->next; 
	while (p != NULL)
	{
		cout << "��" << i << "�ڵ�:" << p->value << endl;
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
		cout << "����ȡԪ�ز���������" << endl;
		return;
	}

	p = p->next;
	int i = 0;
	for (i = 0; i < index - 1; i++)
	{
		p = p->next;
	}

	cout << "��"<<i<<"�ڵ�:" << p->value<< endl;
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
	cout << "��" << index1 << "��Ԫ�غ�" << "��" << index2 << "��Ԫ�ؽ����ɹ�" << endl;
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