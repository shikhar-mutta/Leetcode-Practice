// Link: https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        for (int x : nums) {
            string s = to_string(x);
            reverse(s.begin(), s.end());
            seen.insert(stoi(s));
        }
        return seen.size();
    }
};
