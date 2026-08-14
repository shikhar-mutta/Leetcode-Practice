// Link: https://leetcode.com/problems/finding-3-digit-even-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10] = {0};
        for (int d : digits) cnt[d]++;
        vector<int> res;
        for (int num = 100; num <= 998; num += 2) {
            int a = num / 100, b = (num / 10) % 10, c = num % 10;
            int need[10] = {0};
            need[a]++; need[b]++; need[c]++;
            bool ok = true;
            for (int i = 0; i < 10; i++) if (need[i] > cnt[i]) { ok = false; break; }
            if (ok) res.push_back(num);
        }
        return res;
    }
};
