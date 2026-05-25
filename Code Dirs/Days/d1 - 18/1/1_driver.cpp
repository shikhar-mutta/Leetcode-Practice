#include <bits/stdc++.h>
using namespace std;

#include "1.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n;
        vector<int> nums(n);
        for (auto& x : nums) cin >> x;
        cin >> target;

        Solution sol;
        vector<int> ans = sol.twoSum(nums, target);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
