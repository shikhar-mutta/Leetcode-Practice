// Link: https://leetcode.com/problems/repeated-string-match/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m). SC: O(n).
// Approach: We can keep appending the string a to itself until its length is greater than or equal to the length of string b. Then we can check if b is a substring of the resulting string. If it is, we return the number of times we appended a. If not, we append a one more time and check again. If b is still not a substring, we return -1.
class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        string s = a;
        int cnt = 1;
        while (s.size() < b.size())
        {
            s += a;
            cnt++;
        }
        if (s.find(b) != string::npos)
            return cnt;
        s += a; // one extra copy covers matches that wrap past the boundary
        if (s.find(b) != string::npos)
            return cnt + 1;
        return -1;
    }
};
