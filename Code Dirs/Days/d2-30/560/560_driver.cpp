#include <bits/stdc++.h>
using namespace std;

#include "560.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        cout << sol.subarraySum(nums, k) << "\n";
    }
    return 0;
}
