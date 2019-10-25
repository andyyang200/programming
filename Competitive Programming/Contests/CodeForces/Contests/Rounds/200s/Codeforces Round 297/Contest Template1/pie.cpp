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
int keys[26];
int main()
{
	int n;
	scanf("%d", &n);
	int count = 0;
	FOR(i, 0, n - 1)
	{
		char key, door;
		cin >> key >> door;
		keys[key - 'a']++;
		door = door - 'A' + 'a';
		if (keys[door - 'a'] == 0)
		{
			count++;
		}
		else
		{
			keys[door - 'a']--;
		}
	}
	cout << count << endl;
}