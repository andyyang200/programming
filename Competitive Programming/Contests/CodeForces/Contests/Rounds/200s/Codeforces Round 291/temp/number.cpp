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
#include <map>
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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	string s;
	cin >> s;
	if (s[0] > '4' && s[0] < '9')
	{
		s[0] = '9' - s[0] + '0';
	}
	FOR(i, 1, s.length())
	{
		if (s[i] > '4')
		{
			s[i] = '9' - s[i] + '0';
		}
	}
	cout << s << endl;
}