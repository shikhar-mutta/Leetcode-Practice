// Link: https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int rounds = 0;
        unordered_set<int> seen;
        for (int x : rolls) {
            seen.insert(x);
            if ((int)seen.size() == k) {
                rounds++;
                seen.clear();
            }
        }
        return rounds + 1;
    }
};
