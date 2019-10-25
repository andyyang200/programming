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


int n;
string s;
int len[500005];
int start[500005];
int f(int i) {
	return i < n ? start[i] : n;
}
int main() {
	getline(cin, s);
	s += ' ';
	int st = 0;
	FOR(i, 0, n + 1){
		if (s[i] == ' ') {
			len[st] = i;
			len[st] -= st;
			st = i + 1;
		}
		start[i] = st;
	}
	int a, b;
	scanf("%d%d", &a, &b);
	FOR(x, a, b + 1){
		int ans = 0;
		for (int pos = 0; pos < n; pos = f(pos + x)) {
			ans += len[pos] + 1;
		}
		cout << ans - 1 << endl;
	}

}
/*
its a long way to the top if you wanna rock n roll

13 16

*/
