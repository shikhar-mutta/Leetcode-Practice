// Link: https://leetcode.com/problems/output-contest-matches/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: pair the first with the last team repeatedly, wrapping each
// pair in parentheses, and recurse until only one string remains
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> teams(n);
        for (int i = 0; i < n; i++) teams[i] = to_string(i + 1);

        while (teams.size() > 1) {
            vector<string> next;
            int sz = teams.size();
            for (int i = 0; i < sz / 2; i++) {
                next.push_back("(" + teams[i] + "," + teams[sz - 1 - i] + ")");
            }
            teams = next;
        }
        return teams[0];
    }
};
