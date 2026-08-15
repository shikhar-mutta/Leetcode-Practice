// Link: https://leetcode.com/problems/recover-the-original-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<int> triedK;
        for (int i = 1; i < n; i++) {
            long long diff = (long long)nums[i] - nums[0];
            if (diff <= 0 || diff % 2 != 0) continue;
            int k = (int)(diff / 2);
            if (triedK.count(k)) continue;
            triedK.insert(k);

            multiset<int> ms(nums.begin(), nums.end());
            vector<int> result;
            bool ok = true;
            while (!ms.empty()) {
                int x = *ms.begin();
                ms.erase(ms.begin());
                auto it = ms.find(x + 2 * k);
                if (it == ms.end()) { ok = false; break; }
                ms.erase(it);
                result.push_back(x + k);
            }
            if (ok) return result;
        }
        return {};
    }
};
