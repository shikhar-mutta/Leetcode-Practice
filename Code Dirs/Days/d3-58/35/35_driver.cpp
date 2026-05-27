#include <bits/stdc++.h>
using namespace std;

#include "35.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        cout << sol.searchInsert(nums, target) << "\n";
    }
    return 0;
}
