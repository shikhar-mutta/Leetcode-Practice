// Link: https://leetcode.com/problems/invalid-transactions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> name(n), city(n);
        vector<int> time(n), amount(n);
        for (int i = 0; i < n; i++) {
            stringstream ss(transactions[i]);
            string tok;
            vector<string> parts;
            while (getline(ss, tok, ',')) parts.push_back(tok);
            name[i] = parts[0];
            time[i] = stoi(parts[1]);
            amount[i] = stoi(parts[2]);
            city[i] = parts[3];
        }

        vector<bool> invalid(n, false);
        for (int i = 0; i < n; i++) {
            if (amount[i] > 1000) invalid[i] = true;
            for (int j = 0; j < n; j++) {
                if (i == j || name[i] != name[j]) continue;
                if (abs(time[i] - time[j]) <= 60 && city[i] != city[j]) {
                    invalid[i] = true;
                    break;
                }
            }
        }

        vector<string> res;
        for (int i = 0; i < n; i++) if (invalid[i]) res.push_back(transactions[i]);
        return res;
    }
};
