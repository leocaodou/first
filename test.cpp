#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
struct Node{
public:
    int data;
    Node*next;
    friend ostream&operator<<(ostream&out, const Node&n);
};
ostream& operator<<(ostream&out, const Node&n) {
    out << n.data;
    return out;
}
class LinkedList{//构造空的链表类
public:
    Node*head;
    LinkedList():head(NULL){}
    void insertHead(int d) 
    {//向链表中插入元素
        Node *p;
        p = new Node;
        p->data = d;
        p->next = head;
        head = p;
    }
    void  remove(int a) {//删除每一个节点
        Node *i;
        for (i = head; i != NULL; i = i->next) {
            if (i->next) {
                if (i->next->data == a) {
                    Node*p = i->next;
                    i->next = p->next;
                    delete p;
                }
            }
        }
    }
    Node* find(int d) {//寻找第一个数据为data的节点
        Node*i;
        for (i = head; i != NULL; i = i->next) {
            if (i->data == d) {
                return i;
            }
            else {
                cout << "您所访问的数据不存在！";
                return NULL;
            }
        }
    }
    void travalLsit(){ //遍历，访问链表中的所有节点
        Node*i;
        for (i=head; i!=NULL; i=i->next) 
        {
            cout << *i << ' ';
        }
        cout << endl; 
    } 
    bool  isEmpty() {//判断链表是否为空
        if (head == NULL) {
            cout << "EMPTY!" << endl;
            return true;
        }
        else {
            cout << "NOT EMPYT!" << endl;
            return false;
        }
    }

};
int main(void)
{
    int i = 0;
    LinkedList b;
    for (i = 0; i < 10; i++)
    {
        b.insertHead(i);
    }
    b.isEmpty();
    b.travalLsit();
    b.find(100);
    for (i; i < 10; i++) {
        b.remove(i);
    }
}
