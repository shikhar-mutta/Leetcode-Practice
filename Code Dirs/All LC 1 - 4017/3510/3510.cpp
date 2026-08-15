// Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        vector<long long> val(n);
        vector<int> prevI(n), nextI(n);
        for (int i = 0; i < n; i++) {
            val[i] = nums[i];
            prevI[i] = i - 1;
            nextI[i] = (i + 1 < n) ? i + 1 : -1;
        }

        set<pair<long long,int>> pq;
        int badCount = 0;
        for (int i = 0; i < n; i++) {
            if (nextI[i] != -1) {
                pq.insert({val[i] + val[nextI[i]], i});
                if (val[i] > val[nextI[i]]) badCount++;
            }
        }

        auto removeRelation = [&](int i) {
            int j = nextI[i];
            if (j == -1) return;
            pq.erase({val[i] + val[j], i});
            if (val[i] > val[j]) badCount--;
        };
        auto addRelation = [&](int i) {
            int j = nextI[i];
            if (j == -1) return;
            pq.insert({val[i] + val[j], i});
            if (val[i] > val[j]) badCount++;
        };

        int ops = 0;
        while (badCount > 0) {
            auto it = pq.begin();
            int i = it->second;
            int j = nextI[i];

            int p = prevI[i];
            int nx = nextI[j];

            if (p != -1) removeRelation(p);
            removeRelation(i);
            if (j != -1) removeRelation(j);

            long long newVal = val[i] + val[j];
            val[i] = newVal;
            nextI[i] = nx;
            if (nx != -1) prevI[nx] = i;

            if (p != -1) addRelation(p);
            addRelation(i);

            ops++;
        }

        return ops;
    }
};
