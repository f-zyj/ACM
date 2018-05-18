//
//  main.cpp
//  f-图灵杯-第四届“图灵杯”NEUQ-ACM 程序设计竞赛-H-简单的机械臂设计
//
//  Created by ZYJ on 2017/6/13.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;

int root, tot;
int sz[MAXN], pre[MAXN], ch[MAXN][2], rev[MAXN];

bool which_son(int o)
{
    return ch[pre[o]][1] == o;
}

void update_rev(int o){
    if(!o)
        return ;
    swap(ch[o][0],ch[o][1]);
    rev[o]^=1;
}

void push_up(int o){
    sz[o]=sz[ch[o][0]]+sz[ch[o][1]]+1;
}

void push_down(int o){
    if(rev[o]){
        update_rev(ch[o][0]);
        update_rev(ch[o][1]);
        rev[o]=0;
    }
}

void build(int &o,int l,int r,int fa){
    if(l>r)
        return ;
    int m=(l+r)>>1;
    o=m;
    pre[o]=fa;
    ch[o][0]=ch[o][1]=0;
    sz[o]=1;
    rev[o]=0;
    build(ch[o][0],l,m-1,o);
    build(ch[o][1],m+1,r,o);
    push_up(o);
}

void init(int n){
    root=tot=0;
    pre[0]=sz[0]=ch[0][1]=ch[0][0]=rev[0]=0;
    build(root,1,n,0);
    push_up(root);
}

void rotate(int o,int d){
    int fa=pre[o];
    push_down(fa);
    push_down(o);
    ch[fa][!d]=ch[o][d];
    pre[ch[o][d]]=fa;
    pre[o]=pre[fa];
    if(pre[fa])
        ch[pre[fa]][which_son(fa)]=o;
    pre[o]=pre[fa];
    ch[o][d]=fa;
    pre[fa]=o;
    push_up(fa);
}

void splay(int o,int goal){
    push_down(o);
    while(pre[o]!=goal){
        if(pre[pre[o]]==goal){
            push_down(pre[o]);
            push_down(o);
            rotate(o,!which_son(o));
        }
        else{
            push_down(pre[pre[o]]);
            push_down(pre[o]);
            push_down(o);
            int fa=pre[o];
            int d=!which_son(fa);
            if(ch[fa][d]==o){
                rotate(o,!d);
                rotate(o,d);
            }
            else{
                rotate(fa,d);
                rotate(o,d);
            }
        }
    }
    push_up(o);
    if(goal==0)
        root=o;
}

int get_max(int o){
    push_down(o);
    while(ch[o][1]){
        o=ch[o][1];
        push_down(o);
    }
    return o;
}

void remove(){
    if(ch[root][0]==0){
        root=ch[root][1];
        pre[root]=0;
    }
    else{
        int m=get_max(ch[root][0]);
        splay(m,root);
        ch[m][1]=ch[root][1];
        pre[ch[root][1]]=m;
        root=m;
        pre[root]=0;
        push_up(root);
    }
}

struct node{
    int v,id;
    bool operator<(const node rhs) const{
        if (v==rhs.v) return id<rhs.id;
        return v<rhs.v;
    }
}a[MAXN];

int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i].v);
            a[i].id=i;
        }
        sort(a+1,a+1+n);
        init(n);
        for(int i=1;i<n;++i){
            splay(a[i].id,0);
            printf("%d ",sz[ch[a[i].id][0]]+i);
            update_rev(ch[a[i].id][0]);
            remove();
        }
        printf("%d\n",n);
    }
    return 0;
}
