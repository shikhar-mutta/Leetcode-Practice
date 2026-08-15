// Link: https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int> freq;
        int cnt = 0;
        for (int h : hours) {
            int need = (24 - h % 24) % 24;
            if (freq.count(need)) cnt += freq[need];
            freq[h % 24]++;
        }
        return cnt;
    }
};
