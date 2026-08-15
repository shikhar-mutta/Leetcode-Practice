// Link: https://leetcode.com/problems/online-stock-span/description/

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
    vector<pair<int,int>> st;
public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.back().first <= price) {
            span += st.back().second;
            st.pop_back();
        }
        st.push_back({price, span});
        return span;
    }
};
