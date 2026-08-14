// Link: https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> arr(n, 0);
        int count = 0;
        vector<int> ans;
        for (auto &q : queries) {
            int idx = q[0], color = q[1];

            if (arr[idx] != 0) {
                if (idx > 0 && arr[idx-1] == arr[idx]) count--;
                if (idx < n-1 && arr[idx+1] == arr[idx]) count--;
            }

            arr[idx] = color;

            if (idx > 0 && arr[idx-1] == arr[idx]) count++;
            if (idx < n-1 && arr[idx+1] == arr[idx]) count++;

            ans.push_back(count);
        }
        return ans;
    }
};
