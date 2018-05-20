#include <stdio.h>
#include <string.h>
#define _MAX 1001

//  递归进位函数
void Carrying(int tag,int i,int j,int *p)
{
    p[i+j]+=tag;
    if (p[i+j]>9)
    {
        tag=p[i+j]/10;
        p[i+j] %=10;
        Carrying(tag, i+1, j, p);                       //  写成Carrying(tag, i, j+1, p);也成立，为了让i+j递增而已
    }
    return ;
}

int main(int argc, const char * argv[])
{
    int product[2 * _MAX],i=0,j=0,numOneLen,numTwoLen,tag;
    char numOne[_MAX],numTwo[_MAX];
    memset(product, 0, sizeof(int) * 2 * _MAX);         //  初始化product数据为0
    scanf("%s%s",numOne,numTwo);                        //  存数据
    
    numOneLen=(int)strlen(numOne);
    numTwoLen=(int)strlen(numTwo);
    
    //  数据逆序
    for (i=0; i<numOneLen/2; i++)
    {
        tag=numOne[i];
        numOne[i]=numOne[numOneLen-1-i];
        numOne[numOneLen-1-i]=tag;
    }
    for (i=0; i<numTwoLen/2; i++)
    {
        tag=numTwo[i];
        numTwo[i]=numTwo[numTwoLen-1-i];
        numTwo[numTwoLen-1-i]=tag;
    }
    
    //  逐位相乘
    for (i=0; i<numOneLen; i++)
    {
        for (j=0; j<numTwoLen; j++)
        {
            tag=((int)numOne[i]-48)*((int)numTwo[j]-48);
            Carrying(tag, i, j, product);               //  递归
        }
    }
    
    //  倒序输出结果
    for (i=_MAX * 2 - 1; i>0; i--)
    {
        if (product[i]!=0)
        {
            break;                                      //  查找到第一个不等于0的跳出
        }
    }
    for (j=i; j>=0; j--)
    {
        printf("%d",product[j]);
    }
    printf("\n");
    
    return 0;
}
