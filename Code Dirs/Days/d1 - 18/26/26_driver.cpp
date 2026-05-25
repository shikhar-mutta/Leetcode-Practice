#include <bits/stdc++.h>
using namespace std;

#include "26.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        sol.rotate(nums, k);
        for (int i = 0; i < n; i++) cout << nums[i] << " \n"[i == n - 1];
    }
    return 0;
}
