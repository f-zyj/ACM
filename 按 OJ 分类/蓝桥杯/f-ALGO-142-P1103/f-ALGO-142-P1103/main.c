//
//  main.c
//  f-ALGO-142-P1103
//
//  Created by ZYJ on 16/2/15.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <stdio.h>

typedef struct plural    //结构体－－复数
{
    float x,y;
}plu;

void add(struct plural *p, struct plural *q);
void sub(struct plural *p, struct plural *q);
void mul(struct plural *p, struct plural *q);
void did(struct plural *p, struct plural *q);

int tag = 1;
float a,b;
int main(int argc, const char * argv[])
{
    char sym;  //符号
    plu *p, p1, *q, q1;
    p = &p1;
    q = &q1;
    scanf("%c %f %f %f %f", &sym, &p->x, &p->y, &q->x, &q->y);
    
    switch (sym)
    {
        case '+':
            add(p, q);
            printf("%.2f+%.2fi\n",a,b);
            break;
        case '-':
            sub(p, q);
            printf("%.2f+%.2fi\n",a,b);
            break;
        case '*':
            mul(p, q);
            printf("%.2f+%.2fi\n",a,b);
            break;
        default:
            did(p, q);
            if (tag == 0)
            {
                break;
            }
            printf("%.2f+%.2fi\n",a,b);
            break;
    }
    return 0;
}

//加
void add(struct plural *p, struct plural *q)
{
    a = p->x + q->x;
    b = p->y + q->y;
    return ;
}
//减
void sub(struct plural *p, struct plural *q)
{
    a = p->x - q->x;
    b = p->y - q->y;
    return ;
}
//乘
void mul(struct plural *p, struct plural *q)
{
    a = p->x * q->x - p->y * q->y;
    b = p->y * q->x + p->x * q->y;
    return ;
}
//除
void did(struct plural *p, struct plural *q)
{
    if (q->x == 0 && q->y == 0)
    {
        printf("ERROR!\n");
        tag = 0;
        return ;
    }
    a = (p->x * q->x + p->y * q->y) * 1.0 / (q->x * q->x + q->y * q->y);
    b = (p->y * q->x - p->x * q->y) * 1.0 / (q->x * q->x + q->y * q->y);
    return ;
}