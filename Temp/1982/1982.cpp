// Link: https://leetcode.com/problems/find-array-given-subset-sums/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        multiset<int> ms(sums.begin(), sums.end());
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int diff = *next(ms.begin()) - *ms.begin();
            multiset<int> group0, group1;
            multiset<int> pool = ms;
            vector<int> arr(ms.begin(), ms.end());

            for (int x : arr) {
                auto itx = pool.find(x);
                if (itx == pool.end()) continue;
                pool.erase(itx);
                auto it = pool.find(x + diff);
                if (it != pool.end()) {
                    pool.erase(it);
                    group0.insert(x);
                    group1.insert(x + diff);
                }
            }

            if (group0.count(0)) {
                ms = group0;
                ans.push_back(diff);
            } else {
                ms = group1;
                ans.push_back(-diff);
            }
        }
        return ans;
    }
};
