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
vector<int> children[100005];
int visited[100005];
int maxd = 0;
void dfs(int u, int d){
    maxd = max(maxd, d);
    visited[u] = 1;
    for(int c : children[u]) dfs(c, d + 1);
}
int main(){
    int n;
    cin >> n;
    FOR(i, 0, n){
        int p;
        cin >> p;
        if (p != -1){
            p--;
            children[p].push_back(i);
        }
    }
    FOR(i, 0, n){
        if (!visited[i]) dfs(i, 1);
    }
    cout << maxd << endl;
}

