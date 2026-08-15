// Link: https://leetcode.com/problems/number-of-employees-who-met-the-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;
        for (int h : hours) if (h >= target) count++;
        return count;
    }
};
