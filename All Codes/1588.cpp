// Link: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size(), sum = 0;
        for (int i = 1; i <= n; i += 2)
        {
            int win = 0;
            for (int j = 0; j < i; j++) // get the sum of first window
                win += arr[j];
            sum += win;
            for (int j = i; j < n; j++) // slide the window and update the sum
            {
                win += arr[j] - arr[j - i];
                sum += win; // add the sum of current window to the answer
            }
        }
        return sum;
    }
};
