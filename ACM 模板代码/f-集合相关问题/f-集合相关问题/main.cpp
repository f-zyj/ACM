//
//  main.cpp
//  f-集合相关问题
//
//  Created by ZYJ on 16/6/26.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//const int MaxSize = 200;
//
////  集合类模板
//template<class T>
//class SeqList
//{
//public:
//    SeqList()                                   //  无参构造函数
//    {
//        length = 0;
//    }
//    
//    SeqList(T a, int n)                         //  带参构造函数
//    {
//        if (n > MaxSize)
//        {
//            throw "Error: The number of array elements is not valid in One!";   //  数组元素个数不合法
//        }
//        for (int i = 0; i < n; i++)
//        {
//            data[i] = a[i];
//        }
//        length = n;                             //  长度
//    }
//    
//    SeqList(const SeqList &A)                   //  A中元素的值不变
//    {
//        for(int i = 0; i < A.length; i++)
//        {
//            data[i] = A.data[i];
//        }
//        length = A.length;
//    }
//    
//    int Length()                                //  求长度
//    {
//        return length;
//    }
//    
//    char Get(int i)                                //  获取下标为i的元素
//    {
//        return data[i];
//    }
//    
//    int Locate(T item)                          //  查找相同的元素
//    {
//        for (int i = 0; i <= length; i++)
//        {
//            if (data[i] == item)
//            {
//                return i + 1;
//            }
//        }
//        return 0;
//    }
//    
//    void Insert(int i, char item)                  //  插入操作  在第i个位置插入一个元素item
//    {
//        int j;
//        if (length >= MaxSize)
//        {
//            throw "Error: Length is not lawful in Two!";   //  长度不合法
//        }
//        if (i < 1 || i > length + 1)
//        {
//            throw "Error: Place is not valid in Three!";   //  位置不合法
//        }
//        for (j = length; j >= i; j--)
//        {
//            data[j] = data[j - 1];
//        }
//        data[i - 1] = item;
//        length++;
//    }
//    
//    T Delete(int i)                             //  删除并返回删除值操作  删除第i个位置的元素
//    {
//        int item, j;
//        if (length == 0)
//        {
//            throw "Error: Table is empty, can not delete elements!";    //  表为空，无法删除元素
//        }
//        if (i < 1 || i > length)
//        {
//            throw "Error: Place is not valid in Three!";   //  元素位置不合法
//        }
//        item = data[i - 1];
//        for (j = i; j < length; j++)
//        {
//            data[j-1]=data[j];
//        }
//        length--;
//        return item;
//    }
//    
//    void display()                              //  输出操作
//    {
//        for (int i = 0; i < length; i++)
//        {
//            cout << data[i];
//        }
//    }
//    
//    bool empty()                                //  判断是否为空
//    {
//        if (length == 0)
//        {
//            return true;
//        }
//        return false;
//    }
//    
//    void clear()                                //  清理
//    {
//        length = 0;
//    }
//    
//private:
//    char data[MaxSize];    //  存储数据的数组
//    int length;         //  表的长度
//};
//
////  集合的并集集运算
//template<class T>
//SeqList<T> Union(SeqList<T> A, SeqList<T> B)
//{
//    SeqList<T> C;
//    int m = 1;
//    int a = A.Length();
//    for (int b = 0; b <= B.Length(); b++)
//    {
//        A.Insert(a + b + 1, B.Get(b));          //  将B的元素插入到A的后面
//    }
//    
//    for (char i = 'a'; i <= 'z'; i++)
//    {
//        for (int d = 0; d <= A.Length(); d++)
//        {
//            if (A.Get(d) == i)                  //  将组合后的元素和i比较
//            {
//                C.Insert(m, i);                 //  相同则插入
//                m++;                            //  不同则继续
//                break;
//            }
//        }
//    }
//    
//    for (char u = 'a' - 32; u <= 'z' - 32; u++)
//    {
//        for (int d = 0; d <= A.Length(); d++)
//        {
//            if (A.Get(d) == u)                  //  将组合后的元素和i比较
//            {
//                C.Insert(m, u);                 //  相同则插入
//                m++;                            //  不同则继续
//                break;
//            }
//        }
//    }
//    return C;
//}
//
////  集合的交集运算
//template<class T>
//SeqList<T> Toge(SeqList<T> A,SeqList<T> B)
//{
//    SeqList<T> C;
//    int m = 1;
//    int flag = 0;
//    for (char i = 'a'; i <= 'z'; i++, flag = 0)
//    {
//        for (int a = 0; a <= A.Length(); a++)
//        {
//            if (A.Get(a) == i)                          //  将i与A中元素进行比较
//            {
//                for (int b = 0; b <= B.Length(); b++)
//                {
//                    if (B.Get(b) == i)                  //  将i与B中元素进行比较
//                    {
//                        C.Insert(m, i);                 //  若都有i，则将其插入C
//                        m++;
//                        flag = 1;
//                        break;
//                    }
//                }
//                if(flag == 1)
//                {
//                    break;
//                }
//            }
//        }
//    }
//    
//    for (char u = 'a' - 32; u <= 'z' - 32; u++, flag = 0)
//    {
//        for (int a = 0; a <= A.Length(); a++)
//        {
//            if (A.Get(a) == u)                          //  将i与A中元素进行比较
//            {
//                for (int b = 0; b <= B.Length(); b++)
//                {
//					if (B.Get(b) == u)                  //  将i与B中元素进行比较
//					{
//                        C.Insert(m, u);                 //  若都有i，则将其插入C
//                        m++;
//                        flag=1;
//                        break;
//					}
//                }
//                if (flag == 1)
//                {
//                    break;
//                }
//            }
//        }
//    }
//    
//    return C;
//}
//
////  集合的差集运算
//template<class T>
//SeqList<T> Subm(SeqList<T> A, SeqList<T> B)
//{
//    SeqList<T> C;
//    int m = 1;
//    int flag = 0;
//    for (char i = 'a'; i <= 'z'; i++, flag = 0)         //  这里i的范围如何修改，能够将大写的字母也加入范围中
//    {
//        for (int a = 0; a <= A.Length(); a++)
//        {
//            if (A.Get(a) == i)                          //将i与A中元素进行比较
//            {
//                for (int b = 0; b <= B.Length(); b++)
//                {
//                    if (B.Get(b) == i)                  //继续与B中元素进行比较
//                    {
//                        flag = m;
//                    }
//                }
//                if (flag == 0)
//                {
//                    C.Insert(m, i);
//                    m++;
//                    break;
//                }
//            }
//            
//        }
//    }
//    
//    for (char u = 'a' - 32; u <= 'z' - 32; u++, flag = 0) //  这里i的范围如何修改，能够将大写的字母也加入范围中
//    {
//        for (int a = 0; a <= A.Length(); a++)
//        {
//            if(A.Get(a) == u)                           //  将i与A中元素进行比较
//            {
//                for(int b = 0; b <= B.Length(); b++)
//                {
//					if(B.Get(b) == u)                   //  继续与B中元素进行比较
//                    {
//                        flag = m;
//                    }
//                }
//                if(flag == 0)
//                {
//					C.Insert(m, u);
//					m++;
//					break;
//                }
//            }
//        }
//    }
//    return C;
//}
//
//int main()
//{
//    string a;
//    string b;
//    cout << "************集合a的元素为************:\n";
//    getline(cin, a);       //  读取a的输入，因为输入中可能有空格，所以不用cin
//    cout << endl;
//    cout << "************集合b的元素为************:\n";
//    getline(cin, b);       //  读取b的输入
//    cout << endl;
//    
//    SeqList<string> A(a, (int)a.length()), B(b, (int)b.length()), C, D, E, F;
//    C = Union(A, B);
//    cout << "集合的并集为:";
//    C.display();
//    cout << endl;
//    
//    D = Toge(A, B);
//    cout << "集合的交集为:";
//    D.display();
//    cout << endl;
//    
//    E = Subm(B, A);
//    F = Subm(A, B);
//    cout << "集合的差集为:";
//    E.display();
//    F.display();
//    cout << endl;
//    return 0;
//}

//数据结构课设  顺序存储结构
#include<iostream>
using namespace std;
const int MaxSize=200;//定义Const常量 MaxSize
template<class T>//类模板
class SeqList
{
public:
    SeqList(){length=0;}//无参构造函数
    SeqList(T a[],int n)//带参构造函数
    {
        if(n>MaxSize) throw"数组元素个数不合法";//异常处理
        for(int i=0;i<n;i++)
            data[i]=a[i];
        length=n;//长度
        
    }
    SeqList(const SeqList&A)//A中元素的值不变
    {
        for(int i=0;i<A.length;i++)
            data[i]=A.data[i];
        length=A.length;
    }
    int Length()//求长度
    {
        return length;
    }
    T Get(int i)
    {
        return data[i];
    }
    int Locate(T item)//查找相同的元素
    {
        for(int i=0;i<=length;i++)
        {
            if(data[i]==item)
            {
                return i+1;
            }
        }
        return 0;
    }
    void Insert(int i,T item)//插入操作，在第i个位置前插入一个元素item
    {
        int j;
        if(length>=MaxSize) //长度不合法
        {
            throw"溢出";
        }
        if(i<1||i>length+1) //下标越界
        {
            throw"i 不合法!";
        }
        for(j=length;j>=i;j--)//数据后移
        {
            data[j]=data[j-1];
        }
        data[i-1]=item;
        length++;
    }
    T Delete(int i)//删除操作
    {
        int item,j;
        if(length==0)
        {
            throw"表为空，无法删除元素!";
        }
        if(i<1||i>length)
        {
            throw"i 不合法!";
        }
        item=data[i-1];
        for(j=i;j<length;j++)
            data[j-1]=data[j];
        length--;
        return item;
    }
    void display()//输出操作
    {
        for(int i=0;i<length;i++)
            cout<<data[i];
    }
    int empty()//判断是否为空
    {
        if(length==0)
            return 1;
        return 0;
    }
    void clear()//清理
    {
        length=0;
    }
private:
    T data[MaxSize];//存储数据的数组
    int length;//表的长度
};
template<class T>
SeqList<T>Union(SeqList<T>A,SeqList<T> B)//集合的交集运算
{
    SeqList<T> C;
    int m=1;
    int a=A.Length();
    for(int b=0;b<B.Length();b++)
    {
        A.Insert(a+b+1,B.Get(b));//将B的元素插入到A的后面的组合
    }
    for(int i=65;i<=132;i++)//确定输入字符的范围是'A'-'Z','a'-'z';
    {
        if(i==91) i=97;
        for(int d=0;d<A.Length();d++)
        {
            if(A.Get(d)==i)//将组合后的元素和i比较
            {
                C.Insert(m,i);//相同则插入
                m++;//不同则继续
                break;
            }
        }
    }
    return C;
}

template<class T>
SeqList<T>Toge(SeqList<T>A,SeqList<T> B)//集合的并集运算
{
    SeqList<T> C;
    int m=1;
    int flag;
    for(int i=65;i<=132;i++)
    {
        if(i==91) i=97;
        flag = 0;
        for(int a=0;a<A.Length();a++)
        {
            if(A.Get(a)==i)//将i与A中元素进行比较
            {
                for(int b=0;b<B.Length();b++)
                {
                    if(B.Get(b)==i)//将i与B中元素进行比较
                    {
                        C.Insert(m,i);//若都有i，则将其插入C
                        m++;
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
        }
    }
    
    
    return C;
}

template<class T>
SeqList<T>Subm(SeqList<T>A,SeqList<T> B)//集合的差集运算
{
    SeqList<T> C;
    int m=1;
    int flag;
    for(int i=65;i<=132;i++)
    {
        if(i==91) i=97;
        flag = 0;
        for(int a=0;a<A.Length();a++)
        {
            if(A.Get(a)==i)//将i与A中元素进行比较
            {
                for(int b=0;b<B.Length();b++)
                {
                    if(B.Get(b)==i)
                    {
                        flag=m;//继续与B中元素进行比较
                    }
                }
                if(flag==0)
                {
                    C.Insert(m,i);
                    m++;
                    break;
                }
            }
            
        }
    }
    return C;
}

int main()
{
    char a[100];
    char b[100];
    cout<<"************集合a的元素为************:\n";
    cin.getline(b,'\n');    //读取a的输入
    cout<<endl;
    cout<<"************集合b的元素为************:\n";
    cin.getline(a,'\n');    //读取b的输入
    cout<<endl;
    SeqList<char>A(a,50),B(b,50),C,D,E,F;
    C=Union(A,B);
    cout<<"集合的并集为:";
    C.display();
    cout<<endl;
    D=Toge(A,B);
    cout<<"集合的交集为:";
    D.display();
    cout<<endl;
    E=Subm(A,B);
    F=Subm(B,A);
    cout<<"集合的差集为:";
    E.display();
    F.display();
    cout<<endl;
    return 0;
}

