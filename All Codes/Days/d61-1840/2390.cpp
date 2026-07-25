// Link: https://leetcode.com/problems/removing-stars-from-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the length of the input string s, as we iterate through each character of the string once.
// SC: O(n), where n is the length of the input string s, as we are using a vector to store the characters of the resulting string.
//  Approach:
//   1. We initialize an empty vector st to store the characters of the resulting string.
//   2. We iterate through each character ch in the input string s using a for loop. For each character, we check if it is a star ('*').
//   3. If the character is a star, we pop the last character from the vector st using the pop_back() function, effectively removing the last character from the resulting string.
//   4. If the character is not a star, we push it onto the vector st using the push_back() function, effectively adding it to the resulting string.
//   5. After iterating through all characters in the input string, we convert the vector st to a string using the string constructor and return it as the final result.
class Solution
{
public:
    string removeStars(string s)
    {
        vector<char> st;
        for (char ch : s)
        {
            if (ch == '*')
            {
                st.pop_back();
            }
            else
            {
                st.push_back(ch);
            }
        }
        return string(st.begin(), st.end());
    }
};