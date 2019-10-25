#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int a[200005];
int main(){
	int n, q;
	cin >> n >> q;
	FOR(i, 0, n){
        scanf("%d", &a[i]);
	}
	sort(a, a + n);
	FOR(asd, 0, q){
        int x;
        scanf("%d", &x);
        int ans = 0;
        RFOR(i, n - 1, -1){
            if (a[i] <= x){
                x -= a[i];
                ans++;
            }
        }
        if (x) ans = -1;
        printf("%d\n", ans);
	}
}
