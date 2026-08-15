// Link: https://leetcode.com/problems/three-equal-parts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int ones = 0;
        for (int x : arr) ones += x;
        if (ones == 0) return {0, n - 1};
        if (ones % 3 != 0) return {-1, -1};

        int k = ones / 3;
        vector<int> starts;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                cnt++;
                if (cnt == 1 || cnt == k + 1 || cnt == 2 * k + 1) starts.push_back(i);
            }
        }

        int len = n - starts[2];
        if (starts[0] + len > starts[1] || starts[1] + len > starts[2]) return {-1, -1};

        for (int i = 0; i < len; i++) {
            if (arr[starts[0] + i] != arr[starts[2] + i]) return {-1, -1};
            if (arr[starts[1] + i] != arr[starts[2] + i]) return {-1, -1};
        }
        return {starts[0] + len - 1, starts[1] + len};
    }
};
