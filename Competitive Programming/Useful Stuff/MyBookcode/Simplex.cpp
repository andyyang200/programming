#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------


class Simplex {

private:
    int m, n;
    std::vector<std::vector<double> > A;
    std::vector<int> basic;                 // size m.  indices of basic vars
    std::vector<int> nonbasic;              // size n.  indices of non-basic vars

public:
    std::vector<double> soln;
    double z; // return value of the objective function.
    int lp_type; // for return.  1 if feasible, 0 if not feasible, -1 if unbounded

    const double INF; // unbelivably, C++ doesn't support static doubles initialized in a class
    const double EPS;
    const static int FEASIBLE = 1; // int vars are ok though
    const static int INFEASIBLE = 0;
    const static int UNBOUNDED = -1;

  /*
    input:
      m = #constraints, n =#variables
      max c dot x s.t. a x <= b
      where a = mxn, b = m vector, c = n vector
    output:
      Infeasible, or Unbounded, or a pair Feasible (z,soln) where z is
      the maximum objective function value, and soln is an n-vector of
      variable values.
    caveats:
      Cycling is possible.  Nothing is done to mitigate loss of
      precision when the number of iterations is large.
  */
    Simplex(int m0, int n0,
            std::vector<std::vector<double> > & A0,
            std::vector<double> & B,
            std::vector<double> & C) :
        m(m0),
        n(n0),
        A(m0+1),
        basic(m0),
        nonbasic(n0),
        soln(n),
        INF(1e100),
        EPS(1e-9)

    {
        for (unsigned int i = 0; i < A.size(); i++) {
            A[i].resize(n+1);
        }

        for (int j=0; j<m; j++) basic[j] = n+j;
        for (int i=0; i<n; i++) nonbasic[i] = i;

        for (int i=0; i<m; i++) {
            A[i][n] = B[i];
            for (int j=0; j<n; j++) A[i][j] = A0[i][j];
        }

        for (int j=0; j<n; j++) A[m][j] = C[j];

        if(!Feasible()) {
            lp_type = INFEASIBLE;
            return;
        }

        while(true) {
            int r=0, c=0;
            double p = 0.0;
            for (int i=0; i<n; i++) {if (A[m][i] > p) p = A[m][c=i];}
            if (p < EPS) {
                for(int j=0; j<n; j++) if (nonbasic[j] < n) soln[nonbasic[j]] = 0;
                for(int i=0; i<m; i++) if (basic[i] < n) soln[basic[i]] = A[i][n];
                z = -A[m][n];
                lp_type = FEASIBLE;
                break;
            }
            p = INF;
            for (int i=0; i<m; i++) {
                if (A[i][c] > EPS) {
                    double v = A[i][n] / A[i][c];
                    if (v < p) {p = v; r = i;}
                }
            }
            if (p == INF) {
                lp_type = UNBOUNDED;
                break;
            }
            Pivot(r,c);
        }
    }

private:

    void printa() {
	int i,j;
	for(i=0; i<=m; i++) {
	    for(j=0; j<=n; j++) {
		printf("A[%d][%d] = %f\n", i, j, A[i][j]);
	    };
	}
    }

    void Pivot(int r, int c) {

	// printf("pivot %d %d\n", r, c);
	// printa();

	swap(basic[r], nonbasic[c]);

        A[r][c] = 1 / A[r][c];
        for (int j=0; j<=n; j++) {
            if (j!=c) A[r][j] *= A[r][c];
        }
        for(int i=0; i<=m; i++) {
            if (i != r) {
                for (int j=0; j<=n; j++) {if (j!=c) A[i][j] -= A[i][c] * A[r][j];}
                A[i][c] = -A[i][c] * A[r][c];
            }
        }
    }

    bool Feasible() {
        int r=0, c=0;
        while(true) {
            double p = INF;
            for(int i=0; i<m; i++) if(A[i][n] < p) p = A[r=i][n];
            if(p > -EPS) return true;
            p = 0.0;
            for(int i=0; i<n; i++) if(A[r][i] < p) p = A[r][c=i];
            if(p > -EPS) return false;
            p = A[r][n] / A[r][c];
            for(int i=r+1; i<m; i++) {
                if(A[i][c] > EPS) {
                    double v = A[i][n] / A[i][c];
                    if(v < p) {p = v; r = i;}
                }
            }
            Pivot(r,c);
        }
    }
};
