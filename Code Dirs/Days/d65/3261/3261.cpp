// Link: https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + Q log N), SC: O(N)
// Approach: two-pointer to find maxR[l] = furthest r such that s[l..r] satisfies the constraint
// (count of 0s or count of 1s <= k); maxR is non-decreasing in l. For a query [l,r], substrings
// starting at s in [l,r] contribute min(maxR[s],r)-s+1 each. Binary search the threshold where
// maxR[s] first reaches r; before it, sum via a precomputed prefix sum of (maxR[s]-s+1); from
// there to r, the contribution is a simple triangular-number sum.
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> maxR(n);
        int cnt[2] = {0, 0};
        int right = -1;
        for (int l = 0; l < n; l++) {
            if (right < l - 1) right = l - 1;
            while (right + 1 < n) {
                int nc = s[right+1] - '0';
                cnt[nc]++;
                if (cnt[0] <= k || cnt[1] <= k) { right++; }
                else { cnt[nc]--; break; }
            }
            maxR[l] = right;
            cnt[s[l]-'0']--;
        }

        vector<long long> prefixSum(n+1, 0);
        for (int i = 0; i < n; i++) prefixSum[i+1] = prefixSum[i] + (maxR[i] - i + 1);

        vector<long long> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            // find smallest s in [l,r] with maxR[s] >= r
            int lo = l, hi = r, threshold = r + 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (maxR[mid] >= r) { threshold = mid; hi = mid - 1; }
                else lo = mid + 1;
            }
            long long sumBefore = prefixSum[threshold] - prefixSum[l];
            long long countAfter = r - threshold + 1;
            long long sumAfter = countAfter * (countAfter + 1) / 2;
            ans.push_back(sumBefore + sumAfter);
        }
        return ans;
    }
};
