#include <iostream>
#include <cmath>
using namespace std;
const long long N=100000000000000ll;
const int P=10000;
bool prime[P];
int plist[P];
int pn;
void init()
{
    pn=0;

    for(int i=2;i<P;i++)
    {
        if(!prime[i])
        {
            plist[pn++]=i;
            if(1ll*i*i<P)
            {
                for(int j=i*i;j<P;j+=i)
                {
                    prime[j]=true;
                }
            }
        }
    }
}
const int mod=1e9+7;
int arr[100];
int an;
int ans1,ans2;
int sum(long long x)
{
    long long t=x+1;
    if(x%2==0)x/=2;
    else t/=2;
    return (x%mod)*(t%mod)%mod;
}
void dfs(int depth,int st,int val,const long long &N,const int &X)
{
    if(depth%2==0)
    {
        ans1=(ans1+(N/val)%mod-(X/val)+mod)%mod;
        ans2=(ans2+(1ll*val*sum(N/val))%mod-(1ll*val*sum(X/val))%mod+mod)%mod;
//        if(X==4)
//        {
//            cout<<val<<' '<<N/val<<' '<<sum(N/val)<<' '<<ans2<<endl;
//        }
    }
    else
    {
        ans1=(ans1-(N/val)%mod+(X/val)+mod)%mod;
        ans2=(ans2-(1ll*val*sum(N/val))%mod+(1ll*val*sum(X/val))%mod+mod)%mod;
//        if(X==4)
//        {
//            cout<<val<<' '<<N/val<<' '<<sum(N/val)<<' '<<sum(X/val)<<' '<<ans2<<endl;
//        }
    }
    if(depth==an)return;

    for(int i=st;i<an;i++)
    {
        dfs(depth+1,i+1,val*arr[i],N,X);
    }
}
int solve(int x)
{
    an=0;
    int t=x;
    for(int i=0;i<pn&&plist[i]<t;i++)
    {
        if(t%plist[i]==0)
        {
            arr[an++]=plist[i];
            while(t%plist[i]==0)t/=plist[i];
        }
    }
    if(t>1)arr[an++]=t;
//    cout<<"FACTORIZATION"<<x<<' '<<an<<endl;
//    for(int i=0;i<an;i++)cout<<arr[i]<<' ';
//    cout<<endl;
    ans1=0;
    ans2=0;
    dfs(0,0,1,N/x,x);
//    cout<<"SOLVE"<<x<<' '<<ans1<<' '<<ans2<<endl;


    return (1ll*ans1*x%mod+ans2)%mod;
}
int main()
{
    init();
    long long ans=0;
    int n=sqrt(N);
//    cout<<n<<' '<<n*n<<' '<<N<<endl;
    for(int i=2;i<=n;i++)
    {
        int t=solve(i);
//        cout<<i<<' '<<t<<endl;
        ans=(ans+t)%mod;
        if(i%100000==0)cout<<i<<' '<<ans<<endl;
    }
    ans=(ans+(N-1))%mod;
    cout<<ans<<endl;
    return 0;
}
