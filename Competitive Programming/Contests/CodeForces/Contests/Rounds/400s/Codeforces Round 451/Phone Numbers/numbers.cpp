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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
map<string, vector<string>> m;
bool isSuffix(string a, string b) {
	if (a.length() > b.length()) return false;
	FOR(i, 0, a.length()) {
		if (b[b.length() - i - 1] != a[a.length() - i - 1]) {
			return false;
		}
	}
	return true;
}
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		int nn;
		string name;
		cin >> name >> nn;
		FOR(j, 0, nn) {
			string number;
			cin >> number;
			m[name].push_back(number);
		}
	}
	cout << m.size() << endl;
	FOREACH(itr, m) {
		vector<string> v = itr->second;
		FOR(i, 0, v.size()) {
			FOR(j, 0, v.size()) {
				if (i == j) continue;
				if (isSuffix(v[i], v[j])) {
					v.erase(v.begin() + i);
					i--;
					break;
				}
			}
		}
		cout << itr->first << " " << v.size() << " ";
		for (string x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}