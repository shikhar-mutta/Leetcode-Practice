// Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for (int x : chalk) total += x;
        long long rem = k % total;
        for (int i = 0; i < (int)chalk.size(); i++) {
            if (rem < chalk[i]) return i;
            rem -= chalk[i];
        }
        return 0;
    }
};
