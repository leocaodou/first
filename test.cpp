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
	cout << "��¼����Ϣ��" << endl;
	cout << "�û�����";
	cin >> s->C_name;
	cout << "�����ĵ�ӰƬ���ͣ�";
	cin >> s->M_name;
	cout << "������";
	cin >> s->M_time;
	if (s->M_name == "��ͨƬ") {
		s->i += 1;
		if (s->M_time <= 2) {
			s->cost = 2;
		}
		else s->cost = (s->M_time - 2)*1.5 + 2;
	}
	else if (s->M_name == "��ͯƬ") {
		s->i += 1;
		if (s->M_time <= 3) {
			s->cost = 1.5;
		}
		else s->cost = (s->M_time - 3)*1.5 + 1.5;
	}
	else if (s->M_name == "��Ƭ") {
		if (s->M_time > 2)
			s->i += 2;
		else s->i += 1;
		s->cost = s->M_time * 3;
	}
	cout << "������Ҫ���ķ��ã�";
	cout << s->cost << endl;
	cout << "��ǰ�û����ֵ�Ϊ��";
	cout << s->i;
	cout << endl << "====================================��Ϣ¼��ɹ�===============================" << endl;
	
}
Customer* cheak_num(string str, Customer *head)//����˺��Ƿ����
{
	Customer *p = head;//pΪͷָ��
	if (head == NULL)//���ͷָ��Ϊ��
		return NULL;
	else//���ͷָ�벻Ϊ��
	{
		while (p != NULL)//�������˺Ž��б�����p����һλ��Ϊ��
		{
			if (p->C_name != str)//p��������ֵ�����û�
				p = p->next;//p=p����һλ
			else//�������p�����������û�
			{
				return p;
			}
		}
	}
	return p;
}
Customer * get_information(Customer *head)//����Ա¼����Ϣ
{
	Customer * p;
	ioinformation(head);
	while (1)//������1ʱѭ��
	{
		char ch;//�����ַ�
		cout << "�Ƿ����¼����Ϣ   �ǣ�1������2����" << endl;
		cin >> ch;//��������
		while (ch != '1' && ch != '2') {//��ѡ��Ȳ���1Ҳ����2ʱ
			cout << "�����������Ƿ����¼�� �ǣ�1��  ��2��";
			cin >> ch;
		}
		if (ch == '1') {//ѡ����
			Customer*p;
			string s;
			cout << "��¼����Ϣ��" << endl;
			cout << "�û�����";
			cin >> s;
			p = cheak_num(s, head);
			if (p ==NULL)
			{
				cout << "�����û�û�����޹�Ӱ��\n";
				p = new Customer();
				p->next = head;
				head = p;
				p->C_name = s;
			}
			else cout << "�����û����޹�Ӱ��";
			cout << "�����ĵ�ӰƬ���ͣ�";
			cin >> p->M_name;
			cout << "������";
			cin >> p->M_time;
			if (p->M_name == "��ͨƬ") {
				p->i += 1;
				if (p->M_time <= 2) {
					p->cost = 2;
				}
				else p->cost = (p->M_time - 2)*1.5 + 2;
			}
			else if (p->M_name == "��ͯƬ") {
				p->i += 1;
				if (p->M_time <= 3) {
					p->cost = 1.5;
				}
				else p->cost = (p->M_time - 3)*1.5 + 1.5;
			}
			else if (p->M_name == "��Ƭ") {
				if (p->M_time > 2)
					p->i += 2;
				else p->i += 1;
				p->cost = p->M_time * 3;
			}
			cout << "������Ҫ���ķ��ã�";
			cout << p->cost << endl;
			cout << "��ǰ�û����ֵ�Ϊ��";
			cout << p->i;
			cout << endl << "====================================��Ϣ¼��ɹ�===============================" << endl;
		}
		else//ѡ�񡰷�
		{
			break;//����ѭ��
		}
	}
	return head;
}
int main() {
	Customer *head = NULL;
	get_information(head);
}
