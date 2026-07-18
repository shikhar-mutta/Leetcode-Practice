// Link: https://leetcode.com/problems/baseball-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        vector<int> sc;
        for (const string &op : operations)
        {
            int n = sc.size();
            if (op == "C")
                sc.pop_back();
            else if (op == "D")
                sc.push_back(sc[n - 1] * 2);
            else if (op == "+")
                sc.push_back(sc[n - 1] + sc[n - 2]);
            else
                sc.push_back(stoi(op));
        }
        return accumulate(sc.begin(), sc.end(), 0);
    }
};
