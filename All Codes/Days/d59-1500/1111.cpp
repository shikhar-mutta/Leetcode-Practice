// Link: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the string seq
// SC: O(n) where n is the length of the string seq
// Approach:
//  1. We can use a depth counter to keep track of the current depth of the parentheses.
//  2. When we encounter an opening parenthesis '(', we push the current depth % 2 to the answer vector and increment the depth counter.
//  3. When we encounter a closing parenthesis ')', we decrement the depth counter and push the current depth % 2 to the answer vector.
//  4. Finally, we return the answer vector which contains the maximum nesting depth of two valid parentheses strings.
class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> ans;
        int depth = 0;
        for (char c : seq)
        {
            if (c == '(')
            {
                ans.push_back(depth % 2); // depth before opening
                depth++;
            }
            else
            {
                depth--;
                ans.push_back(depth % 2); // depth after closing
            }
        }
        return ans;
    }
};