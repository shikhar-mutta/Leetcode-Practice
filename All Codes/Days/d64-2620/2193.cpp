// Link: https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(1)
//  Approach: We can use a two-pointer approach to solve this problem. We can start with two pointers, one at the beginning of the string and the other at the end. We can then iterate through the string and for each character, we can check if it matches the character at the other pointer. If it does, we can move both pointers towards the center of the string. If it does not match, we can move the pointer at the end of the string towards the center until we find a match or reach the beginning of the string. We can then count the number of moves required to make the string a palindrome and return the result.
class Solution
{
public:
    int minMovesToMakePalindrome(string s)
    {
        int n = s.size();
        int ans = 0;
        while (s.size())
        {
            int i = s.find(s.back());
            if (i == s.size() - 1)
            {
                ans += (i / 2);
                // Only one element
            }
            else
            {
                ans += i;
                s.erase(i, 1);
            }
            s.pop_back();
        }
        return ans;
    }
};