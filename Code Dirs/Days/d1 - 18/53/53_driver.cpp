#include <bits/stdc++.h>
using namespace std;

#include "53.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        cout << sol.maxSubArray(nums) << "\n";
    }
    return 0;
}
