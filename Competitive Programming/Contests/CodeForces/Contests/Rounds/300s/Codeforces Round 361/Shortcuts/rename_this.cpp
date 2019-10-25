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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int d[200001];
vector<int> edges[200001];
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		d[i] = INF;
		int a;
		scanf("%d", &a);
		a--;
		edges[i].push_back(a);
		if (i > 0)
		{
			edges[i].push_back(i - 1);
		}
		if (i < n - 1)
		{
			edges[i].push_back(i + 1);
		}
	}
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v : edges[u])
		{
			if (d[v] == INF)
			{
				q.push(v);
				d[v] = d[u] + 1;
			}
		}
	}
	FOR(i, 0, n)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}