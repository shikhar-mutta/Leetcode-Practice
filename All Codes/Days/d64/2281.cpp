// Link: https://leetcode.com/problems/sum-of-total-strength-of-wizards/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: monotonic stack to find, for each i, the range (left, right)
// where strength[i] is the strict minimum (left exclusive strictly less,
// right exclusive less-or-equal to avoid double counting duplicates).
// For that range, sum over all subarrays containing i of (subarray sum)
// is computed via prefix-of-prefix sums (P2) with a closed formula, then
// multiplied by strength[i] and accumulated mod 1e9+7.
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const long long MOD = 1e9 + 7;
        int n = strength.size();
        vector<long long> P(n + 1, 0), P2(n + 2, 0);
        for (int i = 0; i < n; i++) P[i+1] = (P[i] + strength[i]) % MOD;
        for (int i = 0; i <= n; i++) P2[i+1] = (P2[i] + P[i]) % MOD;
        vector<int> left(n), right(n);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && strength[st.back()] >= strength[i]) st.pop_back();
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && strength[st.back()] > strength[i]) st.pop_back();
            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = left[i], r = right[i];
            long long leftCount = i - l;
            long long rightCount = r - i;
            long long sumRight = (P2[r + 1] - P2[i + 1] + MOD * MOD) % MOD;
            long long sumLeft = (P2[i + 1] - P2[l + 1] + MOD * MOD) % MOD;
            long long total = ((leftCount * sumRight - rightCount * sumLeft) % MOD + MOD) % MOD;
            ans = (ans + (long long)strength[i] % MOD * total) % MOD;
        }
        return (int)ans;
    }
};
