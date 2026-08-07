#include <bits/stdc++.h>
using namespace std;

static int _pick;
int guess(int num) {
    if (num > _pick) return -1;
    if (num < _pick) return 1;
    return 0;
}

#include "374.cpp"

int _ri() { string s; getline(cin,s); return stoi(s); }

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n = _ri();
        _pick = _ri();
        Solution sol;
        cout << sol.guessNumber(n) << "\n";
    }
    return 0;
}
