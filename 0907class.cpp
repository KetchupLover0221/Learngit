#include <iostream>
using namespace std;
int main()
{
    //cout << "Hello World!\n";

    /* new 会返回指针 需要左侧保存地址   p指针变量   所有指针变量4个字节*/
  //int* p = new int(20);   申请一个单元 赋值20    delete p;
    // int*p1 = new int[20];  申请20个变量               delete []p; 释放整片
    //int *p=new int ;  申请一个单元 随机赋值

//引用 变量 或 常量 指针
   // int k = 0;
    //int& namek1 = k, & namek2 = k;  namek1,namek2 都是k的别名 间接访问
    //namek1 = 20;
    //namek2 = 30;  k=30
    //k 4个字节 namek1 ，namek2   不占内存

    //引用传递
  //  int k1 = 10,k2 = 20;
 //   int* pk1 = &k1, * pk2 = &k2;//pk1 指向k1 pk2 指向k2
   // swap1(pk1,pk2)
    //void swap1(int *&N1,int *  &N2)//N1的别名的地址，与N1的地址相同
    //{
       // int *temp=N1;
      //  N1=N2;
      //  N2=temp;
    //}


    /*函数重载
    定义名字一致，形参不一致的函数
    */


    /*
    函数模板
    template <typename T>//数据类型形参表     T add(T n1, T n2)  //n1 n2 数据类型不确定
    {
     T temp;
     temp = n1+ n2;
     return temp;
    }
    int main ()
    {
        int temp1= add(1,2);  // int 类型的add  T由模板转化为int    由模板产生的函数叫模板函数
        double temp2 = add(10.0, 20.0);  //T 转化为double
    }
    */


    /*
    内联函数 inline 没有进栈出栈
    
    */

    /*
    类 数据类型
    包含 数据成员
    成员函数
    */

    /*
    友元函数     友元类
    函数与类   类与类
    */

    /*
    类的继承
    */

    /*
    链表 容器    
    数组： 地址依次存放
    链表：节点离散保存 每个节点都有下一个节点的地址，
    //第一个节点有头，最后一个节点保存地址0
    空链表  student *head1= NULL;
    student s1={ , }, s2={ , } s3={ , };
    head = &s1;
    s1->pnext= &s2;  或 head -> pnext = &s2;   前一个结点保存后续结点的指针
    s2->pnext= &s3;
    s3-> pnext= NULL;

    链表操作
    插入，修改，删除，查找， 计算
    */
  //  int k = 0;
    //int t = (1, 9, k + 2, 8);
    //cout << t;  //t=8


    //int* p2[3];// 指针数组   存放指针的数组

    //int(*p3)[3], (*p7)[5];// 数组指针   行指针 p3：3个元素，p7：5个元素   
    //指针+1  p7+1  p7多5个元素 20个字节      p3+1 多3个元素  12个字节
    
    //int(*p4)(int);
    //int(*p8)(double);
    //函数指针


//将二维数组赋给一指针：int a[3][4];
 //int(*p)[4]; //该语句是定义一个数组指针，指向含4个元素的一维数组。
  //p++;       //该语句执行过后，也就是p=p+1;p跨过行a[0][]指向了行a[1][]


//定义 int* p[n];
//[] 优先级高，先与p结合成为一个数组，再由int* 说明这是一个整型指针数组
//它有n个指针类型的数组元素。
//int* p[3];
//int a[3][4];
//p++; //该语句表示p数组指向下一个数组元素。
//注：此数组每一个元素都是一个指针

//数组指针只是一个指针变量，占有内存中一个指针的存储空间。
//指针数组是多个指针变量，以数组形式存在内存当中，
//占有多个指针的存储空间。


/*int main()
{
    char a[5] = { 'A','B','C','D' };
    char(*p3)[5] = &a;
    char(*p4)[5] = a;
    return 0;
}*/
//p3 和p4 都是数组指针，指向的是整个数组。
//&a 是整个数组的首地址，a是数组首元素的首地址
//p3 这个定义的“=”号两边的数据类型完全一致，
//p4左边的类型是指向整个数组的指针，右边的数据类型是指向单个字符的指针



//int main() {
  //  char* ptr_1 = "this is a C string";
  //  printf("%s\n", ptr_1);
   // return 0;
//}
//这样也可以间接的表现为指针指向了字符串
//135行本质是将这个字符串的首地址存放到了指针内
//此时指针的指向不再是单个字符，而是字符串

//int a[3][3];
//void print(int a[3][3]);  //OK    等同于void print(int(*a)[3]);
//void print(int a[4][3]);  //OK    等同于void print(int(*a)[3]);
//void print(int a[][3]);   //OK    等同于void print(int(*a)[3]);
}

