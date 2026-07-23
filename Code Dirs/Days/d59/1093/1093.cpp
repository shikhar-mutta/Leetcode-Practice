// Link: https://leetcode.com/problems/statistics-from-a-large-sample/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the size of the count array
    // SC: O(1)
    //  Approach:
    //   1. We will iterate through the count array and calculate the minimum, maximum, mean, median and mode of the sample.
    //   2. We will keep track of the total number of samples, the sum of the samples, the minimum and maximum values, and the mode and its count.
    //   3. We will calculate the mean by dividing the sum by the total number of samples.
    //   4. We will calculate the median by finding the middle value(s) of the sorted sample. If the total number of samples is odd, we will take the middle value. If it is even, we will take the average of the two middle values.
    //   5. Finally, we will return a vector containing the minimum, maximum, mean, median and mode of the sample.
    vector<double> sampleStats(vector<int> &count)
    {
        int n = count.size();
        long long total = 0;
        double sum = 0;
        int minVal = -1, maxVal = -1;
        int modeVal = 0;
        long long modeCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (count[i] > 0)
            {
                if (minVal == -1)
                    minVal = i;
                maxVal = i;
                sum += (double)i * count[i];
                total += count[i];
                if (count[i] > modeCount)
                {
                    modeCount = count[i];
                    modeVal = i;
                }
            }
        }
        double mean = sum / total;

        long long half1 = (total + 1) / 2;
        long long half2 = (total + 2) / 2;
        long long cum = 0;
        int val1 = -1, val2 = -1;
        for (int i = 0; i < n; i++)
        {
            cum += count[i];
            if (val1 == -1 && cum >= half1)
                val1 = i;
            if (val2 == -1 && cum >= half2)
                val2 = i;
            if (val1 != -1 && val2 != -1)
                break;
        }
        double median = (val1 + val2) / 2.0;

        return {(double)minVal, (double)maxVal, mean, median, (double)modeVal};
    }
};
