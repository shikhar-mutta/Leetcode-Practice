// Link: https://leetcode.com/problems/maximum-elegance-of-a-k-length-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: sort by profit descending, take the top k as the base selection. Track which
// categories are already represented and stack up "redundant" duplicates from within the top k
// (same category repeated). Then scan the remaining items: any item introducing a brand-new
// category is worth swapping in for the least profitable duplicate (stack top), since it both
// keeps the profit sum nearly the same and grows the distinct-category bonus.
class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](auto& a, auto& b) { return a[0] > b[0]; });
        int n = items.size();

        long long sum = 0;
        unordered_set<int> seen;
        vector<long long> dupStack;
        for (int i = 0; i < k; i++) {
            sum += items[i][0];
            if (!seen.insert(items[i][1]).second) dupStack.push_back(items[i][0]);
        }

        long long ans = sum + (long long)seen.size() * seen.size();
        for (int i = k; i < n; i++) {
            if (seen.count(items[i][1]) || dupStack.empty()) continue;
            sum += items[i][0] - dupStack.back();
            dupStack.pop_back();
            seen.insert(items[i][1]);
            ans = std::max(ans, sum + (long long)seen.size() * (long long)seen.size());
        }
        return ans;
    }
};
