#include <bits/stdc++.h>
using namespace std;

#include "7.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        Solution sol;
        int ans = sol.reverse(num);
        cout << ans << "\n";
    }
    return 0;
}
