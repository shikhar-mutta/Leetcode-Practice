#include <bits/stdc++.h>
using namespace std;

#include "283.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        sol.moveZeroes(nums);
        for (int i = 0; i < n; i++) cout << nums[i] << " \n"[i == n - 1];
    }
    return 0;
}
