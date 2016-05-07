/*
 * File:   main.cpp
 * Author: nyroro
 *
 * Created on 2011年8月8日, 下午8:11
 */

#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define inf 0x7fffffff
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

using namespace std;

/*
 *
 */
#define mod 20092010
int m;
long long n;
#define N 2002
long long a[N],b[N],c[N*2],d[N*2];

long long mult3(long long n,long long b,long long c)
{
    if(n<=1)
        return b;
    b=mult3(n/2,b,c);
    //cout<<n<<' '<<b<<' '<<c<<endl;
    b*=b;
    b%=mod;
    if(n&1)
    {
        b*=c;
        b%=mod;
    }
    return b;
}
void mult(long long n)
{
    cout<<n<<endl;
    int i,j;
    if(n==1)
        return;
    mult(n/2);


    for(i=0;i<2*m;i++)
        d[i]=0;
    for(i=0;i<m;i++)
    {
        if(c[i])
        {
            for(j=0;j<m;j++)
            {
                d[i+j]+=c[i]*c[j];
                d[i+j]%=mod;
            }
        }
    }

    for(i=2*m-1;i>=m;i--)
    {
        if(d[i])
        {
           // cout<<i<<endl;
            for(j=0;j<m;j++)
            {
                d[i-m+j]+=d[i]*b[j];
                d[i-m+j]%=mod;
            }
            d[i]=0;
        }
    }
    if(n&1)
    {
        for(i=0;i<2*m;i++)
            c[i]=0;

        for(i=0;i<m;i++)
        {
            c[i+1]=d[i];
        }
        if(c[m]>0)
        {
            for(i=0;i<m;i++)
            {
                c[i]+=c[m]*b[i];
                c[i]%=mod;
            }
            c[m]=0;
        }
    }
    else
    {
        for(i=0;i<m;i++)
            c[i]=d[i];
    }
}
int main() {

    int t;
    t=1;
    while(t--)
    {
        m=2000;
        n=1000000000000000000ll;

        if(m==1)
        {
            long long a,b,c;
            cin>>a>>b;
            c=b;
            cout<<(a*mult3(n,b,c))%mod<<endl;;
            continue;
        }
        int i,j;
        for(i=0;i<m;i++)
            a[i]=1;
        for(i=0;i<m;i++)
            b[i]=0;
        b[0]=b[1]=1;

        for(i=0;i<2*m;i++)
            c[i]=0;
        c[1]=1;

        mult(n);

        long long res=0;

        for(i=0;i<m;i++)
        {
            res+=c[i]*a[i];
            res%=mod;
        }
        cout<<res<<endl;
    }

    return 0;
}
