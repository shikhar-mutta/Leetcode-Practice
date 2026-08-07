// Link: https://leetcode.com/problems/majority-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: Boyer-Moore for >n/3 — at most 2 such elements can exist, track two candidates with counts
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 = 0, count1 = 0, count2 = 0;
        for (int x : nums) {
            if (count1 > 0 && x == cand1) count1++;
            else if (count2 > 0 && x == cand2) count2++;
            else if (count1 == 0) { cand1 = x; count1 = 1; }
            else if (count2 == 0) { cand2 = x; count2 = 1; }
            else { count1--; count2--; }
        }
        count1 = count2 = 0;
        for (int x : nums) {
            if (x == cand1) count1++;
            else if (x == cand2) count2++;
        }
        vector<int> res;
        int n = nums.size();
        if (count1 > n / 3) res.push_back(cand1);
        if (count2 > n / 3) res.push_back(cand2);
        sort(res.begin(), res.end());
        return res;
    }
};
