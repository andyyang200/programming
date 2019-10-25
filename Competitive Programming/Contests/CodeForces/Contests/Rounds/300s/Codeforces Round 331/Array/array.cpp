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
int b[200005];
int main()
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &b[i]);
	}
	ll a = 0;
	ll ans = 0;
	FOR(i, 0, n)
	{
		int x = b[i] - a;
		ans += abs(x);
		a += x;
	}
	cout << ans << endl;
}