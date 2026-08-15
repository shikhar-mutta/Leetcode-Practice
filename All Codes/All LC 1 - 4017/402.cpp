// Link: https://leetcode.com/problems/remove-k-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string removeKdigits(string num, int k)
    {
        string st; // monotonic-increasing stack of kept digits
        for (char c : num)
        {
            while (!st.empty() && k > 0 && st.back() > c)
            {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }
        st.resize(st.size() - k); // remove any leftover k from the end
        int i = 0;
        while (i < (int)st.size() && st[i] == '0')
            i++; // strip leading zeros
        st = st.substr(i);
        return st.empty() ? "0" : st;
    }
};
