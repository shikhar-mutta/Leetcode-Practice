// Link: https://leetcode.com/problems/invalid-transactions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(n)
    // Approach: We can split the transaction string into name, time, amount and city. Then we can check for each transaction if it is invalid or not. A transaction is invalid if the amount is greater than 1000 or if there is another transaction with the same name but different city and the time difference is less than or equal to 60 minutes.
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
                    invalid = true;
                class Solution
                {
                public:
                    vector<string> invalidTransactions(vector<string> &transactions)
                    {
                    }
                };
            }
            if (invalid)
                res.push_back(transactions[i]);
        }
        return res;
    }
};
