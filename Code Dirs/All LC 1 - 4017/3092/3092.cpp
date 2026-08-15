// Link: https://leetcode.com/problems/most-frequent-ids/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> cnt;
        multiset<long long> vals;
        vector<long long> res;
        for (int i = 0; i < (int)nums.size(); i++) {
            int id = nums[i];
            auto it = cnt.find(id);
            if (it != cnt.end() && it->second != 0) vals.erase(vals.find(it->second));
            long long newVal = (it != cnt.end() ? it->second : 0) + freq[i];
            cnt[id] = newVal;
            if (newVal != 0) vals.insert(newVal);
            res.push_back(vals.empty() ? 0 : *vals.rbegin());
        }
        return res;
    }
};
