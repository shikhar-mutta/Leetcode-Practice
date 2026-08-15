// Link: https://leetcode.com/problems/make-three-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int minLen = min({s1.size(), s2.size(), s3.size()});
        int common = 0;
        while (common < minLen && s1[common] == s2[common] && s2[common] == s3[common]) common++;
        if (common == 0) return -1;
        return (int)(s1.size() - common) + (int)(s2.size() - common) + (int)(s3.size() - common);
    }
};
