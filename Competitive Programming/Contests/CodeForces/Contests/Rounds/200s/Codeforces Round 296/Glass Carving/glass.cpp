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
typedef long long ll;
typedef pair<int, int> pii;

set<int> vertical;
set<int> horizontal;

int main()
{
	int w, h, n;
	scanf("%d%d%d", &w, &h, &n);
	vertical.insert(0);
	vertical.insert(w);
	horizontal.insert(0);
	horizontal.insert(h);
	FOR(i, 0, n)
	{
		char ch;
		cin >> ch;
		if (ch == 'V')
		{

		}
		else
		{

		}
	}
}