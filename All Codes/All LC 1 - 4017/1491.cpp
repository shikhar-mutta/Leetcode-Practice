// Link: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        // Find the minimum and maximum salary, and calculate the sum of all salaries.
        int minSal = INT_MAX, maxSal = INT_MIN, sum = 0;
        for (int i = 0; i < salary.size(); i++)
        {
            minSal = min(minSal, salary[i]);
            maxSal = max(maxSal, salary[i]);
            sum += salary[i];
        }
        return (double)(sum - minSal - maxSal) / (salary.size() - 2);
    }
};
