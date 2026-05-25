#include <bits/stdc++.h>
using namespace std;

#include "9.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        Solution sol;
        bool ans = sol.isPalindrome(num);
        cout << (ans ? "true" : "false") << "\n";
    }
    return 0;
}
