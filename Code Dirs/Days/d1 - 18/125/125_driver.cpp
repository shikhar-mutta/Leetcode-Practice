#include <bits/stdc++.h>
using namespace std;

#include "125.cpp"

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Solution sol;
        bool ans = sol.isPalindrome(s);
        cout << (ans ? "true" : "false") << "\n";
    }
    return 0;
}
