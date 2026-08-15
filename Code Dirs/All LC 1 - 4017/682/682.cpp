// Link: https://leetcode.com/problems/baseball-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: simulate with a stack; "+" sums last two, "D" doubles last, "C" removes last, digits push the value.
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        for (auto& op : operations) {
            if (op == "+") stk.push_back(stk[stk.size()-1] + stk[stk.size()-2]);
            else if (op == "D") stk.push_back(stk.back() * 2);
            else if (op == "C") stk.pop_back();
            else stk.push_back(stoi(op));
        }
        int sum = 0;
        for (int x : stk) sum += x;
        return sum;
    }
};
