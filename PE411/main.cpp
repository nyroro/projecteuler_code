#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 24300000*2+10
pair<int,int> p[N];
map<int,int> mp;
typedef map<int,int>::iterator mit;
int cal(int n)
{
    int ans=0;
    mp.clear();
    for(int i=0;i<n;i++)
    {
        if(mp.empty())
        {
            mp[p[i].second]=1;
        }
        else
        {
            mit it=mp.find(p[i].second);
            //UPDATE
            if(it==mp.end())
            {
                mp[p[i].second]=1;
                it=mp.find(p[i].second);
                if(it!=mp.begin())
                {
                    it--;

                    mp[p[i].second]+=it->second;

                }
            }
            else
            {
                it->second++;
            }
            //保持第二维升序
            it=mp.find(p[i].second);
            mit next=it;
            next++;
            while(next!=mp.end())
            {

                if(it->second>=next->second)
                {
                    mp.erase(next);
                    next=it;
                    next++;
                }
                else
                {
                    break;
                }
            }
        }

        ans=max(ans,mp[p[i].second]);
    }
    return ans;
}
int S(int n)
{
    int a,b;
    a=b=1;
    for(int i=0;i<=2*n;i++)
    {
        p[i]=make_pair(a%n,b%n);
        a=a*2%n;
        b=b*3%n;
    }
    sort(p,p+2*n+1);

    int pn=unique(p,p+2*n+1)-p;
    return cal(pn);
}

int main()
{
    /*int ans=0;
    for(int i=1;i<=30;i++)
    {
        int t=S(int(pow(i,5)));
        int j=1;
        for(int k=0;k<5;k++)j*=i;
        cout<<j<<' '<<int(pow(i,5))<<endl;
        ans+=t;
        cout<<i<<' '<<t<<endl;
    }
    cout<<ans<<endl;
    */
    cout<<S(1)<<endl;
    cout<<S(22)<<endl;
    cout<<S(123)<<endl;
    cout<<S(10000)<<endl;
    return 0;
}
