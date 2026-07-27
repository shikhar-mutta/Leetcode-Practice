// Link: https://leetcode.com/problems/maximum-number-of-subsequences-after-one-inserting/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: Count the number of L's before C and T's after C. The answer is the maximum of the number of subsequences formed by inserting C, L, or T. We can also keep track of the best number of subsequences formed by the existing C's in the string.
class Solution
{
public:
    typedef long long ll;
    long long numOfSubsequences(string s)
    {
        int n = s.size();
        vector<int> prev(n + 1, 0);
        vector<int> suff(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
            {
                prev[i + 1] = 1;
            }
            prev[i + 1] += prev[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == 'T')
            {
                suff[i] = 1;
            }
            suff[i] += suff[i + 1];
        }
        // No of Subsequences already exists?
        ll insC = 0;
        ll bestC = 0;
        ll insL = 0;
        ll insT = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'C')
            {
                insC += prev[i] * suff[i + 1];
                insL += (prev[i] + 1) * suff[i + 1];
                insT += prev[i] * (suff[i + 1] + 1);
            }
            else
            {
                bestC = max((1LL) * prev[i] * suff[i], bestC);
            }
        }
        insC += bestC;
        return max({insC, insL, insT});
    }
};