// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-word-k-periodic/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = word.size();
        unordered_map<string,int> freq;
        int maxF = 0;
        for (int i = 0; i < n; i += k) {
            string block = word.substr(i, k);
            maxF = max(maxF, ++freq[block]);
        }
        return n / k - maxF;
    }
};
