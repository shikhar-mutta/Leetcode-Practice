// Link: https://leetcode.com/problems/number-of-good-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> cnt;
        int pairs = 0;
        for (int x : nums) {
            pairs += cnt[x];
            cnt[x]++;
        }
        return pairs;
    }
};
