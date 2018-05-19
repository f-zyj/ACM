//#include<stdio.h>
//#include<string.h>
//#define BG 1000000007
//#define MAXN 2501
//
//typedef long long __int64;
//
//int n,N;
//int X[MAXN*2+1];
//struct D{ __int64 A[MAXN][MAXN]; };
//D a,T,a1,T1,b;
//D operator +(const D &c,const D &a)
//{
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++)
//            b.A[i][j]=(a.A[i][j]+c.A[i][j])%BG;
//    return b;
//}
//D operator *(const D &c,const D &a)
//{
//    __int64 q1,q2;
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++)
//        {
//            b.A[i][j]=0;
//            for(int k=0;k<n;k++)
//            {
//                q1=(__int64)c.A[i][k];
//                q2=(__int64)a.A[k][j];
//                b.A[i][j]+=(q1*q2%BG);
//                b.A[i][j]%=BG;
//            }
//        }
//    return b;
//}
//void slov(int k)
//{
//    for(int i=0;i<31;i++)
//    {
//        if((1<<i)&k)
//        {
//            a=a*a1;
//            T=(T*a1)+(a*T);
//        }
//        a1=a1*a1;
//        T1=(T1*a1)+(a1*T1);
//    }
//    int u;
//    __int64 q1,q2;
//    for(int i=0;i<n;i++)
//    {
//        u=0;
//        for(int j=0;j<n;j++)
//        {
//            q1=(__int64)a.A[i][j];
//            q2=(__int64)X[j];
//            u+=(int)(q1*q2%BG);
//            u%=BG;
//        }
//        printf("%d\n",u);
//    }
//    for(int i=n;i<N;i++)
//    {
//        u=0;
//        for(int j=0;j<n;j++)
//        {
//            q1=(__int64)T.A[i][j];
//            q2=(__int64)X[j];
//            u+=(int)(q1*q2%BG);
//            u%=BG;
//        }
//        for(int j=n;j<N;j++)
//        {
//            q1=(__int64)a.A[i][j];
//            q2=(__int64)X[j];
//            u+=(int)(q1*q2%BG);
//            u%=BG;
//        }
//        printf("%d\n",u);
//    }
//}
//int main ()
//{
//    int k;
//    scanf("%d%d",&N,&k);
//    if(N%2==0)n=N/2;
//    else n=(N+1)/2;
//    for(int i=0;i<N;i++)scanf("%d",X+i);
//    for(int i=0;i<n;i++)
//        for(int j=0;j<=i;j++)a1.A[i][j]=1;
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++)T1.A[i][j]=1;
//    for(int i=0;i<n;i++)a.A[i][i]=1;
//    slov(k);
//    return 0;
//}
//
////#include <stdio.h>
////#include <math.h>
////
////int main()
////{
////    int n;
////    while (scanf("%d", &n) == 1)
////    {
////        if (n == 0)
////        {
////            return 0;
////        }
////        
////        int digA = n % 10;
////        int digB = n / 10 % 10;
////        int digC = n / 100 % 10;
//////        printf("%d %d %d\n", digA, digB, digC);
////        
////        if (pow(digA, 3) + pow(digB, 3) + pow(digC, 3) == n)
////        {
////            printf("Yes\n");
////        }
////        else
////        {
////            printf("No\n");
////        }
////    }
////    
////    return 0;
////}

//#include<stdio.h>
//
//int main()
//{
//    int a, b, c, n;
//    a = 1;
//    b = 1;
//    printf("%d\n%d\n", a, b);
//    
//    for (n = 2; n < 30; n++)
//    {
//        c = a + b;
//        a = b;
//        b = c;
//        printf("%d\n", c);
//    }
//    return 0;
//}

#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>

#define pb push_back

#define P 63
#define Mo 1000000007

using namespace std;
typedef long long ll;
const int mod=Mo;

void jia(long long &x,long long y) { x+=y; if (x>=Mo) x-=Mo; }

long long i,j,p,k,A[P+5][P+5],E[P+5],Maxp;

long long pr[20005],MA[20005];

vector<long long>v[P],va[P],vb[P],vr[P];

ll modAdd(ll a, ll b) {
    a += b;
    return a>=mod? (a - mod) : a;
}
ll modMul(ll a , ll b) {
    a *= b;
    return a>=mod ? (a%mod) : a;
}

void multiply(const vector<ll> &Q, vector<ll> &Qr) {
    
    int size = Qr.size();
    
    for(int i = 0 ; i< size; i++) {
        Qr[i] = 0;
        for(int j = max(0 , 2*i - size +1 );  j<min( size, (2*i + 1)) ; j++) {
            
            int x = (j&1) ? ( (mod-Q[j])  ) : (Q[j]) ;
            int y = modMul(x, Q[2*i - j]);
            
            Qr[i] = modAdd(Qr[i], y );
        }
    }
}

void cal(long long *A,long long n,long long k,long long *C)
{
    vector<ll> Q(k+3);
    vector<ll> Qr(k+3);
    
    n--;
    while( n >= k) {
        Q[0] = 1;
        for(int i=0; i<k; i++) {
            Q[i+1] = -C[i];
            if(Q[i+1] < 0) {
                Q[i+1] += mod;
            }
        }
        
        for(int i=k; i< (2*k); i++) {
            A[i] = 0;
            for(int j = 0; j < k; j++) {
                int add = modMul( A[i-1-j] ,  C[j] );
                A[i] = modAdd(A[i], add);
            }
        }
        
        multiply(Q, Qr);
        
        for(int i=0; i<k; i++) {
            C[i] = (-Qr[i+1]);
            
            if(C[i] < 0) {
                C[i] += mod;
            }
        }
        
        int offset = n & 1;
        for(int i=0; i<k; i++) {
            A[i] = A[2*i + offset];
        }
        
        n /= 2;
    }
    
    printf("%lld\n",A[n]);
}

int power(int x,int y)
{
	   int sum=1;
	   for (;y;y>>=1)
       {
           if (y&1) sum=1ll*sum*x%Mo;
           x=1ll*x*x%Mo;
       }
	   return sum;
}

void guass(int n)
{
    int i,j,k;
    for (i=1;i<=n;++i)
    {
        for (j=i;j<=n;++j) if (A[j][i]) break;
        for (k=1;k<=n+1;++k) swap(A[i][k],A[j][k]);
        int p=power(A[i][i],Mo-2);
        for (j=i+1;j<=n;++j)
            if (A[j][i])
            {
                int now=1ll*A[j][i]*p%Mo;
                for (k=i;k<=n+1;++k)
                    jia(A[j][k],Mo-1ll*A[i][k]*now%Mo);
            }
    }
    for (i=n;i;--i)
    {
        for (j=i+1;j<=n;++j) jia(A[i][n+1],Mo-1ll*A[i][j]*E[j]%Mo);
        E[i]=1ll*A[i][n+1]*power(A[i][i],Mo-2)%Mo;
    }
}

long long n,m,sA[P],sB[P];

int Count(vector<long long> A,long long R)
{
    long long i,j,sum=0; R%=Mo;
    for (i=0;i<(int)A.size();++i)
    {
	  	    long long S=0,now=1;
        for (j=0;j<(int)vr[i].size();++j)
            jia(S,1ll*vr[i][j]*now%Mo),now=1ll*now*R%Mo;
        jia(sum,1ll*S*A[i]%Mo);
    }
    return sum;
}

int main()
{
    for (i=0;i<P;++i)
    {
        memset(A,0,sizeof(A));
        for (j=1;j<=i+2;++j)
        {
            for (k=1;k<=i+2;++k) A[j][k]=power(j,k-1);
            A[j][i+3]=power(2*j-1,i);
            jia(A[j][i+3],A[j-1][i+3]);
            if (j>1)
                jia(A[j][i+3],power(2*j-2,i));
        }
        guass(i+2);
        for (j=1;j<=i+2;++j) v[i].pb(E[j]);
    }
    for (i=0;i<P;++i)
    {
        memset(A,0,sizeof(A));
        for (j=1;j<=i+2;++j)
        {
            for (k=1;k<=i+2;++k) A[j][k]=power(j,k-1);
            A[j][i+3]=power(j,i);
            (A[j][i+3]+=A[j-1][i+3])%=Mo;
        }
        guass(i+2);
        for (j=1;j<=i+2;++j) vr[i].pb(E[j]);
    }
    int T;
    scanf("%d",&T);
    for (;T--;)
    {
        scanf("%lld%lld",&n,&m);
        Maxp=(int)(log2(n)+1);
        memset(sA,0,sizeof(sA)); memset(sB,0,sizeof(sB));
        for (i=1;i<=Maxp;++i) va[i].clear(),vb[i].clear();
        sA[1]=n/2; sB[1]=n; vb[1].pb(1);
        for (i=2;i<=Maxp;++i)
        {
            sA[i]=sA[i-1]/2; sB[i]=sB[i-1]/2;
            int str=Count(vb[i-1],sB[i-1]);
            for (j=0;j<i;++j) vb[i].pb(0),va[i].pb(0);
            vb[i][0]=str;
            for (j=0;j<(int)vb[i-1].size();++j)
            {
                int wei=(Mo-vb[i-1][j]);
                for (k=0;k<(int)v[j].size();++k)
                    jia(vb[i][k],1ll*wei*v[j][k]%Mo);
            }
            int End=Count(vb[i-1],sA[i-1]);
            va[i][0]=(str-End+Mo)%Mo;
            jia(va[i][0],Count(va[i-1],sA[i-1]));
            for (j=0;j<(int)va[i-1].size();++j)
            {
                int wei=(Mo-va[i-1][j]);
                for (k=0;k<(int)v[j].size();++k)
                    jia(va[i][k],1ll*wei*v[j][k]%Mo);
            }
        }
        for (i=1;i<=Maxp;++i) 
        {
            pr[i]=Count(va[i],sA[i]);
            jia(pr[i],Count(vb[i],sB[i]));
            jia(pr[i],Mo-Count(vb[i],sA[i]));
        }
        memset(MA,0,sizeof(MA));
        MA[0]=1;
        for (i=1;i<Maxp;++i) 
            for (j=1;j<=i;++j) 
                jia(MA[i],1ll*MA[i-j]*pr[j]%Mo);
        for (i=0;i<Maxp;++i) swap(pr[i],pr[i+1]); 
        if (m<Maxp) printf("%d\n",MA[m]);
        else  cal(MA,m+1,Maxp,pr);	
    }
}
