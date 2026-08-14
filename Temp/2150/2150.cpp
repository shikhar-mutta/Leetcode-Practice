// Link: https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        vector<int> res;
        for (int x : nums) {
            if (cnt[x] == 1 && !cnt.count(x - 1) && !cnt.count(x + 1)) res.push_back(x);
        }
        return res;
    }
};
