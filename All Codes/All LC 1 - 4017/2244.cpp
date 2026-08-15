// Link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: count occurrences of each task difficulty. A count of exactly
// 1 can never be fully grouped into rounds of 2 or 3, so it's impossible.
// Otherwise, any count >= 2 can always be partitioned optimally into groups
// of 2s and 3s using ceil(cnt/3) rounds (since 3a+2b=cnt is always solvable
// for cnt>=2, and using as many 3-groups as possible minimizes the round
// count). Sum this over all distinct difficulties.
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> freq;

        for (int x : tasks)
            ++freq[x];

        int rounds = 0;
        for (const auto& [_, cnt] : freq) {
            if (cnt == 1)
                return -1;
            rounds += (cnt + 2) / 3;
        }

        return rounds;
    }
};
