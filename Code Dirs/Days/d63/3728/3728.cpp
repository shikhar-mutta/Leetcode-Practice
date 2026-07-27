// Link: https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: subarray [l,r] is stable iff capacity[l]==capacity[r]==v and
// interior sum S[r]-S[l+1]==v, which simplifies to S[r] = S[l] + 2v.
// Group indices by value; for each r in a group, count earlier l's in the
// same group (with l<=r-2, ensuring length>=3) whose prefix sum equals
// S[r]-2v, using a hashmap fed incrementally as we advance through the
// sorted group.
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        vector<long long> S(n + 1, 0);
        for (int i = 0; i < n; i++) S[i + 1] = S[i] + capacity[i];

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[capacity[i]].push_back(i);

        long long ans = 0;
        for (auto& [v, idx] : groups) {
            unordered_map<long long, int> cnt;
            int j = 0;
            for (int r : idx) {
                while (j < (int)idx.size() && idx[j] <= r - 2) {
                    cnt[S[idx[j]]]++;
                    j++;
                }
                long long need = S[r] - 2LL * v;
                auto it = cnt.find(need);
                if (it != cnt.end()) ans += it->second;
            }
        }
        return ans;
    }
};
