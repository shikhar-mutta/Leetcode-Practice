// Link: https://leetcode.com/problems/invalid-transactions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        int n = transactions.size();
        vector<string> name(n), city(n);
        vector<int> time(n), amount(n);
        for (int i = 0; i < n; i++)
        {
            stringstream ss(transactions[i]);
            string t;
            getline(ss, name[i], ',');
            getline(ss, t, ',');
            time[i] = stoi(t);
            getline(ss, t, ',');
            amount[i] = stoi(t);
            getline(ss, city[i], ',');
        }

        vector<string> res;
        for (int i = 0; i < n; i++)
        {
            bool invalid = amount[i] > 1000;
            for (int j = 0; j < n && !invalid; j++)
            {
                if (j != i && name[j] == name[i] && city[j] != city[i] &&
                    abs(time[j] - time[i]) <= 60)
                    invalid = true;class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        
    }
};
            }
            if (invalid)
                res.push_back(transactions[i]);
        }
        return res;
    }
};
