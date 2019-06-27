#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
class QWQ//��������ʱ�������ݺ�����
{
public:
	string name;
	int c;
};
bool cmp(QWQ a,QWQ b)//������ı�׼
{
	if(a.c < b.c)
		return true;
	else
		return false;
}
class date
{
public:
	int month;//��
	int day;//��
	int level;//ȱ�εȼ�
	string ke;//��ȱ�γ�����
	int jie;//��
	date():month(0),day(0),level(0),ke("NULL"),jie(0){}
	date(int m,int d,int l,const string& k,int j) : month(m),day(d),level(l),ke(k),jie(j){}//��5�������Ĺ��캯��������¼����Ϣ
	date(int m,int d,int j) : month(m),day(d),jie(j){}//ֻ�����ս����������Ĺ��캯����������Ϣ�Ĳ���
	bool operator>= (const date& d)//���������>=�����أ��������ڵıȽϣ�����ֻ��Ҫ�����Ƚ����սھ�����
	{
		if(month > d.month)
			return true;
		if(month == d.month)
		{
			if(day > d.day)
				return true;
			if(day == d.day)
			{
				if(jie >= d.jie)
					return true;
				else
					return false;
			}
			return false;
		}
		return false;
	}
	bool operator<= (const date& d)//���ڲ�����<=�����أ���>=����
	{
		if(month < d.month)
			return true;
		if(month == d.month)
		{
			if(day < d.day)
				return true;
			if(day == d.day)
			{
				if(jie <= d.jie)
					return true;
				else
					return false;
			}
			return false;
		}
		return false;
	}
	bool operator== (const date& d)//���ڲ�����==�����أ��ж������Ƿ����
	{
		if(month == d.month && day == d.day && jie == d.jie)
			return true;
		else
			return false;
	}
};
template <typename T>//����
class node
{
public:
	T data;//��������
	node* next;
	friend ostream& operator << (ostream& ,const node<date>& );//ר�����ʱ��������͵�����
};
ostream& operator << (ostream& out ,const node<date>& n)//ר�����ʱ��������͵�����ľ���ʵ��
{
	out << n.data.month << "��" << n.data.day << "�յ�" << n.data.jie << "�ڵ�" << n.data.ke << "��";
	switch(n.data.level)//�ǵü��ϵȼ�
	{
		case 1 :
		{
			cout << "�ٵ���";
			break; 
		}
		case 2 :
		{
			cout << "������";
			break;
		}
		case 3 :
		{
			cout << "�����";
			break;
		}
		case 4 :
		{
			cout << "������";
			break;
		} 
	}
	return out;
}
template <typename T>//������
class dateLink
{
public:
	node<T>* head;
	dateLink() : head(NULL){}
	void insertHead(T a)//����Ԫ��
	{
		node<T>* p;
		p = new node<T>;
		p->data = a;
		p->next = head;
		head = p;
	}
	void remove(T d)//����Ԫ�ص�ɾ��
	{
		for(node<T>* i = head;i != NULL;)
		{
			if(head->data == d)
			{
				node<T>* p = i;
				head = p->next;
				i = p->next;
				delete p;
				return;
			}
			else if(i->next)
			{
				if(i->next->data == d)
				{
					node<T>* p = i->next;
					i->next = p->next;
					i = i->next;
					delete p;
					return;
				}
				else
					i = i->next;
			}
			else
				i = i->next;
		}
	}
	node<T>* find(T d)//��������ĳһ��Ԫ��
	{
		node<T>* i;
		for(i = head;i != NULL;i = i->next)
		{
			if(i->data == d)
			{
				return i;
			}
		}
		return NULL;
	}
	void travalList()//��������
	{
		if(head)
		{
			for(node<T>* i = head;i != NULL;i = i->next)
			{
				cout << *i << endl;
			}
		}
		else
			cout << "��λͬѧû��ȱ����"; //����Ϊ��
			cout << endl;
	}
	void deleteList()//ɾ�����������ͷſռ�
	{
		for(node<T>* i = head;i != NULL;)
		{
			node<T>* p = i;
			i = i->next;
			delete p;
			if(i == NULL)
				break;
		}
		head = NULL;

	}
	bool isEmpty()
	{
		if(head == NULL)
			return true;
		else
			return false;
	}
};
class student//ѧ����
{
public:
	string n;//����ѧ������
	dateLink<date> que;//����ͬѧ��ȱ����Ϣ
	student() : n("NULL"){}
	student(const string& _n) : n(_n){}
	void getdate(date d)//¼��ѧ����ȱ����Ϣ
	{
		que.insertHead(d);
	}
	void chaxunall()//��ѯѧ��������ȱ�����
	{
		que.travalList();
	}
	void deletedateall()//ɾ�����е�ȱ����Ϣ
	{
		que.deleteList();
	}
	void deletedate(date d)//ɾ������ĳһ��ʱ�������
	{
		que.remove(d);
	}
	int ci(date a,date b)//ͳ����ĳ��ʱ���ڵ�ȱ�δ���
	{
		int s = 0;
		for(node<date>* i = que.head;i != NULL;i = i->next)
		{
			if(i->data >= a && i->data <= b && i->data.level == 4)
				s++;
		}
		return s;
	}
	bool operator==(const student& x)//����==�����أ������ж�����ѧ���Ƿ���ͬ
	{
		if(n == x.n)
			return true;
		else
			return false;
	}
};
class ke//�γ̵���
{
public:
	string n;
	dateLink<date> da;//����ȱϯ���ſγ̵�ʱ��
	ke() : n("NULL"){}//
	ke(const string& _n) : n(_n){}
	//����ĺ���������student���ͬС��
	void getdate(date d)
	{
		da.insertHead(d);
	}
	void deletedateall()
	{
		da.deleteList();
	}
	int ci(date a,date b)
	{
		int s = 0;
		for(node<date>* i = da.head;i != NULL;i = i->next)
		{
			if(i->data >= a && i->data <= b && i->data.level == 4)
				s++;
		}
		return s;
	}
	bool operator==(const ke& x)
	{
		if(n == x.n)
			return true;
		else
			return false;
	}
};
int main()
{
	int st = 0,kc = 0;
	dateLink<student> stu;//����student���������ڴ���ѧ����Ϣ
	dateLink<ke> k;//�����γ̵��������ڴ���γ�
	while(1)
	{
		cout << "_________________________________________________________________________________" << endl;
		cout << "****************��������Ҫ��ʲô��****************\n��1��¼��ѧ����ȱ�μ�¼����1��\n��2���޸�ĳ��ѧ����ȱ�μ�¼����2��\n��3����ѯĳ��ѧ����ȱ�μ�¼����3��\n��4��ɾ��ĳ��ѧ����ȱ�μ�¼����4��\n��5��ͳ��ĳ��ʱ���ڣ�ĳ�ſο���ѧ�����������δ����������δ������ٵ������򣨰�5��\n��6��ͳ��ĳ��ʱ���ڣ���ѧ�����εĿγ̼����δ������������˴����ٵ������򣨰�6��\n��7���˳����򣨰�7��\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;//����Ŀ¼�����
		cout << "ʹ�ù��ܣ�";
		int n;
		fflush(stdin);//�������������ֹ��ѭ��
		scanf("%d",&n);
		//����ѡ��
		if(n == 7)
		{
			cout << "��л����ʹ�ã���ӭ�ٴ�ʹ��" <<  endl;
			break;
		}
		switch(n)
		{
			case 1 : //¼��ѧ��ȱ�μ�¼
			{
				string name,kec;
				cout << "������ѧ��������" << endl;
				cin >> name;
				cout << "������γ����ڣ��Լ��ڼ��ڿΣ�����1��1�յ�2�ڿ����� 1 1 2��" << endl;
				int n,y,j;
				cin >> n >> y >>j;
				cout << "������γ�����" << endl;
				cin >> kec;
				node<ke> *q;
				q = k.find(ke(kec));//�Ȳ����ڿγ��������Ƿ��Ѿ��иÿγ�
				if(!q)//���û�иÿγ�
				{
					ke p(kec);//����һ������Ŀγ�
					kc++;//�γ���Ŀ��һ
					k.insertHead(p);//����γ���ӵ��γ�������
					q = k.find(p);//������qָ��γ�����ĸÿγ�
				}
				cout << "������ȱ������   �ٵ���1�����ˣ�2����٣�3�����Σ�4��" << endl;
				int o;
				cin >> o;
				date D(n,y,o,kec,j);//����һ���ÿγ���Ϣ
				q->data.da.insertHead(D);//�����������ӵ��γ̵���
				node<student> *w;
				w = stu.find(student(name));//�Ȳ�����ѧ���������Ƿ��Ѿ�����һλͬѧ
				if(!w)//û�еĻ�
				{
					student p(name);//����һ����ѧ��
					stu.insertHead(p);//��ѧ����������Ӹ�ѧ��
					st++;//ѧ����Ŀ��һ
					w = stu.find(p);//��ָ��ָ���ѧ��
				}
				w->data.que.insertHead(D);//��ѧ����Ϣ��������ȱ����Ϣ
				cout << "��¼�ɹ���" << endl;
				break;

			}
			case 2://�޸�ĳͬѧ����Ϣ
			{
				string name;
				cout << "����������Ҫ�޸ĵ�ͬѧ������" << endl;
				cin >> name;
				node<student> *p;
				p = stu.find(student(name));//��ָ��ָ���ѧ��
				if(!p)//��ָ��Ϊ��
				{
					cout << "��λͬѧû��ȱ����" << endl;
					break;
				}
				cout << "����������Ҫ�޸ĵ����ں͵ڼ��ڿΣ�����1��1�յ�2�ڿ����� 1 1 2��" << endl;
				int m,d,j;
				cin >> m >> d >> j;//�޸ĵ�ĳһ��
				date D(m,d,j);
				node<date> *q;
				q = p->data.que.find(D);//ָ���ѧ������һ����Ϣ
				if(!q)//��ָ��Ϊ��
				{
					cout << "���ʱ����λͬѧû��ȱ��" << endl;
					break;
				}
				cout << "�������ǣ�1��׼����ʱ�䣨2���޸Ŀγ̣�3���޸�ȱ�θ�����" << endl;
				int n;
				fflush(stdin);//�������������ֹ��ѭ��
				scanf("%d",&n);
				switch(n)//����޸�
				{
					case 1 :
					{
						cout << "������Ҫ�޸ĵ�ʱ��" << endl;
						node<ke> *w;
						w = k.find(ke(q->data.ke));//�ҵ��γ̣���Ϊ���޸�ѧ����Ϣ��ͬʱ���γ������ϢҲ�����޸�
						int _m,_d,_j;
						cin >> _m >> _d >> _j;//������Ҫ�޸ĵļ��¼��յڼ���
						q->data.month = _m;
						q->data.day = _d;
						q->data.jie = _j;
						node<date> *r;
						r = w->data.da.find(D);//�ҵ���Ӧ�γ̵���Ҫ�޸�����
						r->data.month = _m;
						r->data.day = _d;
						r->data.jie = _j;
						break;
					}
					case 2:
					{
						cout << "������Ҫ�޸ĵĿγ�" << endl;
						string kk;
						cin >> kk;
						node<ke> *w;
						w = k.find(ke(q->data.ke));//����Ҳ��Ҫ����ؿγ̽����޸�
						w->data.da.remove(D);
						q->data.ke = kk;//��������Ϣ�޸�
						D = q->data;
						w = k.find(ke(kk));//�鿴�޸ĺ�Ŀγ��Ƿ����
						if(w)
							w->data.da.insertHead(D);//���ڵĻ�ֱ�Ӽ���
						else
						{
							ke o(kk);
							kc++;
							k.insertHead(o);
							w = k.find(ke(kk));
							w->data.da.insertHead(D);
						}
						break;
					}
					case 3 :
					{
						cout << "������Ҫ�޸�ȱ������" << endl;
						node<ke> *w;
						w = k.find(ke(q->data.ke));//�ѵ��տγ��ҵ�
						int l;
						cin >> l;
						q->data.level = l;//�޸�
						node<date> *r;
						r = w->data.da.find(D);//ͬ���޸Ŀγ���������
						r->data.level = l;
						break;
					}
					default ://�������ƥ��
					{
						cout << "�������" << endl;
						break;
					}
				}
				cout << "�޸ĳɹ���"<<endl;
				break; 
			}
			case 3 :
			{
				cout << "����������Ҫ�鿴��ͬѧ������" << endl;
				string n;
				cin >> n;
				node<student> *p;
				p = stu.find(student(n));//�ҵ���λͬѧ
				if(!p)//��ָ��Ϊ��
				{
					cout << "���ʱ����λͬѧû��ȱ��";
					break;
				}
				p->data.que.travalList();
				break;
			}
			case 4 :
			{
				cout << "����������Ҫɾ��ȱ�μ�¼ͬѧ������" << endl;
				string n;
				cin >> n;
				node<student> *p;
				p = stu.find(student(n));
				if(!p)
				{
					cout << "���ʱ����λͬѧû��ȱ��" << endl;
					break;
				}
				cout << "�������루1��ɾ�����еļ�¼���ǣ�2������ĳ��ʱ��ļ�¼" << endl;
				int f;
				fflush(stdin);//�������������ֹ��ѭ��
				scanf("%d",&f);
				switch(f)
				{
					case 1 :
					{
						p->data.deletedateall();
						break;
					}
					case 2 :
					{
						cout << "������Ҫɾ����¼��ʱ��" << endl;
						int m,d,j;
						cin >> m >> d >> j;
						date D(m,d,j);
						p->data.deletedate(D);//����ɾ��ʱ��ĺ���
						break;
					}
					default :
					{
						cout << "�������" << endl;
					}
				}
				break;
			}
			case 5 :
			{
				int m,d,j;
				cout << "��������Ҫ��ѯ������ʱ���\n" << "�Ӷ�ÿ�ʼ���� �� �ڣ�" << endl;
				cin >> m >> d >> j;
				date A(m,d,j);
				cout << "����ý������� �� �ڣ�"<< endl;
				cin >> m >> d >> j;
				date B(m,d,j);
				QWQ f[st];//�����е�ѧ���������鵱�У���������
				node<student>* ji = stu.head;
				for(int i = 0;i < st;i++)//�洢����
				{
					f[i].name = ji->data.n;
					f[i].c = ji->data.ci(A,B);
					ji = ji->next;
				}
				sort(f,f + st,cmp);//����sort��������
				for(int i = 0;i < st;i++)//�������
				{
					cout << f[i].name <<"������ʱ����ȱ��" << f[i].c << "��" << endl;
				}
				break;
			}
			case 6:
			{
				int m,d,j;
				cout << "��������Ҫ��ѯ������ʱ���\n" << "�Ӷ�ÿ�ʼ���� �� �ڣ�" << endl;
				cin >> m >> d >> j;
				date A(m,d,j);
				cout << "����ý������� �� �ڣ�"<< endl;
				cin >> m >> d >> j;
				date B(m,d,j);
				QWQ f[kc];//�����еĿγ̼������ݷ�������
				node<ke>* ji = k.head;
				for(int i = 0;i < kc;i++)//��ʼ¼������
				{
					f[i].name = ji->data.n;
					f[i].c = ji->data.ci(A,B);
					ji = ji->next;
				}
				sort(f,f + kc,cmp);
				for(int i = 0;i < kc;i++)
				{
					cout << f[i].name <<"��������ʱ������" << f[i].c << "��ȱ��" << endl;
				}
				break;
			}
			default :
			{
				cout << "���������������" << endl;
			}
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	}
	stu.deleteList();
	k.deleteList();
	return 0;
}
