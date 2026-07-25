// Link: https://leetcode.com/problems/maximum-value-after-insertion/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the string n
// SC: O(1)
//   Approach: Greedy
//     1. If the number is negative, insert x before the first digit that is greater than x.
//     2. If the number is positive, insert x before the first digit that is less than x.
//     3. If no such digit is found, insert x at the end of the string.
class Solution
{
public:
    string maxValue(string n, int x)
    {
        int count{};
        if (n[0] == '-')
        { // negative
            count = 1;
            while (count < n.size() && n[count] - '0' <= x)
                count++;
        }
        else
        { // positive
            while (count < n.size() && n[count] - '0' >= x)
                count++;
        }

        n.push_back(' ');
        copy_backward(n.begin() + count, n.end() - 1, n.end());
        n[count] = x + '0';

        return n;
    }
};
