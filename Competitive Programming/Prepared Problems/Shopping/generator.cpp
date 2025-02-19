#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    /* Read number from command line. */
    int n = atoi(argv[1]);
    cout << n << " ";
    int k = atoi(argv[2]);
    cout << k << endl;
    int maxc = atoi(argv[3]);
    for (int i = 0; i < n; i++) {
        cout << rnd.next(1, maxc);
        if (i + 1 < n)
            cout << " ";
    }
    cout << endl;
}
