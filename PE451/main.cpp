#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int p_cnt[2*10000010];//素因子个数
int plist[2*10000010];//素数表
int factor[100],fn;//因子表
int pre[2*10000010];
int mod[100];//余数表
int pn;//素数表个数
#define N 2*1e7


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
        a=(1ll*y*m*b[i]+a)%n;
    }
    if(a>0)return a;
    else return a+n;
}
int main()
{
    memset(p_cnt,0,sizeof(p_cnt));
    long long ans=0;
    int pn=0;
    int t_ans;
    for(int i=2; i<=N; i++)pre[i]=1;

    for(int i=2; i<=N; i++)
    {
        if(p_cnt[i]==0)
        {
            t_ans=1;
            for(int j=i+i; j<=N; j+=i)
            {
                pre[j]=i;
                p_cnt[j]++;
            }
            plist[pn++]=i;
        }
        else
        {
            fn=0;
            int tmp=i;
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
            t_ans=1;


            bool flag=false;
            for(int j=1; j<(1<<fn); j++)
            {
                for(int k=0; k<fn; k++)
                {
                    mod[k]=(((j)&(1<<k))!=0)?1:factor[k]-1;
                }

                int tmp=china(mod,factor,fn);

                if(tmp!=i-1)
                    t_ans=max(t_ans,tmp);

                if(factor[fn-1]%2==0&&factor[fn-1]>=8)
                {
                    mod[fn-1]=(factor[fn-1]/2-1);
                    tmp=china(mod,factor,fn);
                    if(tmp!=i-1)
                        t_ans=max(t_ans,tmp);

                    mod[fn-1]=(factor[fn-1]/2+1);
                    tmp=china(mod,factor,fn);
                    if(tmp!=i-1)
                        t_ans=max(t_ans,tmp);
                }

            }
        }
        if(i>=3)ans+=t_ans;
    }
    cout<<ans<<endl;
    return 0;
}
