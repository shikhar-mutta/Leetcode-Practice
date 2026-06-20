// Link: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N). SC: O(1).
    int chalkReplacer(vector<int> &chalk, int k)
    {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= sum; // full rounds change nothing; only the remainder matters
        // first student whose chalk exceeds the remaining k runs out
        for (int i = 0; i < (int)chalk.size(); i++)
        {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return 0; // unreachable
    }
};
