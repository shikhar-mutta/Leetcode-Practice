#include <bits/stdc++.h>
using namespace std;

#include "27.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, val;
        cin >> n >> val;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        int k = sol.removeElement(nums, val);
        sort(nums.begin(), nums.begin() + k);
        cout << k;
        for (int i = 0; i < k; i++) cout << " " << nums[i];
        cout << "\n";
    }
    return 0;
}
