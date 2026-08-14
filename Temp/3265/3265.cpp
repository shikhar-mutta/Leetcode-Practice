// Link: https://leetcode.com/problems/count-almost-equal-pairs-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<long long> variants(int x) {
        string s = to_string(x);
        unordered_set<long long> res;
        res.insert(x);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string t = s;
                swap(t[i], t[j]);
                res.insert(stoll(t));
            }
        }
        return res;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_set<long long>> var(n);
        for (int i = 0; i < n; i++) var[i] = variants(nums[i]);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (var[i].count(nums[j]) || var[j].count(nums[i])) cnt++;
            }
        }
        return cnt;
    }
};
