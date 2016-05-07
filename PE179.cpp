#include <iostream>
#include <cstring>
using namespace std;
int p_cnt[10000010];//素因子个数
int plist[10000010];//素数表
int factor[100],fn;//因子表
int pre[10000010];
int mod[100];//余数表
int pn;//素数表个数
#define N 10000000


int main()
{
    memset(p_cnt,0,sizeof(p_cnt));
    long long ans=0;
    int pn=0;
    for(int i=2; i<=N; i++)pre[i]=1;
    int a=-1,b;
    cout<<"start"<<endl;
    for(int i=2; i<=N; i++)
    {
        if(p_cnt[i]==0)
        {
            b=2;
            for(int j=i+i; j<=N; j+=i)
            {
                pre[j]=i;
                p_cnt[j]++;
            }
            plist[pn++]=i;
        }
        else
        {
            b=1;
            int t=i;

            while(t>1)
            {
                if(p_cnt[t]==0)
                {
                    b*=2;
                    break;
                }
                int v=pre[t];
                int num=1;
                while(t%v==0)
                {
                    t/=v;
                    num++;
                }
                b*=num;
            }
        }
        if(i%100000==0)cout<<i<<' '<<ans<<endl;
//        cout<<i<<' '<<b<<endl;
        if(b==a)
        {
            ans++;
        }
        a=b;
    }
    cout<<ans<<endl;
    return 0;
}
