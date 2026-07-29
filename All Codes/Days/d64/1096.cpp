// Link: https://leetcode.com/problems/brace-expansion-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: We can use a stack to keep track of the current set of strings we are building. When we encounter a '{', we push the current set of strings onto the stack and start a new set. When we encounter a '}', we pop the previous set from the stack and combine it with the current set using the Cartesian product. When we encounter a ',', we add the current set of strings to the previous set on the stack. When we encounter a letter, we add it to the current set of strings. Finally, we sort the resulting set of strings and remove duplicates before returning it.
class Solution
{
public:
    vector<string> mul(vector<string> &a, vector<string> &b)
    {
        if (a.empty())
            return b;
        if (b.empty())
            return a;

        vector<string> c;
        for (auto &x : a)
            for (auto &y : b)
                c.push_back(x + y);

        return c;
    }

    vector<string> braceExpansionII(string s)
    {
        vector<string> a, b;
        stack<vector<string>> st;

        for (auto &c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                if (b.size())
                    for (auto &x : b)
                        x += c;
                else
                    b.push_back(string(1, c));
            }
            else if (c == '{')
            {
                st.push(a);
                st.push(b);
                a.clear();
                b.clear();
            }
            else if (c == '}')
            {
                auto y = st.top();
                st.pop();
                auto x = st.top();
                st.pop();

                for (auto &t : b)
                    a.push_back(t);

                b = mul(y, a);
                a = x;
            }
            else
            {
                for (auto &t : b)
                    a.push_back(t);
                b.clear();
            }
        }

        for (auto &x : b)
            a.push_back(x);

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        return a;
    }
};