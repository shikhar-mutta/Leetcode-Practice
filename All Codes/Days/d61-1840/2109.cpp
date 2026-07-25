// Link: https://leetcode.com/problems/adding-spaces-to-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), where n is the length of the string s and m is the length of the spaces array.
// SC: O(n + m), where n is the length of the string s and m is the length of the spaces array.
// Approach:
//  1. We initialize two pointers, wrInd and spInd, to keep track of the current index in the answer string and the current index in the spaces array, respectively. We also create an answer string of size s.size() + spaces.size() initialized with spaces.
//  2. We iterate through the string s using a for loop. For each character in s, we check if the current index strInd is equal to the current space index in the spaces array. If it is, we add a space to the answer string at the current wrInd and increment the spInd. We then add the current character from s to the answer string at the current wrInd and increment the wrInd.
//  3. Finally, we return the answer string.
class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int wrInd = 0;
        int spInd = 0;
        string ans(s.size() + spaces.size(), ' ');

        for (int strInd = 0; strInd < s.size(); strInd++)
        {
            if (spInd < spaces.size() && strInd == spaces[spInd])
            {
                ans[wrInd++] = ' ';
                spInd++;
            }
            ans[wrInd++] = s[strInd];
        }
        return ans;
    }
};
