#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct node{
    long long key;
    struct node* next;
}KeyNode;
void bucket_sort(int keys[],int size,int bucket_size);
int main()
{
	int n , i;
	cin >> n;
	long long a[n];
	for(i = 0; i < n;i++ )
		cin >> a[i];
    int size=sizeof(a)/sizeof(a[0]);
    bucket_sort(a,size,10);
    return 0;
}
void bucket_sort(long long keys[],int size,int bucket_size)
{
    KeyNode **bucket_table=(KeyNode**)malloc(bucket_size*sizeof(KeyNode*));
    for(int i=0;i<bucket_size;i++){    //初始化桶 
        bucket_table[i]=(KeyNode*)malloc(sizeof(KeyNode));
        bucket_table[i]->key=0;
        bucket_table[i]->next=NULL;
    }
    for(int i=0;i<size;i++){
        KeyNode* node=(KeyNode*)malloc(sizeof(KeyNode));
        node->key=keys[i];
        node->next=NULL;
        int index=keys[i]/10;//给数据分类的方法（关系到排序速度，很重要）
        KeyNode *p=bucket_table[index];
        if(p->key==0){
            p->next=node;
            p->key++;
        }            
        else{
            while(p->next!=NULL&&p->next->key<=node->key){//=的时候后来的元素会排在后面 
                p=p->next;
            }
            node->next=p->next;
            p->next=node;
            (bucket_table[index]->key)++;
        }
    }
    KeyNode* k=NULL;
    for(int i=0;i<bucket_size;i++){
        for(k=bucket_table[i]->next;k!=NULL;k=k->next){
            printf("%d ",k->key);
        }    
    }
}