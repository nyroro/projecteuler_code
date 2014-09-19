#include <iostream>
#include <cstring>
using namespace std;
int p_cnt[10000010];//素因子个数
int plist[10000010];//素数表
int factor[100],fn;//因子表
int pre[10000010];
int mod[100];//余数表
int pn;//素数表个数
#define N 1e7

int extgcd(int a, int b, int & x, int & y)
{
    if (b == 0)
    {
        x=1;
        y=0;
        return a;
    }
    int d = extgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
int china(int b[],int w[],int k)
{
    int i,d,x,y,m,a=0,n=1;
    for(i=0; i<k; i++)
        n*=w[i];
    for(int i=0; i<k; i++)
    {
        m=n/w[i];
        d=extgcd(w[i],m,x,y);
        a=(a+y*m*b[i])%n;
    }
    if(a>0)return a;
    else return a+n;
}
int main()
{
    memset(p_cnt,0,sizeof(p_cnt));
    long long ans=0;
    int pn=0;
    for(int i=2; i<=N; i++)pre[i]=1;

    for(int i=2; i<=N; i++)
    {
        if(p_cnt[i]==0)
        {
            ans++;
            for(int j=i+i; j<=N; j+=i)
            {
                pre[j]=i;
                p_cnt[j]++;
            }
            plist[pn++]=i;
        }
        else
        {
            if(p_cnt[i]==1)
            {
                ans++;
            }
            else
            {
                fn=0;
                int tmp=i;
//#define FIRST
#ifndef FIRST
                int ele=-1;

                while(pre[tmp]!=1)
                {
                    int v=pre[tmp];
                    tmp=tmp/v;

                    if(ele!=v)
                    {
                        ele=v;
                        factor[fn++]=v;
                    }
                    else
                    {
                        factor[fn-1]*=ele;
                    }
                }
                int v=tmp;
                tmp=tmp/v;

                if(ele!=v)
                {
                    ele=v;
                    factor[fn++]=v;
                }
                else
                {
                    factor[fn-1]*=ele;
                }

//
//                cout<<i<<':';
//                for(int i=0; i<fn; i++)
//                {
//                    cout<<factor[i]<<' ';
//                }
//                cout<<endl;
#else


                for(int j=0; tmp>0&&plist[j]<=tmp; j++)
                {
                    int v=plist[j];
                    if(tmp%v==0)
                    {
                        tmp/=v;
                        factor[fn++]=v;
                        while(tmp>0&&tmp%v==0)
                        {
                            factor[fn-1]*=v;
                            tmp/=v;
                        }
                    }
                }
#endif
                int t_ans=1;
                for(int j=1; j<(1<<fn); j++)
                {
                    for(int k=0; k<fn; k++)
                    {
                        mod[k]=(((j)&(1<<k))!=0);
                    }
                    t_ans=max(t_ans,china(mod,factor,fn));
                }
                ans+=t_ans;
            }
        }
//        if(i%100000==0)cout<<i<<' '<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
