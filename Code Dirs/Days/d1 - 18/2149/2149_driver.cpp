#include <bits/stdc++.h>
using namespace std;

#include "2149.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        vector<int> ans = sol.rearrangeArray(nums);
        for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }
    return 0;
}
