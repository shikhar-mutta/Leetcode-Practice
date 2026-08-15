// Link: https://leetcode.com/problems/clumsy-factorial/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int n) {
        stack<int> st;
        st.push(n);
        n--;
        int op = 0; // 0=*,1=/,2=+,3=-
        while (n > 0) {
            if (op == 0) { st.top() *= n; }
            else if (op == 1) { st.top() /= n; }
            else if (op == 2) { st.push(n); }
            else { st.push(-n); }
            op = (op + 1) % 4;
            n--;
        }
        int sum = 0;
        while (!st.empty()) { sum += st.top(); st.pop(); }
        return sum;
    }
};
