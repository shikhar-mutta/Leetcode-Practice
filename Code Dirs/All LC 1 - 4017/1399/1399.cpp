// Link: https://leetcode.com/problems/count-largest-group/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> cnt;
        int maxCount = 0;
        for (int i = 1; i <= n; i++) {
            int s = 0, x = i;
            while (x) { s += x % 10; x /= 10; }
            cnt[s]++;
            maxCount = max(maxCount, cnt[s]);
        }
        int groups = 0;
        for (auto& [k, v] : cnt) if (v == maxCount) groups++;
        return groups;
    }
};
