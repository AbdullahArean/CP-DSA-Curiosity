#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
//**************************////**************************//
#define eb emplace_back
#define fill(v,val) memset(v,val,sizeof(v))
#define ll  long long
#define ld  long double
#define ff  first
#define ss  second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define sq(v) ((v)*(v))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define print(v) cout<<v<<"\n"
#define printv(v) for(auto &vv:v){cout<<vv<<" ";}cout<<"\n"
#define input(v) for(auto &vv:v){cin>>vv;}

//**************************////**************************//

const ll MOD = 1000*1000*1000+7;
const ll INF = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ld PI = 3.141592653589793;
//**************************////**************************//

ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);} 
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll binexp(ll a,ll b){if(!b)return 1;ll res=binexp(a,b/2);res=(res*res)%MOD;if(b&1)res=(a*res)%MOD;return res;}
ll binexpmod(ll x,ll y,ll p){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
vector<bool> soe(ll num) {vector<bool>pno(num,1);pno[0]=pno[1]=false;
        for(int i=2;i*i<=num;i++){if(pno[i]){for(int j=i*i;j<=num;j+=i)pno[j]=0;}}return pno;}
ll chash(string s){ll p=31,m=1e9+9;ll hv=0,p_pow=1;
        for(char c:s){hv=(hv+(c-'a'+1)*p_pow)%m;p_pow=(p_pow*p)%m;}return hv;}
int smallestDivisor(int n){if(n%2==0)return 2;for(int i=3;i*i<=n;i+=2)if(n%i==0)return i;return n;}
int nopf(int n){int ans=0;while (n!=1){ans++;int sm=smallestDivisor(n);n/=sm;}return ans;}

/**************************////**************************//

void solve()
{
    int n,m,z[(int)1e5 + 5];
    ll d[(int)1e5 + 5];
    fill(d,0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>z[i];

    vector<vector<pair<int,int>>> c((int)1e5 + 5);
    for(int i=0;i<m;i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        c[l].eb(r,k);
    }

    set<pair<int,int>> s;
    ll ans=0;
    ll dam=0;
    for(int i=1;i<=n;i++)
    {
        for(auto &x:c[i])
            s.insert(x);

        dam-=d[i];
        z[i]-=dam;
        
        while(z[i]>0)
        {
            if(s.empty() || s.rbegin()->first<i){ans=-1;break;}
            int r,k; tie(r,k)=*s.rbegin();
            s.erase(prev(s.end())); //What does it means
            
            int drop=min(k,z[i]);
            
            z[i]-=drop; k-=drop;
            ans+=drop; dam+=drop; d[r+1]+=drop;
            
            if(k)
                s.insert({r,k});
        }
        if(ans==-1)break;
    }

    if(ans==-1)
        cout<<"NO\n";
    else
        cout<<"YES "<<ans<<"\n";
}
signed main()
{
    // cout<<fixed<<setprecision(10);
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;cin>>t;
    // int t=1;
    for(int i=1;i<=t;i++)
        solve();
    #ifndef ONLINE_JUDGE
    printclock;
    #endif
}