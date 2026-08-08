// Link: https://leetcode.com/problems/array-of-doubled-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> cnt;
        for (int x : arr) cnt[x]++;
        vector<int> keys;
        for (auto& [k, v] : cnt) keys.push_back(k);
        sort(keys.begin(), keys.end(), [](int a, int b) { return abs(a) < abs(b); });

        for (int x : keys) {
            if (cnt[x] == 0) continue;
            if (x == 0) {
                if (cnt[x] % 2 != 0) return false;
                cnt[x] = 0;
                continue;
            }
            int need = 2 * x;
            if (cnt.find(need) == cnt.end() || cnt[need] < cnt[x]) return false;
            cnt[need] -= cnt[x];
            cnt[x] = 0;
        }
        return true;
    }
};
