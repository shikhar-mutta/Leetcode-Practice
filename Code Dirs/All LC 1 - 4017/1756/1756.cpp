// Link: https://leetcode.com/problems/design-most-recently-used-queue/description/

#include <bits/stdc++.h>
using namespace std;

class MRUQueue {
public:
    vector<int> data;

    MRUQueue(int n) {
        data.resize(n);
        iota(data.begin(), data.end(), 1);
    }

    int fetch(int k) {
        int val = data[k-1];
        data.erase(data.begin() + k - 1);
        data.push_back(val);
        return val;
    }
};
