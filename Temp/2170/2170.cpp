// Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int,int>> topTwo(unordered_map<int,int>& freq) {
        vector<pair<int,int>> v(freq.begin(), freq.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second > b.second; });
        v.resize(min((int)v.size(), 2));
        return v;
    }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> evenFreq, oddFreq;
        int evenCount = 0, oddCount = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { evenFreq[nums[i]]++; evenCount++; }
            else { oddFreq[nums[i]]++; oddCount++; }
        }
        auto evenTop = topTwo(evenFreq);
        auto oddTop = topTwo(oddFreq);
        while (evenTop.size() < 2) evenTop.push_back({-1, 0});
        while (oddTop.size() < 2) oddTop.push_back({-1, 0});

        int best = n;
        for (auto& [ve, fe] : evenTop) {
            for (auto& [vo, fo] : oddTop) {
                if (ve == vo) continue;
                int changes = (evenCount - fe) + (oddCount - fo);
                best = min(best, changes);
            }
        }
        return best;
    }
};
