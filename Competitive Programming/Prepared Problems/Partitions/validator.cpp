#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();
    for(int i = 0; i < n; i++) {
        inf.readInt(1, 1000000, "c");
        if (i + 1 < n) inf.readSpace();
    }
    inf.readEoln();
    inf.readEof();
}
