// Link: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int mn = *min_element(salary.begin(), salary.end());
        int mx = *max_element(salary.begin(), salary.end());
        double sum = 0;
        for (int x : salary) sum += x;
        sum -= mn + mx;
        return sum / (salary.size() - 2);
    }
};
