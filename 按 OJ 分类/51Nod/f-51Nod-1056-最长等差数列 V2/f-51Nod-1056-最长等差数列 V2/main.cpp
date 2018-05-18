//
//  main.cpp
//  f-51Nod-1056-最长等差数列 V2
//
//  Created by ZYJ on 2016/10/14.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#define ll long long
#define ull unsigned long long
#define d double
#define ui unsigned int
const int maxn=10023,modd=23333;
int too[maxn],pre[maxn],last[modd];
int a[maxn];
int i,j,k,n,m;

int ra,fh;char rx;
inline int read(){
    rx=getchar(),ra=0,fh=1;
    while((rx<'0'||rx>'9')&&rx!='-')rx=getchar();
    if(rx=='-')fh=-1,rx=getchar();
    while(rx>='0'&&rx<='9')ra*=10,ra+=rx-48,rx=getchar();return ra*fh;
}
inline bool exist(int v){
    if(v<=0)return 0;
    int x=v%modd,i=last[x];
    while(i&&too[i]!=v)i=pre[i];
    return i;
}
inline void insert(int v){
    int x=v%modd;
    too[i]=v,pre[i]=last[x],last[x]=i;
}
int main(){
    n=read();
    for(i=1;i<=n;i++)a[i]=read(),insert(a[i]);
    std::sort(a+1,a+1+n);int ans=2,tmp,sm,delta;ll mx;
    for(i=2;i+ans-1<=n;i++)for(j=i-1,k=i+1,tmp=a[i]<<1;j;j--){
        while(a[k]+a[j]<tmp&&k<=n)k++;
        if(k>n-ans+2)break;
        if(a[k]+a[j]==tmp){
            delta=a[i]-a[j],mx=a[j]+1ll*delta*ans;
            if(mx>a[n]||!exist(mx))continue;
            sm=3;register int now=a[k]+delta;
            while(exist(now))sm++,now+=delta;
            if(sm>ans)ans=sm;
        }
    }
    printf("%d\n",ans);
}
