// Link: https://leetcode.com/problems/simple-bank-system/description/

#include <bits/stdc++.h>
using namespace std;

class Bank {
    vector<long long> balance;
    int n;
public:
    Bank(vector<long long>& balance) : balance(balance) {
        n = balance.size();
    }

    bool valid(int account) {
        return account >= 1 && account <= n;
    }

    bool transfer(int account1, int account2, long long money) {
        if (!valid(account1) || !valid(account2)) return false;
        if (balance[account1 - 1] < money) return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!valid(account)) return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!valid(account)) return false;
        if (balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }
};
