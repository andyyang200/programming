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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int a[500];
int main(void)
{
	int n;
	cin >> n;
	int ans = INF;
	FOR(i, 0, n)cin >> a[i];
	for (int i = 0; i < n; i++) {
		int sum = 0;
		int j = i;
		FOR (k, 0, n) {
			sum += a[j];
			j = (j + 1) % n; 
			ans = min(ans, abs(sum - (360 - sum)));
		}
	}
	cout << ans << endl;
}