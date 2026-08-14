// Link: https://leetcode.com/problems/split-with-minimum-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        string a, b;
        for (int i = 0; i < (int)s.size(); i++) {
            if (i % 2 == 0) a += s[i];
            else b += s[i];
        }
        return stoi(a) + stoi(b);
    }
};
