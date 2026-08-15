// Link: https://leetcode.com/problems/substring-matching-pattern/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        int star = p.find('*');
        string pre = p.substr(0, star);
        string suf = p.substr(star + 1);
        int n = s.size();
        for (int i = 0; i + (int)pre.size() <= n; i++) {
            if (s.compare(i, pre.size(), pre) != 0) continue;
            int startSuf = i + pre.size();
            for (int j = startSuf; j + (int)suf.size() <= n; j++) {
                if (s.compare(j, suf.size(), suf) == 0) return true;
            }
        }
        return false;
    }
};
