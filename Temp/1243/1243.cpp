// Link: https://leetcode.com/problems/array-transformation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int n = arr.size();
        while (true) {
            vector<int> next = arr;
            bool changed = false;
            for (int i = 1; i < n - 1; i++) {
                if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) { next[i] = arr[i] - 1; changed = true; }
                else if (arr[i] < arr[i-1] && arr[i] < arr[i+1]) { next[i] = arr[i] + 1; changed = true; }
            }
            arr = next;
            if (!changed) break;
        }
        return arr;
    }
};
