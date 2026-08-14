// Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrefixAndSuffix(const string& a, const string& b) {
        if (a.size() > b.size()) return false;
        return b.substr(0, a.size()) == a && b.substr(b.size() - a.size()) == a;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isPrefixAndSuffix(words[i], words[j])) cnt++;
        return cnt;
    }
};
