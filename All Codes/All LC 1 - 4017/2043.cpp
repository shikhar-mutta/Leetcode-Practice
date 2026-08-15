// Link: https://leetcode.com/problems/simple-bank-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(n)
//  Approach:
//  1. We can use a vector to store the balance of each account.
//  2. We can then implement the transfer, deposit, and withdraw functions to update the balance of the accounts accordingly.
//  3. We can check if the account number is valid and if the account has enough balance before performing the operations. If the account number is invalid or the account does not have enough balance, we return false. Otherwise, we return true after performing the operation.
class Bank
{
public:
    vector<long long> balance;
    Bank(vector<long long> &balance) : balance(balance) {}

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 > balance.size() || account1 < 1 ||
            account2 > balance.size() || account2 < 1)
        {
            return false;
        }
        if (balance[account1 - 1] >= money)
        {
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money)
    {
        if (account > balance.size() || account < 1)
        {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account > balance.size() || account < 1)
        {
            return false;
        }
        if (balance[account - 1] >= money)
        {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};
