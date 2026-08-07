// Link: https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n+m) SC: O(n)
// Approach: map each list1 restaurant to its index, then scan list2 tracking the minimum index sum, collecting all restaurants that achieve it.
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> idx1;
        for (int i = 0; i < (int)list1.size(); i++) idx1[list1[i]] = i;
        int best = INT_MAX;
        vector<string> res;
        for (int j = 0; j < (int)list2.size(); j++) {
            auto it = idx1.find(list2[j]);
            if (it == idx1.end()) continue;
            int s = it->second + j;
            if (s < best) { best = s; res = {list2[j]}; }
            else if (s == best) res.push_back(list2[j]);
        }
        return res;
    }
};
