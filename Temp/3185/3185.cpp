// Link: https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,long long> freq;
        long long cnt = 0;
        for (int h : hours) {
            int need = (24 - h % 24) % 24;
            if (freq.count(need)) cnt += freq[need];
            freq[h % 24]++;
        }
        return cnt;
    }
};
