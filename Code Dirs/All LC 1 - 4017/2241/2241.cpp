// Link: https://leetcode.com/problems/design-an-atm-machine/description/

#include <bits/stdc++.h>
using namespace std;

class ATM {
    vector<long long> count;
    vector<int> denom = {20, 50, 100, 200, 500};
public:
    ATM() {
        count.assign(5, 0);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) count[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount) {
        vector<long long> use(5, 0);
        long long remaining = amount;
        for (int i = 4; i >= 0; i--) {
            long long take = min(count[i], remaining / denom[i]);
            use[i] = take;
            remaining -= take * denom[i];
        }
        if (remaining != 0) return {-1};
        for (int i = 0; i < 5; i++) count[i] -= use[i];
        return vector<int>(use.begin(), use.end());
    }
};
