#include <bits/stdc++.h>
using namespace std;

#include "349.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums1(n);
        for (int i = 0; i < n; i++) cin >> nums1[i];
        int m;
        cin >> m;
        vector<int> nums2(m);
        for (int i = 0; i < m; i++) cin >> nums2[i];
        Solution sol;
        vector<int> result = sol.intersection(nums1, nums2);
        for (int i = 0; i < (int)result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }
    return 0;
}
