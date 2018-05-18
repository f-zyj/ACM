//
//  main.c
//  f-NYOJ-8-一种排序
//
//  Created by ZYJ on 16/5/23.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#include <stdlib.h>
//
//int B, C;
//struct node
//{
//    int a;
//    int b;
//    int c;
//} s[1001];
//
//int cmp(const void *a, const void *b)
//{
//    struct node *aa = (struct node *)a;
//    struct node *bb = (struct node *)b;
//    if (aa->a != bb->a)
//    {
//        return aa->a < bb->a;
//    }
//    else if (aa->b != bb->b)
//    {
//        return aa->b < bb->b;
//    }
//    else if (aa->c != bb->c)
//    {
//        return aa->c < bb->c;
//    }
//    return 0;
//}
//
//int main(int argc, const char * argv[])
//{
//    int n;
//    scanf("%d", &n);
//    
//    while (n--)
//    {
//        int m;
//        scanf("%d", &m);
//        
//        for (int i = 0; i < m; i++)
//        {
//            scanf("%d %d %d", &s[i].a, &B, &C);
//            if (B > C)
//            {
//                s[i].b = B;
//                s[i].c = C;
//            }
//            else
//            {
//                s[i].b = C;
//                s[i].c = B;
//            }
//        }
//        
//        qsort(s, m, sizeof(int), cmp);
//        
//        printf("%d %d %d\n", s[0].a, s[0].b, s[0].c);
//        for (int i = 1; i < m; i++)
//        {
//            if (s[i].a != s[i - 1].a || s[i].b != s[i -1].b || s[i].c != s[i -1].c)
//            {
//                printf("%d %d %d\n", s[i].a, s[i].b, s[i].c);
//            }
//        }
//    }
//    
//    return 0;
//}


#include<stdio.h>

int main()
{
    int n, m, x, y, z, t;
    scanf("%d\n",&n);//输入n组数据
    while(n--)
    {
        scanf("%d\n",&m);//每组数据里有m个长方形
        int s[m][3];
        for(int i = 0; i < m; i++)
        {
            for(int j=0;j<3;j++)
                scanf("%d",&s[i][j]);
            if(s[i][1]<s[i][2])
            {
                t=s[i][1];
                s[i][1]=s[i][2];
                s[i][2]=t;
            }
        }
        
        for(int i=0;i<m-1;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                if (s[i][0]>s[j][0])
                {x=s[i][0];y=s[i][1];z=s[i][2];
                    s[i][0]=s[j][0];s[i][1]=s[j][1];s[i][2]=s[j][2];
                    s[j][0]=x;s[j][1]=y;s[j][2]=z;
                }
                if(s[i][0]==s[j][0])
                {
                    if (s[i][1]>s[j][1])
                    {y=s[i][1];z=s[i][2];
                        s[i][1]=s[j][1];s[i][2]=s[j][2];
                        s[j][1]=y;s[j][2]=z;
                    }
                    if(s[i][1]==s[j][1])
                    { if (s[i][2]>s[j][2])
                    {z=s[i][2];
                        s[i][2]=s[j][2];
                        s[j][2]=z;}
                        if(s[i][2]==s[j][2])
                        {
                            s[j][0]=0;
                            s[j][1]=0;
                            s[j][2]=0;
                        }
                    }
                }
                
            }
        }
        
        for(int i=1;i<m;i++)
        {
            if(s[i][0]==0){
                
                for(int j=i;j<m;j++)
                    
                {s[j][0]=s[j+1][0];
                    s[j][1]=s[j+1][1];
                    s[j][2]=s[j+1][2];
                }
                s[m][0]=0;
                i--;
                m--;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<3;j++)
                printf("%d\t",s[i][j]);
            printf("\n");}
    }
    
}

//#include <stdio.h>
//int B, C;
//int a[1001], b[1001], c[1001];
//
//void swap(int a, int b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//    return ;
//}
//
//
//int main(int argc, const char * argv[])
//{
//    int n;
//    scanf("%d", &n);
//
//    while (n--)
//    {
//        int m;
//        scanf("%d", &m);
//       
//        for (int i = 0; i < m; i++)
//        {
//            scanf("%d %d %d", a + i, &B, &C);
//            if (B > C)
//            {
//                b[i] = B;
//                c[i] = C;
//            }
//            else
//            {
//                b[i] = C;
//                c[i] = B;
//            }
//        }
//        
//        for (int i = 0; i < m - 1; i++)
//        {
//            for (int j = i + 1; j < m; j++)
//            {
//                if (a[i] > a[j] || (a[i] == a[j] && b[i] > b[j]) || (a[i] == a[j] && b[i] == b[j] && c[i] > c[j]))
//                {
//                    swap(a[i], a[j]);
//                    swap(b[i], b[j]);
//                    swap(c[i], c[j]);
//                }
//            }
//        }
//
//        printf("%d %d %d\n", a[0], b[0], c[0]);
//        for (int i = 1; i < m; i++)
//        {
//            if (a[i] != a[i - 1] || b[i] != b[i -1] || c[i] != c[i -1])
//            {
//                printf("%d %d %d\n", a[i], b[i], c[i]);
//            }
//        }
//    }
//
//    return 0;
//}