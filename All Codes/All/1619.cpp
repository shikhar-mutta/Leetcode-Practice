// Link: https://leetcode.com/problems/mean-of-array-after-removing-some-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double sum = 0; // Calculate the sum of the remaining elements
        // Remove the smallest 5% and the largest 5% of the elements
        for (int i = n / 20; i < n - n / 20; i++)
        {
            sum += arr[i];
        }
        return sum / (n - 2 * (n / 20)); // Return the mean of the remaining elements
    }
};
