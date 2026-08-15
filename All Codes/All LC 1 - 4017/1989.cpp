// Link: https://leetcode.com/problems/maximum-number-of-people-that-can-be-caught-in-tag/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        int n = team.size();
        vector<bool> caught(n, false);
        int i = 0, j = 0, count = 0;
        while (i < n && j < n) {
            if (team[i] != 1) { i++; continue; }
            if (team[j] != 0 || caught[j]) { j++; continue; }
            if (abs(i - j) <= dist) {
                caught[j] = true;
                count++;
                i++;
                j++;
            } else if (j < i) {
                j++;
            } else {
                i++;
            }
        }
        return count;
    }
};
