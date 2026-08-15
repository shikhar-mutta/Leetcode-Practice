// Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int target = skill[0] + skill[n-1];
        long long total = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            if (skill[i] + skill[j] != target) return -1;
            total += (long long)skill[i] * skill[j];
        }
        return total;
    }
};
