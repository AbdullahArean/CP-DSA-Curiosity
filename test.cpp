/*
Problem Link  :
About Problem :
Tags          :
 */

#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = (int)1e9+5;

bool comparefn(pair<long long int, long long int> a, pair<long long int, long long int> b)
{
	if (a.first > b.first)
		return false;
	if (a.first < b.first)
		return true;
	else
	{
		if (a.second >= b.second)
			return false;
		else
			return true;
	}
}

void Solution()
{
	long long int n, k;
	long long int ans = 0;
	vector<pair<long long int, long long int>> arr;
	cin >> n >> k;
	for (long long int i = 0; i < n; i++)
	{
		long long int temp = 0;
		cin >> temp;
		// ans+=temp/k;
		arr.push_back(make_pair(temp % k, temp));
	}
	sort(arr.begin(), arr.end(), comparefn);
	long long int i = 0, j = n - 1;
	while (i < j)
	{
		if ((arr[i].first + arr[j].first) >= k)
		{
			long long int temp = arr[i].first;

			arr[j].second += temp;
			arr[i].second -= temp;

			arr[i].first = arr[i].second/k;
			arr[j].first = arr[j].second/k;
			
			i++; j--;
		}
		else if ((arr[i].first + arr[j].first) < k)
		{
			i++;
		}
	}
	 /*
	 for (long long int i = 0; i < n; i++)
	{
		cout<< arr[i].second<<" " ;
	}
	cout<<endl;
	*/
	for (long long int i = 0; i < n; i++)
	{
		ans += arr[i].second / k;
	}
	
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("inp.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	long long int t;
	cin >> t;
	while (t--)
		Solution();
	return 0;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,k,ans=0;
		scanf("%lld %lld",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			ans=ans+a[i]/k;
			a[i]=a[i]%k;
			
		}
		sort(a+1,a+1+n);
		int l=1,r=n;
		while(l<r){
			if(a[l]+a[r]<k) l++;
			else l++,r--,ans++;
		}
		printf("%lld\n",ans);
	}
}

*/