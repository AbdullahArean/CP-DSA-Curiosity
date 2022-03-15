/*
Problem Link  :https://codeforces.com/contest/1634/problem/B
About Problem : could not solve in contest time upsolved later, need to work on bit manipulation or bit mask
Tags          : bitmasking
Learning Outcome: addition and xor both has one similiarities. even number one produces 0 in both operation.
odd number one produces 1 in both operation.
 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void Solution()
{
	int n;
	cin >> n;
	while (n--)
	{
		bool flag = 0; // alice 0 bob 1
		ll n, x, y, total=0, temp;

		//input
		cin >> n >> x >> y;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			total += temp; //getting total
		}
		total+=x;
		(total % 2 == y % 2) ? flag = 0 : flag = 1;
		!(total % 2 == y % 2) ? flag = 1 : flag = 0;
		if (flag)
			printf("Bob\n");
		else
			printf("Alice\n");
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution();

	return 0;
}