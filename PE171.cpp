#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
#define N 20
#define M 9*9*N
const long long mod = 1e9;
long long cnt[N+2][M+2];
long long sum[N+2][M+2];
int main()
{
    memset(cnt,0,sizeof(cnt));
    memset(sum,0,sizeof(sum));

    for(int i=0;i<=9;i++)
    {
        cnt[1][i*i]=1;
        sum[1][i*i]=i;
    }

    for(int i=2;i<=N;i++)
    {
        for(int j=0;j<=i*9*9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                if(j-k*k>=0)
                {
                    cnt[i][j]+=cnt[i-1][j-k*k];
                    cnt[i][j]%=mod;
                    sum[i][j]+=(sum[i-1][j-k*k]*10)%mod;
                    sum[i][j]%=mod;
                    sum[i][j]+=k*cnt[i-1][j-k*k];
                    sum[i][j]%=mod;
                }
            }
        }
    }

    long long ans = 0;
    for(int i=1;i*i<M;i++)
    {
        ans+=sum[N][i*i];
        cout<<i<<' '<<sum[N][i*i]<<endl;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
