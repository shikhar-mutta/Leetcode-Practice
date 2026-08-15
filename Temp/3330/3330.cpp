// Link: https://leetcode.com/problems/find-the-original-typed-string-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int numRuns = 1;
        for (int i = 1; i < n; i++) if (word[i] != word[i-1]) numRuns++;
        return n - numRuns + 1;
    }
};
