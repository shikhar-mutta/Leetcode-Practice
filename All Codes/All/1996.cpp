// Link: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int maxDef = 0, count = 0;
        for (auto& p : properties) {
            if (p[1] < maxDef) count++;
            else maxDef = p[1];
        }
        return count;
    }
};
