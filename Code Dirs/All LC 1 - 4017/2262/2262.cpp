// Link: https://leetcode.com/problems/total-appeal-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long appealSum(string s) {
        vector<int> last(26, -1);
        long long total = 0, S = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            S += (i - last[c]);
            total += S;
            last[c] = i;
        }
        return total;
    }
};
