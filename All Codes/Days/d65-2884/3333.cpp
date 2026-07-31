// Link: https://leetcode.com/problems/find-the-original-typed-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach: We can use a stack to solve this problem. We can iterate through the input string and for each character, we can check if it is equal to the top of the stack. If it is, we can pop the top of the stack and continue to the next character. If it is not, we can push the character onto the stack. Finally, we can return the string formed by the characters in the stack.
class Solution
{
public:
    int possibleStringCount(string word, int k)
    {
        const long long MOD = 1e9 + 7;
        int n = word.size();
        vector<int> runs;
        int i = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && word[j] == word[i])
                j++;
            runs.push_back(j - i);
            i = j;
        }
        int m = runs.size();

        long long total = 1;
        for (int L : runs)
            total = total * L % MOD;

        long long T = (long long)k - m;
        if (T <= 0)
            return (int)total;
        if (T > 200000)
            T = 200000; // safety cap, k<=2000 per constraints so unreachable

        vector<long long> dp(T, 0);
        dp[0] = 1;
        for (int L : runs)
        {
            if (L <= 1)
                continue;
            long long bound = min((long long)(L - 1), T - 1);
            vector<long long> ndp(T, 0);
            long long windowSum = 0;
            for (int s = 0; s < T; s++)
            {
                windowSum = (windowSum + dp[s]) % MOD;
                if (s - bound - 1 >= 0)
                    windowSum = (windowSum - dp[s - bound - 1] + MOD) % MOD;
                ndp[s] = windowSum;
            }
            dp = ndp;
        }

        long long countBelow = 0;
        for (int s = 0; s < T; s++)
            countBelow = (countBelow + dp[s]) % MOD;

        return (int)((total - countBelow + MOD) % MOD);
    }
};
