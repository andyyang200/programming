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
#define P 37
typedef long long ll;
typedef pair<int, int> pii;
ll phash[100001];
ll power[100001];
ll getHash(int l, int r)
{
	ll ret = phash[r];
	if (l > 0)
	{
		ret -= (phash[l - 1] * power[r - l + 1]) % M;
		while (ret < 0)
		{
			ret += M;
		}
	}
	ret %= M;
	return ret;
}
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	string s;
	cin >> s;
	phash[0] = s[0];
	power[0] = 1;
	FOR(i, 1, s.length())
	{
		phash[i] = phash[i - 1] * P + s[i];
		phash[i] %= M;
		power[i] = power[i - 1] * P;
		power[i] %= M;
	}
}