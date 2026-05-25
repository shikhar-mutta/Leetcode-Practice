#include <bits/stdc++.h>
using namespace std;

#include "121.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++) cin >> prices[i];
        Solution sol;
        cout << sol.maxProfit(prices) << "\n";
    }
    return 0;
}
