//
//  main.c
//  f-CDOJ-2016-H-柱爷大战滑稽王
//
//  Created by ZYJ on 16/5/8.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <stdio.h>
//#include <string.h>
//#define MAXSIZE 100001
//
//int A[MAXSIZE], B[MAXSIZE];
//int dp[MAXSIZE][MAXSIZE] = {0};
//
//int MAX(int a, int b, int c)
//{
//    int max = a > b ? a : b;
//    return max > c ? max : c;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N, M;
//    int i, j;
//    while (~scanf("%d %d", &N, &M))
//    {
//        for (i = 1; i <= N; i++)
//        {
//            scanf("%d", A + i);
//        }
//        for (i = 1; i <= M; i++)
//        {
//            scanf("%d", B + i);
//        }
//        
//        for (i = 1; i <= N; i++)
//        {
//            for (j = 1; j <= M; j++)
//            {
//                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (A[i] == B[j] ? 1 : 0));
//            }
//        }
//        
//        printf("%d\n", dp[N][M] + 1);
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#define MAXSIZE 100001
//
//int A[MAXSIZE], B[MAXSIZE];
//int dp[MAXSIZE][MAXSIZE] = {0};
//
//int MAX(int a, int b, int c)
//{
//    int max = a > b ? a : b;
//    return max > c ? max : c;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N, M;
//    int i, j;
//    while (~scanf("%d %d", &N, &M))
//    {
//        for (i = 1; i <= N; i++)
//        {
//            scanf("%d", A + i);
//        }
//        for (i = 1; i <= M; i++)
//        {
//            scanf("%d", B + i);
//        }
//        
//        for (i = 1; i <= N; i++)
//        {
//            for (j = 1; j <= M; j++)
//            {
//                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (A[i] == B[j] ? 1 : 0));
//            }
//        }
//        
//        printf("%d\n", dp[N][M] + 1);
//    }
//    return 0;
//}


//#include <stdio.h>
//#define MAXSIZE 1000001
//
//int A[MAXSIZE], B[MAXSIZE];
//int C[100 * MAXSIZE];
//int D[100 * MAXSIZE];
//
//int upper_bound(int n, int len)
//{
//    for (int i = 1; i <= len; i++)
//    {
//        if (D[i] >= n)
//        {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N, M;
//    int i, j, k, len;
//    while (~scanf("%d %d", &N, &M))
//    {
//        for (i = 1; i <= N; i++)
//        {
//            scanf("%d", A + i);
//        }
//        for (i = 1; i <= M; i++)
//        {
//            scanf("%d", B + i);
//        }
//        
//        k = 1;
//        C[1] = 0;
//        for (i = 1; i <= M; i++)
//        {
//            for (j = N; j >= 1; j--)
//            {
//                if (B[i] == A[j])   //因为A[]互不相同
//                {
//                    C[k++] = j;
//                    break;
//                }
//            }
//        }
//        
//        if (C[1] == 0)
//        {
//            printf("1\n");
//            continue;
//        }
//        
//        len = 2;
//        D[1] = C[1];
//        for (i = 2; i < k; i++)
//        {
//            D[C[i] > D[len - 1] ? len++ : upper_bound(C[i], len)] = C[i];
//        }
//        
//        printf("%d\n", len);
//    }
//    return 0;
//}


/*问题代码：实现链表的查找并删除功能无法解决*/
//#include <stdio.h>
//#include <stdlib.h>
//#define MAXSIZE 11
//
//int A[MAXSIZE], B, k;
//int C[100 * MAXSIZE];
//int D[100 * MAXSIZE];
//
//typedef struct Node
//{
//    int date;
//    int key;
//    struct Node *last;
//    struct Node *next;
//} Node;
//typedef struct Node *LinkList;
//
//void CreateListHead(LinkList N, int M)
//{
//    LinkList p;
//    N = (LinkList)malloc(sizeof(Node));
//    N->date = 0;
//    N->key = 0;
//    N->last = N;
//    N->next = N;
//    for (int i = 1; i <= M; i++)
//    {
//        p = (LinkList)malloc(sizeof(Node));
//        scanf("%d", &(p->date));
//        p->key = i;
//        p->next = N->next;
//        N->next->last = p;
//        p->last = N;
//        N->next = p;
//    }
//    return ;
//}
//
//int deleteNode(LinkList *p, int flag)
//{
//    flag++;
//    C[k++] = (*p)->key;
//    (*p)->last->next = (*p)->next;
//    (*p)->next->last = (*p)->last;
//    return flag;
//}
//
//int upper_bound(int n, int len)
//{
//    for (int i = 1; i <= len; i++)
//    {
//        if (D[i] >= n)
//        {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int main(int argc, const char * argv[])
//{
//    int N, M;
//    int i, j, len;
//    while (~scanf("%d %d", &N, &M))
//    {
//        for (i = 1; i <= N; i++)
//        {
//            scanf("%d", A + i);
//        }
//        LinkList B;
//        CreateListHead(B, M);
//        
//        k = 1;
//        C[1] = 0;
//        Node **p;
//        int flag;
//        for (i = 1; i <= N; i++)
//        {
//            p = &B;
//            flag = 0;
//            for (j = M; j >= 1; j--)
//            {
//                if (B[j].date == A[i])
//                {
//                    flag = deleteNode(p, flag);
//                }
//                *p = (*p)->next;
//            }
//            M -= flag;
//        }
//        
//        if (C[1] == 0)
//        {
//            printf("1\n");
//            continue;
//        }
//        
//        len = 2;
//        D[1] = C[1];
//        for (i = 2; i < k; i++)
//        {
//            D[C[i] > D[len - 1] ? len++ : upper_bound(C[i], len)] = C[i];
//        }
//        
//        printf("%d\n", len);
//    }
//    return 0;
//}