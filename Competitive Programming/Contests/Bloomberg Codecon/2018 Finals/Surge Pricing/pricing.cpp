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
string mult[1000];
double ret[1000];
int main(void)
{
	int m;
	cin >> m;
	FOR(i, 0, m) {
		cin >> mult[i] >> ret[i];
	}
	int n;
	cin >> n;
	FOR(i, 0, n) {
		int p, d;
		cin >> p >> d;
		if (p <= d) {
			cout << "1.0 ";
			continue;
		}
		FOR(j, 0, m) {
			if (ret[j] / 100 * p <= d) {
				cout << mult[j] << " ";
				break;
			}
		}
	}
	cout << endl;
}