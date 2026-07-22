// Link: https://leetcode.com/problems/remove-duplicate-letters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string.
    // SC: O(n) where n is the length of the input string.
    // Approach:
    //  1. We can use a stack to keep track of the characters in the result string. We can also use a map to keep track of the count of each character in the input string.
    //  2. We can iterate through the input string and for each character, we can decrement its count in the map. If the character is already in the stack, we can skip it.
    //  3. If the character is not in the stack, we can compare it with the top character of the stack. If the top character is greater than the current character and its count in the map is greater than 0, we can pop the top character from the stack and remove it from the set of characters in the stack. We can repeat this process until we find a character that is less than or equal to the current character or its count in the map is 0.
    //  4. Finally, we can push the current character onto the stack and add it to the set of characters in the stack. After iterating through the input string, we can pop all the characters from the stack and reverse the result string to get the final answer.
    string removeDuplicateLetters(string s)
    {
        int n = s.size();
        map<char, int> mpp;
        for (int i = 0; i < n; i++)
            mpp[s[i]]++;
        set<char> ox;
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            mpp[s[i]]--;
            if (ox.find(s[i]) != ox.end())
                continue;
            if (!st.empty() && st.top() < s[i])
                st.push(s[i]);
            else
            {
                while (!st.empty() && st.top() > s[i])
                {
                    if (mpp[st.top()] == 0)
                        break;
                    ox.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
            ox.insert(s[i]);
        }
        string t = "";
        while (!st.empty())
        {
            t += st.top();
            st.pop();
        }
        reverse(t.begin(), t.end());
        return t;
    }
};