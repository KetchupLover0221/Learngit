#include <iostream>
#include"Point2.h"
using namespace std;
struct  PointList
{
    Point2 p;
    PointList* next;
};
void insertHead(PointList*& head,Point2 newp)
{
    PointList* q;
   q = (PointList*)malloc(sizeof(PointList));
    //PointList *q = new PointList;
    q->p = newp;
    if (head->next == NULL)//原先为空链表
    {
        head->next = q;
        q->next = NULL;
    }
    else
    {
        q->next = head->next;
        head->next = q;
    }
}//链首插入

void displayList(PointList*& head)
{
    PointList* q = head->next;
    while (q != NULL)
    {
        q->p.Show();
        q = q->next;
    }
}//显示

void deleteHead(PointList*& head)
{
    if (head != NULL)
    {
        head = head->next;
    }
}//链首删除

void findpoint(PointList*& head, int x)
{
    int judge = 0;
    PointList* q = head->next;
    while (q!= NULL)
    {
        if (q->p.CompX() == x)
        {
            cout << "目标点为：" << endl;
            q->p.Show();
            cout << "目标点指针为：" << endl;
            q->p.Showadd();
            judge = 1;
        }
        q = q->next;
    }
    if (judge == 0)
    {
        cout << "未找到目标点: x = "<< x << endl;
    }
}//找指定点

Point2 p1(1, 1);
int main()
{
    Point2 p2(2, 2);
    Point2 arrayp[3] = { Point2(3,3), Point2(4,4),Point2(5,5) };
    Point2* p = new Point2(6, 6);

    PointList* head = NULL;//空链
    head = (PointList*)malloc(sizeof(PointList));
    head->next = NULL;
    insertHead(head, p1);//插入全局量
    insertHead(head, p2);//插入局部量
    for (int i = 0; i < 3; i++)
    {
        insertHead(head, arrayp[i]);//插入数组
    }
    insertHead(head, *p);//插入指针

    displayList(head);

    deleteHead(head);
    cout << "删除头元素" << endl;
    displayList(head);

    findpoint(head, 6);
    findpoint(head, 2);
}

