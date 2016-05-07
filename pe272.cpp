#include <iostream>
#include <stdio.h>
using namespace std;
typedef unsigned long long int llu;

const long long N = 100000000000ll;

const int PN = N/(7*9*13*19)+2;
const int SN = N/(7*9*13*19*31)+2;

bool prime[PN];
int pre[PN];
int factor[PN];
int fn;
bool ok[SN];
llu sum[SN];

llu result = 0;

void cal_prime(int n)
{
    for(int i=0;i<n;i++)
    {
        prime[i]=true;
        pre[i]=i;
    }

    for(int i=2;i<n;i++)
    {
        if(prime[i])
        {
            if(1ll*i*i<n)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    pre[j]=i;
                    prime[j]=false;
                }
            }
        }
    }
}

void find_factor(int n)
{
    factor[fn++]=9;
    for(int i=7;i<n;i++)
    {
        if(prime[i]&&i%3==1)
        {
            factor[fn++]=i;
        }
    }
    factor[0]=7;
    factor[1]=9;
}

void cal_sum(int n)
{
    for(int i=0;i<n;i++)
    {
        ok[i]=true;
    }
    for(int i=0;i<fn;i++)
    {
        int f=factor[i];
        for(int j=f;j<n;j+=f)
            ok[j]=false;
    }
    sum[0]=0;

    for(int i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+i*ok[i];
    }
}
int dfs(int level,int start,llu num)
{
    int i;
    for(i=start;i<fn;i++)
    {

        int f = factor[i];
        llu tmp = num*f;
        if(tmp>N)break;
        while(tmp<=N)
        {
            if(level == 1)
                result+=tmp*sum[N/tmp];
            else if(dfs(level-1,i+1,tmp)==i+1)
                break;
            tmp*=f;
        }
    }
    return i;
}
int main()
{
    cal_prime(PN);
    find_factor(PN);
    cal_sum(SN);
    cout<<fn<<endl;
    cout<<sum[SN-1]<<endl;
    cout<<"INIT COMPLETE"<<endl;
    result = 0;
    dfs(5,0,1);
    cout<<result<<endl;
    return 0;
}
