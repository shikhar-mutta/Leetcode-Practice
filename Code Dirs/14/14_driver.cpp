#include <bits/stdc++.h>
using namespace std;

#include "14.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> strs(n);
        for (int i = 0; i < n; i++) cin >> strs[i];
        Solution sol;
        cout << sol.longestCommonPrefix(strs) << "\n";
    }
    return 0;
}
