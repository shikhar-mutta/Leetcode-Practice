// Link: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> comp;
        for (int x : nums) {
            if (comp.empty() || comp.back() != x) comp.push_back(x);
        }
        int count = 0;
        for (int i = 1; i + 1 < (int)comp.size(); i++) {
            if ((comp[i] > comp[i-1] && comp[i] > comp[i+1]) ||
                (comp[i] < comp[i-1] && comp[i] < comp[i+1])) count++;
        }
        return count;
    }
};
