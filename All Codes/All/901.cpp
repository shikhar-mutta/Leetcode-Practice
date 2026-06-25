// Link: https://leetcode.com/problems/online-stock-span/description/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    StockSpanner() {}

    // TC: O(n) amortized, SC: O(n)
    int next(int price)
    {
        int span = 1;
        // pop all previous days with price <= current, absorbing their spans
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }

private:
    stack<pair<int, int>> st; // (price, span) of unbeaten days
};
