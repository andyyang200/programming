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
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> ans;
	set<int> s;
	FOR(i, 0, n)
	{
		int a;
		scanf("%d", &a);
		s.insert(a);
	}
	FOR(i, 1, INF + 1)
	{
		if (i > m)
		{
			break;
		}
		if (s.find(i) == s.end())
		{
			ans.push_back(i);
			m -= i;
		}
	}
	cout << ans.size() << endl;
	FOR(i, 0, ans.size())
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}