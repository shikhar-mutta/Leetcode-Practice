#include <bits/stdc++.h>
using namespace std;

#include "1838.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        cout << sol.maxFrequency(nums, k) << "\n";
    }
    return 0;
}
