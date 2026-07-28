// Link: https://leetcode.com/problems/recover-the-original-array/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2 log n)  SC: O(n)
// Approach: sort nums. 2k must equal nums[i]-nums[0] for some i>0 (k>0), so
// try each candidate; for a valid k, greedily pair each unmatched smallest
// value v with v+2k (multiset), taking arr[i]=v+k. First candidate that
// successfully pairs everything gives the answer.
class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            long long diff = nums[i] - nums[0];
            if (diff <= 0 || diff % 2 != 0) continue;
            long long k = diff / 2;
            multiset<int> ms(nums.begin(), nums.end());
            vector<int> result;
            bool ok = true;
            while (!ms.empty()) {
                int v = *ms.begin();
                ms.erase(ms.begin());
                auto it = ms.find(v + 2 * k);
                if (it == ms.end()) { ok = false; break; }
                ms.erase(it);
                result.push_back(v + (int)k);
            }
            if (ok) return result;
        }
        return {};
    }
};
