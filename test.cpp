#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
typedef struct  p{
    float hp = 100;
    float mp = 0;
    int Damage = 5+ rand()%8;
    int Armor = 20;
    int resistance = 10;
    char name[16];
    struct p *next;
}SMonster;

typedef struct q{
    float hp = 80;
    int Damage = 12 + rand()%10;
    int Armor = 0;
    int resistance = 0;
    char name[16];
    struct q *next;
}Sprite1;

typedef struct {
    int num;
    SMonster* next;
}SMonsterLinklist;

typedef struct{
    int num;
    Sprite1* next;
}Sprite1Linklist;

void AddNewSMonster(SMonsterLinklist* head, SMonster* newSMonster)
{
    newSMonster->next = head->next;
    head->next = newSMonster;
    head->num++;
}
void AddNewSprite1(Sprite1Linklist *head, Sprite1* newSprite1)
{
    newSprite1->next = head->next;
    head->next = newSprite1;
    head->num++;
}

void RemoveSMonster(SMonsterLinklist *head, SMonster *Monster)
{
    SMonster *p = head->next;
    if (p == Monster) {
        head->next = p->next;
        free(p);
        head->num--;
        return;
    }
    while (p->next != Monster && p->next != NULL)
        p = p->next;
    if (p->next == Monster)
    {
        SMonster* tmp = p->next->next;
        free(p->next);
        p->next = tmp;
        head->num--;
    }
}


void RemoveSprite1(Sprite1Linklist* head, Sprite1 *Sprite)
{
    Sprite1* p = head->next;
    if (p == Sprite) {
        head->next = p->next;
        free(p);
        head->num--;
        return;
    }
    while (p->next != Sprite && p->next != NULL)
        p = p->next;
    if (p->next == Sprite)
    {
        Sprite1* tmp = p->next->next;
        free(p->next);
        p->next = tmp;
        head->num--;
    }
}

SMonster* FindeByName(SMonsterLinklist* head, char* name)
{
    SMonster* p = head->next;
    while (p != NULL && strcmp(p->name, name) != 0)
        p = p->next;
    return p;
}
Sprite1* FindeByName1(Sprite1Linklist* head, char* name)
{
    Sprite1* p = head->next;
    while (p != NULL && strcmp(p->name, name) != 0)
        p = p->next;
    return p;
}

SMonster* SortByHP(SMonster* first)
{

    if (first == NULL || first->next == NULL)
        return first;
    SMonster * minPre = first;
    SMonster * p = first->next;


    while (p->next != NULL)
    {
        if (p->next->hp < minPre->next->hp)
            minPre = p;
        p = p->next;
    }if (minPre->next->hp < first->hp)
    {
        p = minPre->next = p->next;
        p->next = first;
        first = p;
    }
    first->next = SortByHP(first->next);
    return first;
}
Sprite1* SortByHP(Sprite1* first)
{

    if (first == NULL || first->next == NULL)
        return first;
    Sprite1* minPre = first;
    Sprite1* p = first->next;


    while (p->next != NULL)
    {
        if (p->next->hp < minPre->next->hp)
            minPre = p;
        p = p->next;
    }if (minPre->next->hp < first->hp)
    {
        p = minPre->next = p->next;
        p->next = first;
        first = p;
    }
    first->next = SortByHP(first->next);
    return first;
}


    void DamageSMonster(SMonsterLinklist * head)
    {
        SMonster* p = head->next;
        while (p != NULL)
        {
            p->hp = p->hp - 5 + rand() % 8;
            p = p->next;
        }
        SMonster* p1 = head->next;
        while (p1 != NULL && p1->hp <= 0)
        {
            p1 = p1->next;
            SMonster* p2 = head->next;
            head->next = p2->next;
            free(p2);
            head->num--;
        }
    }
    void DamageSprite1(Sprite1Linklist* head)
    {
        Sprite1* p = head->next;
        while (p != NULL)
        {
            p->hp = p->hp -12 + rand() % 10;
            p = p->next;
        }
        Sprite1* p1 = head->next;
        while (p1 != NULL && p1->hp <= 0)
        {
            p1 = p1->next;
            Sprite1* p2 = head->next;
            head->next = p2->next;
            free(p2);
            head->num--;
        }
    }

    int main()
    {
        srand(time(NULL));
        SMonsterLinklist* head = (SMonsterLinklist*)malloc(sizeof(SMonsterLinklist));
        head->next = NULL;
        head->num = 0;
        int nCand = rand() % 20;
        char* find = NULL;
        for (int i = 0; i < 10; i++)
        {
            SMonster* p = (SMonster*)malloc(sizeof(SMonster));
            p->name[0] = 'A' + rand() % 26;
            p->name[1] = 'A' + rand() % 26;
            p->name[2] = 'A' + rand() % 26;
            p->name[3] = '\0';

            if (nCand == i)
                find = p->name;
        }
        //Print(head);

        srand(time(NULL));
        Sprite1Linklist* head2 = (Sprite1Linklist*)malloc(sizeof(Sprite1Linklist));
        head2->next = NULL;
        head2->num = 0;
        int nCand2 = rand() % 20;
        char* find2 = NULL;
        for (int i = 0; i < 10; i++)
        {
            Sprite1* p = (Sprite1*)malloc(sizeof(Sprite1));
            p->name[0] = 'A' + rand() % 26;
            p->name[1] = 'A' + rand() % 26;
            p->name[2] = 'A' + rand() % 26;
            p->name[3] = '\0';

            if (nCand == i)
                find = p->name;
        }
        //Print(head);

        SMonster* p = FindeByName(head, find);
        printf("The SMonster found:%s,hp:%.2f\n", p->name, p->hp, p->mp);
        RemoveSMonster(head, p);
        printf("Remove it from the list\n");
        //Print(head);

        printf("Sort the list by hp\n");
        head->next = SortByHP(head->next);
        //Print(head);

        //Destroy(head);

        Sprite1 *q = FindeByName1(head2, find);
        printf("TheSprite found:%s,hp:%.2f\n", p->name, p->hp, p->mp);
        RemoveSMonster(head, p);
        printf("Remove it from the list\n");
        //Print(head);

        printf("Sort the list by hp\n");
        head->next = SortByHP(head->next);
        //Print(head);
        //Destroy(head);
    }
    void Print(SMonsterLinklist * head)
    {
        SMonster* p = head->next;
        while (p != NULL)
        {
            printf("%s,%.2f,%.2f\t", p->name, p->hp, p->mp);
            p = p->next;
        }
        printf("\n");
    }
    void Destroy(SMonsterLinklist* head)
    {
        SMonster* p = head->next;
        SMonster* q = p->next;
        while (q != NULL)
        {
            q = p->next;
            free(p);
            p = q;
        }
        free(head);
    }
        void Print(Sprite1Linklist * head)
        {
            Sprite1* p = head->next;
            while (p != NULL)
            {
                printf("%s,%.2f", p->name, p->hp);
                p = p->next;
            }
            printf("\n");
        }                                                     
        void Destroy(Sprite1Linklist * head)
        {
            Sprite1* p = head->next;
            Sprite1* q = p->next;
            while (q != NULL)
            {
                q = p->next;
                free(p);
                p = q;
            }
            free(head);
    }
