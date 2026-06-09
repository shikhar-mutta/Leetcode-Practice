// Link: https://leetcode.com/problems/repeated-substring-pattern/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Approach: KMP Algorithm(Use of Longest Proper Prefix which is also Suffix array)
    // TC: O(n), SC: O(n)
    bool solve(string &s)
    {
        int n = s.size();
        vector<int> lps(n, 0); // longest proper prefix which is also suffix array
        int len = 0, i = 1;    // len is length of longest proper prefix
        int maxlen = 0;        // maxlen is length of longest proper prefix which is also suffix
        while (i < n)
        {
            if (s[i] == s[len]) // if match, then increment len and assign it to lps[i]
            {
                len++;
                lps[i] = len;
                i++;
                maxlen = max(maxlen, len);
            }
            else
            {
                if (len != 0) // if not match and len is not 0, then update len to lps[len - 1]
                    len = lps[len - 1];
                else // f if not match and len is 0, then assign 0 to lps[i] and increment i
                    i++;
            }
        }

        len = lps[n - 1];                       // length of longest proper prefix which is also suffix
        return (len > 0 && n % (n - len) == 0); // n - len is the length of the substring which is repeated
    }

public:
    bool repeatedSubstringPattern(string s)
    {
        return solve(s);
    }
};