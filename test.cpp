#include <iostream>
#include <string>
//#include<windows.h> 

using namespace std;

class node{
public:
	string num;			//职工号
	string name;			//名字
	string phone;			//电话
	string bum;			//部门
	node *next;
}Node;
//typedef struct node * PNode;

class Control
{
public:
	void jiemian();					//界面显示
	void zhuce(node *head);			//注册职工（1）
	void xiugai(node *head);			//修改职工信息（2）
	void shanchu(node *head);			//删除职工信息（3）
	void chaxun(node *head);			//查询职工信息（4）
	void pint(node *head);				//打印所有信息（7）
	void tongji(node *head);			//统计员工数（5）
	void paixv(node *head);				//将员工排序（6）
};



void Control::jiemian()
{
	system("cls");
	cout << "\n\n\n";
	cout << "\t\t\t**************************************\n";
	cout << "\t\t\t*        欢迎来到职工管理系统        *\n";
	cout << "\t\t\t*          1  注册新职工             *\n";
	cout << "\t\t\t*          2 修改职工信息            *\n";
	cout << "\t\t\t*          3 删除职工信息            *\n";
	cout << "\t\t\t*          4 查询职工信息            *\n";
	cout << "\t\t\t*          5 浏览所有信息            *\n";
	cout << "\t\t\t*          6 统计员工信息            *\n";
	cout << "\t\t\t*          7 排序员工信息            *\n";
	cout << "\t\t\t**************************************\n";
	cout << "\n\n\t\t请输入您的选择：";
}

void Control::zhuce(node *head)
{
	
	node *p = new node;
	p->next = NULL; 
	system("cls");//清屏
	cout << "\n\n\n";
	cout << "\t\t\t请输入职工号：";
	cin >> p->num;
	cout << "\n\t\t\t请输入名字：";
	cin >> p->name;
	
	cout << "\n\t\t\t请输入电话：";
	cin >> p->phone;
	cout << "\n\t\t\t请输入部门：";
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
				cout << "该人员信息已存在\n";
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
	cout << "\t\t\t请输入要修改人的职工号：";
	cin >> str1;

	node *temp = head->next;
	while (temp != head)
	{
		if (temp->num == str1)
		{
			flag = 1;
			cout << "\n\t\t\t请输入修改后的名字：";
			cin >> temp->name;
			cout << "\n\t\t\t请输入修改后的电话：";
			cin >> temp->phone;
			cout << "\n\t\t\t请输入修改后的部门：";
			cin >> temp->bum;
			
			break;
		}

		temp = temp->next;
	}
	if (flag)
	{
		//Sleep(2);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t修改成功！" << endl;
	}
	else
	{
		//Sleep(2);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t查无此人！" << endl;
	}
}

void Control::shanchu(node *head)
{
	system("cls");
	string str1;
	cout << "\n\n\n";
	cout << "\t\t\t请输入要修改人的职工号：";
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
		cout << "\n\n\n\n\n\n\t\t\t\t删除成功！" << endl;
	}
	else
	{
		//Sleep(2);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t查无此人！" << endl;
	}
}

void Control::chaxun(node *head)
{
	system("cls");
	string str1, str2;
	cout << "\n\n\n";
	cout << "\t\t\t请输入要查询的职工号：";
	cin >> str1;
	cout << "\n\n\t\t\t请输入要查询的名字：";
	cin >> str2;

	int flag = 0;
	node *temp = head->next;
	while (temp != head)
	{
		if (temp->num == str1 && temp->name == str2)
		{
			flag = 1;
			cout << "\n\n" << " 电话：" << temp->phone << " 部门："
				<< temp->bum << endl;
			break;
		}
		temp = temp->next;
	}

	if (flag == 0)
	{
		//Sleep(2);
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t查无此人！" << endl;
	}
}



void Control::pint(node *head)
{
	node *temp = head->next;
	system("cls");//清屏处理
	cout << "\n\n\n";
	int flag = 0;
	while (temp != head)
	{
		flag = 1;
		cout << "职工号：" << temp->num << " 名字：" << temp->name << " 电话：" << temp->phone << " 部门：" << temp->bum << endl;
		temp = temp->next;
	}
	if (flag == 0)
	{
		//Sleep(2);
		system("cls");//清屏处理
		cout << "\n\n\n\n\n\n\t\t\t\t系统中暂时无人！" << endl;
	}
}
void Control::tongji(node *head) {
	system("cls");//清屏处理
	cout << "\n\n\n";
	int flag = 0;
	if (head->next == NULL) {
		cout << "链表为空链表" << endl;
		return;
	}
	node*p = head->next;//令指针指向头结点
	int i=0;
	while (1) {
		i++;
		p = p->next;
		if(!p)
			break;
	}
	cout << "共有" << i << "人\n";
	

}
void Control::paixv(node *head) {
	system("cls");//清屏处理
}


			//定义头结点为全局变量
node* head = NULL;
int main()
{
	Control con;

	head = new node;
	head->next = NULL;
	
	char ecf;   //选项
	char sel[100];

	while (1)
	{
		con.jiemian();
		cin >> ecf;

		switch (ecf)
		{
		case '1':				//注册新职工
		{
			con.zhuce(head);
			break;
		}
		case '2':				//修改职工信息
		{
			con.xiugai(head);
			cout << "\n\n\t\t输入任意键返回：";
			cin >> sel;
			break;
		}
		case '3':				//删除职工信息
		{
			con.shanchu(head);
			cout << "\n\n\t\t输入任意键返回：";
			cin >> sel;
			break;
		}
		case '4':				//查询职工信息
		{
			con.chaxun(head);
			cout << "\n\n\t\t输入任意键返回：";
			cin >> sel;
			break;
		}
		case '5':				//浏览所有信息
		{
			con.pint(head);
			cout << "\n\n\t\t输入任意键返回：";
			cin >> sel;
			break;
		}
		case'6'://查询员工数量
		{
			con.tongji(head);
			cout << "\n\n\t\t输入任意键返回：";
			cin >> sel;
			break;
		}
		default:
		{
			system("cls");//清屏处理
			cout << "\n\n\n\n\n请输入1--7！" << endl;
			cout << "\n\n\t\t输入任意键返回：";
			cin >> sel;
			break;
		}
		}
	}

	return 0;
}
