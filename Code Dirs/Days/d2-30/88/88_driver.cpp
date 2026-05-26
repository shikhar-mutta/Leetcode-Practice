#include <bits/stdc++.h>
using namespace std;

#include "88.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<int> nums1(m + n), nums2(n);
        for (int i = 0; i < m; i++) cin >> nums1[i];
        for (int i = 0; i < n; i++) cin >> nums2[i];
        Solution sol;
        sol.merge(nums1, m, nums2, n);
        for (int i = 0; i < m + n; i++) cout << nums1[i] << " \n"[i == m + n - 1];
        cout << "\n";
    }
    return 0;
}
