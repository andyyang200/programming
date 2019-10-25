//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>	
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int dp[100001]; // dp[i] = minimum coins to make i
int a[1001];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
	}
	int v;
	cin >> v;

	FOR(i, 0, v + 1)
	{
		dp[i] = INF;
	}
	dp[0] = 0;
	FOR(i, 0, n)
	{
		RFOR(j, v, a[i] - 1)
		{
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}
}