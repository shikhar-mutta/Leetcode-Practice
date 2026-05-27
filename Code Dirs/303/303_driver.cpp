#include <bits/stdc++.h>
using namespace std;

#include "303.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        NumArray obj(nums);
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int left, right;
            cin >> left >> right;
            if (i > 0) cout << " ";
            cout << obj.sumRange(left, right);
        }
        cout << "\n";
    }
    return 0;
}
