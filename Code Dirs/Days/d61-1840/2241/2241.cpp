// Link: https://leetcode.com/problems/design-an-atm-machine/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for both deposit and withdraw (fixed 5 denominations)
// SC: O(1)
// Approach: track a running count per denomination. withdraw greedily uses
// the largest denominations first (always valid here since any smaller
// amount achievable with fewer large notes plus more small notes is also
// achievable by preferring large notes, and the problem only requires ANY
// valid combination, not a canonical one); if the greedy total can't hit
// the exact amount even using all available notes, fail without mutating
// any state. Only commit the withdrawal (decrement counts) after
// confirming feasibility.
class ATM {
    long long counts[5];
    const int values[5] = {20, 50, 100, 200, 500};

public:
    ATM() {
        for (int i = 0; i < 5; ++i)
            counts[i] = 0;
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i)
            counts[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount) {
        vector<int> used(5, 0);
        // greedily use largest denominations first
        for (int i = 4; i >= 0; --i) {
            long long need = min((long long)amount / values[i], counts[i]);
            used[i] = need;
            amount -= need * values[i];
        }
        if (amount != 0)
            return {-1}; // couldn't make exact amount

        // commit the withdrawal
        for (int i = 0; i < 5; ++i)
            counts[i] -= used[i];
        return used;
    }
};
