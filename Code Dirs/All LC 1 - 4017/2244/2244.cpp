// Link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> cnt;
        for (int x : tasks) cnt[x]++;
        int rounds = 0;
        for (auto& [k, c] : cnt) {
            if (c == 1) return -1;
            rounds += (c + 2) / 3;
        }
        return rounds;
    }
};
