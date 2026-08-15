// Link: https://leetcode.com/problems/maximum-number-of-removable-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubseq(const string& s, const string& p, vector<bool>& removed) {
        int j = 0;
        for (int i = 0; i < (int)s.size() && j < (int)p.size(); i++) {
            if (!removed[i] && s[i] == p[j]) j++;
        }
        return j == (int)p.size();
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int lo = 0, hi = removable.size();
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            vector<bool> removed(s.size(), false);
            for (int i = 0; i < mid; i++) removed[removable[i]] = true;
            if (isSubseq(s, p, removed)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
