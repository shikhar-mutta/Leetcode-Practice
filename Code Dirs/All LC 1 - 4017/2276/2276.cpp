// Link: https://leetcode.com/problems/count-integers-in-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class CountIntervals {
    map<int,int> mp; // start -> end
    long long total = 0;
public:
    CountIntervals() {}

    void add(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it != mp.begin()) {
            auto pv = prev(it);
            if (pv->second >= left - 1) {
                it = pv;
                left = min(left, it->first);
                right = max(right, it->second);
            }
        }
        while (it != mp.end() && it->first <= right + 1) {
            right = max(right, it->second);
            total -= (it->second - it->first + 1);
            it = mp.erase(it);
        }
        mp[left] = right;
        total += (right - left + 1);
    }

    int count() {
        return (int)total;
    }
};
