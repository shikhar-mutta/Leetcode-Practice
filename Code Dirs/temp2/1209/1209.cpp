// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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