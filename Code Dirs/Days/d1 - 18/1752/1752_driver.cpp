#include <bits/stdc++.h>
using namespace std;

#include "1752.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        cout << sol.check(nums) << "\n";
    }
    return 0;
}
