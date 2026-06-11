// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log m). SC: O(1).
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            int count = 1, sum = 0;
            for (int weight : weights)
            {
                if (sum + weight > mid)
                    count++, sum = weight;
                else
                    sum += weight;
                if (count > days)
                    break;
            }
            if (count > days)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
