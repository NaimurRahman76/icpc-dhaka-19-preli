#include<bits/stdc++.h>
using namespace std;
#define N 10000002
#define int long long
#define endl '\n'
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20)
///............Author..................................................................
///........... :: .....................................................................
///...........(  NOBODY  )................................................................
///........... Bangabandhu Sheikh Mujibur Rahman Science and Technlogy University,Gopalganj
///............www.facebook.com/naimur76...................................................
///................durjoyovi76@gmail.com...................................................
///........... ....( N~76 ) ...................................................................
///........... No Copyright .....You can copy and paste my code without any permission.....
/// !!!!!!!!!!!!!!!........................................................................
#define pb push_back
#define esp 0.000000001
#define pi acos(-1)
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
bool vis[N];
int totient[N];
vector<int>prime;
void sieve(int n)
{
    memset(vis,false,sizeof(vis));
    totient[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]){
                prime.push_back(i);
                totient[i]=i-1;
        }
        for(int j=0;j<prime.size()&&i*prime[j]<=n;j++)
        {
            vis[i*prime[j]]=true;
            if(i%prime[j]==0){
                totient[i*prime[j]]=prime[j]*totient[i];
                break;
            }
            else totient[i*prime[j]]=totient[i]*totient[prime[j]];
        }
    }
}
int32_t main()
{
    FAST_IO;
    int n,t=0;
    cin>>n;
    sieve(10000000+1);
    for(int i=1;i<=1e7;i++)totient[i]+=totient[i-1];
    while(n--)
    {
        t++;
        int x,y;
        cin>>x>>y;
        int low=1,high=x,fans=-1;
        while(low<=high)
        {
                int mid=(low+high)/2;
                if(totient[x/mid]>=y)
                {
                    fans=mid;
                    low=mid+1;
                }
                else high=mid-1;
        }
        cout<<"Case "<<t<<": "<<fans<<endl;

    }
}

