// Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> res(spells.size());
        for (int i = 0; i < (int)spells.size(); i++) {
            long long need = (success + spells[i] - 1) / spells[i];
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            res[i] = m - idx;
        }
        return res;
    }
};
