#include <bits/stdc++.h>
using namespace std;

#include "219.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        cout << (sol.containsNearbyDuplicate(nums, k) ? "true" : "false") << "\n";
    }
    return 0;
}
