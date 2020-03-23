#include<string>
#include<stdlib.h>
#include<iostream>
#include<ctime>
using namespace std;
class Customer {
public:
	string C_name;
	string M_name;
	double cost;
	double M_time;
	int i = 0;
	int t;
	Customer *next = NULL;
};
void ioinformation(Customer *&s) {
	s = new Customer;
	cout << "请录入信息：" << endl;
	cout << "用户名：";
	cin >> s->C_name;
	cout << "所借阅的影片类型：";
	cin >> s->M_name;
	cout << "天数：";
	cin >> s->M_time;
	if (s->M_name == "普通片") {
		s->i += 1;
		if (s->M_time <= 2) {
			s->cost = 2;
		}
		else s->cost = (s->M_time - 2)*1.5 + 2;
	}
	else if (s->M_name == "儿童片") {
		s->i += 1;
		if (s->M_time <= 3) {
			s->cost = 1.5;
		}
		else s->cost = (s->M_time - 3)*1.5 + 1.5;
	}
	else if (s->M_name == "新片") {
		if (s->M_time > 2)
			s->i += 2;
		else s->i += 1;
		s->cost = s->M_time * 3;
	}
	cout << "您所需要交的费用：";
	cout << s->cost << endl;
	cout << "当前用户积分点为：";
	cout << s->i;
	cout << endl << "====================================信息录入成功===============================" << endl;
	
}
Customer* cheak_num(string str, Customer *head)//检查账号是否存在
{
	Customer *p = head;//p为头指针
	if (head == NULL)//如果头指针为空
		return NULL;
	else//如果头指针不为空
	{
		while (p != NULL)//对已有账号进行遍历，p的下一位不为空
		{
			if (p->C_name != str)//p的数据域值不是用户
				p = p->next;//p=p的下一位
			else//否则如果p的数据域是用户
			{
				return p;
			}
		}
	}
	return p;
}
Customer * get_information(Customer *head)//管理员录入信息
{
	Customer * p;
	ioinformation(head);
	while (1)//条件是1时循环
	{
		char ch;//定义字符
		cout << "是否继续录入信息   是（1），（2）否" << endl;
		cin >> ch;//重新输入
		while (ch != '1' && ch != '2') {//当选项既不是1也不是2时
			cout << "请重新输入是否继续录入 是（1）  否（2）";
			cin >> ch;
		}
		if (ch == '1') {//选择是
			Customer*p;
			string s;
			cout << "请录入信息：" << endl;
			cout << "用户名：";
			cin >> s;
			p = cheak_num(s, head);
			if (p ==NULL)
			{
				cout << "这名用户没有租赁过影碟\n";
				p = new Customer();
				p->next = head;
				head = p;
				p->C_name = s;
			}
			else cout << "这名用户租赁过影碟";
			cout << "所借阅的影片类型：";
			cin >> p->M_name;
			cout << "天数：";
			cin >> p->M_time;
			if (p->M_name == "普通片") {
				p->i += 1;
				if (p->M_time <= 2) {
					p->cost = 2;
				}
				else p->cost = (p->M_time - 2)*1.5 + 2;
			}
			else if (p->M_name == "儿童片") {
				p->i += 1;
				if (p->M_time <= 3) {
					p->cost = 1.5;
				}
				else p->cost = (p->M_time - 3)*1.5 + 1.5;
			}
			else if (p->M_name == "新片") {
				if (p->M_time > 2)
					p->i += 2;
				else p->i += 1;
				p->cost = p->M_time * 3;
			}
			cout << "您所需要交的费用：";
			cout << p->cost << endl;
			cout << "当前用户积分点为：";
			cout << p->i;
			cout << endl << "====================================信息录入成功===============================" << endl;
		}
		else//选择“否”
		{
			break;//跳出循环
		}
	}
	return head;
}
int main() {
	Customer *head = NULL;
	get_information(head);
}
