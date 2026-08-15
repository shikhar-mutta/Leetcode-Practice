// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string s
    // SC: O(n) for the stack to store the characters and their counts
    //  Approach:
    //  1. We will use a stack to keep track of the characters and their counts in the string s.
    //  2. We will iterate through the string s and for each character, we will check if it is the same as the character at the top of the stack.
    //  3. If it is the same, we will increment the count of that character in the stack. If the count reaches k, we will pop that character from the stack, effectively removing k consecutive duplicates.
    //  4. If it is not the same, we will push the character onto the stack with a count of 1.
    //  5. After iterating through the string, we will construct the result string by popping characters from the stack and appending them to the result string based on their counts.
    //  6. Finally, we will reverse the result string and return it as the final answer.
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        for (char ch : s)
        {
            if (!st.empty() && st.top().first == ch)
            {
                st.top().second++;
                if (st.top().second == k)
                {
                    st.pop(); // Remove k consecutive duplicates
                }
            }
            else
            {
                st.push({ch, 1});
            }
        }
        string ans = "";
        while (!st.empty())
        {
            char ch = st.top().first;
            int cnt = st.top().second;
            while (cnt--)
            {
                ans += ch;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};