// Link: https://leetcode.com/problems/count-almost-equal-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<long long> reach2(int xVal) {
        string s = to_string(xVal);
        int L = s.size();
        unordered_set<string> level1;
        level1.insert(s);
        for (int i = 0; i < L; i++) {
            for (int j = i + 1; j < L; j++) {
                string t = s;
                swap(t[i], t[j]);
                level1.insert(t);
            }
        }
        unordered_set<string> level2 = level1;
        for (auto& str : level1) {
            for (int i = 0; i < L; i++) {
                for (int j = i + 1; j < L; j++) {
                    string u = str;
                    swap(u[i], u[j]);
                    level2.insert(u);
                }
            }
        }
        unordered_set<long long> res;
        for (auto& str : level2) res.insert(stoll(str));
        return res;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_set<long long>> var(n);
        for (int i = 0; i < n; i++) var[i] = reach2(nums[i]);

        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (var[i].count(nums[j]) || var[j].count(nums[i])) cnt++;
            }
        }
        return (int)cnt;
    }
};
