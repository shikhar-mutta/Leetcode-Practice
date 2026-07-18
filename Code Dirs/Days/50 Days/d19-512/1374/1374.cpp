// Link: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n).
    string generateTheString(int n)
    {
        if (n % 2 == 0)
            return string(n - 1, 'a') + 'b';
        else
            return string(n, 'a');
    }
};
