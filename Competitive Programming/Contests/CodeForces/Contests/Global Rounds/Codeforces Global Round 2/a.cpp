#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int n;
int a[500005];
int f(){
    FOR(i, 0, n){
        if (a[i] != a[0]){
            if (a[n - 1] == a[0]){
                return n - 1 - i;
            }
            else{
                return n - 1;
            }
        }
    }
}

int main(){
    cin >> n;
    FOR(i, 0, n){
        scanf("%d", &a[i]);
    }
    int ans = f();
    reverse(a, a + n);
    ans = max(ans, f());
    cout << ans << endl;

}

