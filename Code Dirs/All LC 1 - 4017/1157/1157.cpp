// Link: https://leetcode.com/problems/online-majority-element-in-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class MajorityChecker {
    vector<int> arr;
    unordered_map<int, vector<int>> positions;
public:
    MajorityChecker(vector<int>& arr_) : arr(arr_) {
        for (int i = 0; i < (int)arr.size(); i++) positions[arr[i]].push_back(i);
    }

    int query(int left, int right, int threshold) {
        srand(42);
        for (int attempt = 0; attempt < 20; attempt++) {
            int idx = left + rand() % (right - left + 1);
            int val = arr[idx];
            auto& pos = positions[val];
            int lo = lower_bound(pos.begin(), pos.end(), left) - pos.begin();
            int hi = upper_bound(pos.begin(), pos.end(), right) - pos.begin();
            if (hi - lo >= threshold) return val;
        }
        return -1;
    }
};
