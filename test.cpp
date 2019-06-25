#include <iostream>
#include <string>
//#include<windows.h> 

using namespace std;

class node{
public:
	string num;			//ְ����
	string name;			//����
	string phone;			//�绰
	string bum;			//����
	node *next;
}Node;
//typedef struct node * PNode;

class Control
{
public:
	void jiemian();					//������ʾ
	void zhuce(node *head);			//ע��ְ����1��
	void xiugai(node *head);			//�޸�ְ����Ϣ��2��
	void shanchu(node *head);			//ɾ��ְ����Ϣ��3��
	void chaxun(node *head);			//��ѯְ����Ϣ��4��
	void pint(node *head);				//��ӡ������Ϣ��7��
	void tongji(node *head);			//ͳ��Ա������5��
	void paixv(node *head);				//��Ա������6��
};



void Control::jiemian()
{
	system("cls");
	cout << "\n\n\n";
	cout << "\t\t\t**************************************\n";
	cout << "\t\t\t*        ��ӭ����ְ������ϵͳ        *\n";
	cout << "\t\t\t*          1  ע����ְ��             *\n";
	cout << "\t\t\t*          2 �޸�ְ����Ϣ            *\n";
	cout << "\t\t\t*          3 ɾ��ְ����Ϣ            *\n";
	cout << "\t\t\t*          4 ��ѯְ����Ϣ            *\n";
	cout << "\t\t\t*          5 ���������Ϣ            *\n";
	cout << "\t\t\t*          6 ͳ��Ա����Ϣ            *\n";
	cout << "\t\t\t*          7 ����Ա����Ϣ            *\n";
	cout << "\t\t\t**************************************\n";
	cout << "\n\n\t\t����������ѡ��";
}

void Control::zhuce(node *head)
{
	
	node *p = new node;
	p->next = NULL; 
	system("cls");//����
	cout << "\n\n\n";
	cout << "\t\t\t������ְ���ţ�";
	cin >> p->num;
	cout << "\n\t\t\t���������֣�";
	cin >> p->name;
	
	cout << "\n\t\t\t������绰��";
	cin >> p->phone;
	cout << "\n\t\t\t�����벿�ţ�";
	cin >> p->bum;
	string x = p->bum;
	if(head->next == NULL) {
		head->next = p;
	}
	else
	{
		node *i = head->next;
		while (1) {
			if(!i)
			{
				return;
			}
			if (i->num==x) {
				cout << "����Ա��Ϣ�Ѵ���\n";
				return;
			}
			else {
				i=i->next;
			}
		}
		i->next = p;
	}
}

void Control::xiugai(node* head)
{
	string str1;
	int flag = 0;

	system("cls");
	cout << "\n\n\n";
	cout << "\t\t\t������Ҫ�޸��˵�ְ���ţ�";
	cin >> str1;

	node *temp = head->next;
	while (temp != head)
	{
		if (temp->num == str1)
		{
			flag = 1;
			cout << "\n\t\t\t�������޸ĺ�����֣�";
			cin >> temp->name;
			cout << "\n\t\t\t�������޸ĺ�ĵ绰��";
			cin >> temp->phone;
			cout << "\n\t\t\t�������޸ĺ�Ĳ��ţ�";
			cin >> temp->bum;
			
			break;
		}

		temp = temp->next;
	}
	if (flag)
	{
		//Sleep(2);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t�޸ĳɹ���" << endl;
	}
	else
	{
		//Sleep(2);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t���޴��ˣ�" << endl;
	}
}

void Control::shanchu(node *head)
{
	system("cls");
	string str1;
	cout << "\n\n\n";
	cout << "\t\t\t������Ҫ�޸��˵�ְ���ţ�";
	cin >> str1;

	node *temp = head;
	int flag = 0;
	while (temp->next != head)
	{
		if (temp->next->num == str1)
		{
			flag = 1;
			node *p = temp->next;
			temp->next = p->next;
			delete p;
			break;
		}
		temp = temp->next;
	}
	if (flag)
	{
		//Sleep(2);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\tɾ���ɹ���" << endl;
	}
	else
	{
		//Sleep(2);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t���޴��ˣ�" << endl;
	}
}

void Control::chaxun(node *head)
{
	system("cls");
	string str1, str2;
	cout << "\n\n\n";
	cout << "\t\t\t������Ҫ��ѯ��ְ���ţ�";
	cin >> str1;
	cout << "\n\n\t\t\t������Ҫ��ѯ�����֣�";
	cin >> str2;

	int flag = 0;
	node *temp = head->next;
	while (temp != head)
	{
		if (temp->num == str1 && temp->name == str2)
		{
			flag = 1;
			cout << "\n\n" << " �绰��" << temp->phone << " ���ţ�"
				<< temp->bum << endl;
			break;
		}
		temp = temp->next;
	}

	if (flag == 0)
	{
		//Sleep(2);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t���޴��ˣ�" << endl;
	}
}



void Control::pint(node *head)
{
	node *temp = head->next;
	system("cls");//��������
	cout << "\n\n\n";
	int flag = 0;
	while (temp != head)
	{
		flag = 1;
		cout << "ְ���ţ�" << temp->num << " ���֣�" << temp->name << " �绰��" << temp->phone << " ���ţ�" << temp->bum << endl;
		temp = temp->next;
	}
	if (flag == 0)
	{
		//Sleep(2);
		system("cls");//��������
		cout << "\n\n\n\n\n\n\t\t\t\tϵͳ����ʱ���ˣ�" << endl;
	}
}
void Control::tongji(node *head) {
	system("cls");//��������
	cout << "\n\n\n";
	int flag = 0;
	if (head->next == NULL) {
		cout << "����Ϊ������" << endl;
		return;
	}
	node*p = head->next;//��ָ��ָ��ͷ���
	int i=0;
	while (1) {
		i++;
		p = p->next;
		if(!p)
			break;
	}
	cout << "����" << i << "��\n";
	

}
void Control::paixv(node *head) {
	system("cls");//��������
}


			//����ͷ���Ϊȫ�ֱ���
node* head = NULL;
int main()
{
	Control con;

	head = new node;
	head->next = NULL;
	
	char ecf;   //ѡ��
	char sel[100];

	while (1)
	{
		con.jiemian();
		cin >> ecf;

		switch (ecf)
		{
		case '1':				//ע����ְ��
		{
			con.zhuce(head);
			break;
		}
		case '2':				//�޸�ְ����Ϣ
		{
			con.xiugai(head);
			cout << "\n\n\t\t������������أ�";
			cin >> sel;
			break;
		}
		case '3':				//ɾ��ְ����Ϣ
		{
			con.shanchu(head);
			cout << "\n\n\t\t������������أ�";
			cin >> sel;
			break;
		}
		case '4':				//��ѯְ����Ϣ
		{
			con.chaxun(head);
			cout << "\n\n\t\t������������أ�";
			cin >> sel;
			break;
		}
		case '5':				//���������Ϣ
		{
			con.pint(head);
			cout << "\n\n\t\t������������أ�";
			cin >> sel;
			break;
		}
		case'6'://��ѯԱ������
		{
			con.tongji(head);
			cout << "\n\n\t\t������������أ�";
			cin >> sel;
			break;
		}
		default:
		{
			system("cls");//��������
			cout << "\n\n\n\n\n������1--7��" << endl;
			cout << "\n\n\t\t������������أ�";
			cin >> sel;
			break;
		}
		}
	}

	return 0;
}
