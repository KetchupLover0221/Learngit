
#include <iostream>
#include"Point.h"
using namespace std;
struct  PointList
{
    Point p;
    PointList* next;
};
void insertHead(PointList*& head)
{
    int* a = new int[5];
    int* b = new int[5];
    PointList* q;
    q = (PointList*)malloc(sizeof(PointList));
    q->next = nullptr;
    cout << "输入横坐标:"<< endl;
    cin >>*a;
    cout << "输入纵坐标:" << endl;
    cin >> *b;
    head->p= Point(*a, *b);
    if (head->next == NULL)//原先为空链表
        head->next = q;
    else
    {
        q->next = head->next;
        head->next = q;
    }
}//插入
void displayList(PointList*& head)
{
    PointList* q = head;
    while (q != NULL&&q->next !=NULL)
    {
        q->p.Show();
        q = q->next;
    }
}//显示
int main()
{
    PointList* head;
    head = (PointList*)malloc(sizeof(PointList));
    head->next = NULL;
    insertHead(head);
    displayList(head);
}

