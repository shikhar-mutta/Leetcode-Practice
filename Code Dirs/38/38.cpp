// Link: https://leetcode.com/problems/count-and-say/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n). SC: O(2^n).
// Approach: We can use a string to keep track of the current term in the sequence. For each term, we can iterate through the string and count the number of consecutive digits. We can then append the count and the digit to the next term in the sequence. We repeat this process for n-1 times to get the nth term in the sequence.
class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1";
        for (int round = 2; round <= n; round++)
        {
            string next;
            for (int i = 0; i < (int)s.size();)
            {
                int j = i;
                while (j < (int)s.size() && s[j] == s[i])
                    j++;
                next += to_string(j - i);
                next += s[i];
                i = j;
            }
            s = next;
        }
        return s;
    }
};
