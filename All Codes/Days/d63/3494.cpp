// Link: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) SC: O(n)
// Approach: since a potion must be passed on the instant a wizard
// finishes it (no waiting allowed anywhere along the chain), the entire
// journey of potion j through all wizards is one contiguous block once
// it starts at time S_j: wizard i finishes it at S_j + mana[j]*cumSkill[i]
// (cumSkill = inclusive prefix sum of skill). S_j must be late enough
// that when potion j reaches each wizard i (at S_j + mana[j]*preSkill[i],
// preSkill = exclusive prefix sum), that wizard has already finished
// potion j-1: S_j = max_i(completion[i][j-1] - mana[j]*preSkill[i]).
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> cumSkill(n), preSkill(n);
        long long run = 0;
        for (int i = 0; i < n; i++) {
            preSkill[i] = run;
            run += skill[i];
            cumSkill[i] = run;
        }

        vector<long long> completion(n, 0);
        for (int j = 0; j < m; j++) {
            long long S = 0;
            for (int i = 0; i < n; i++) S = max(S, completion[i] - (long long)mana[j] * preSkill[i]);
            for (int i = 0; i < n; i++) completion[i] = S + (long long)mana[j] * cumSkill[i];
        }
        return completion[n-1];
    }
};
