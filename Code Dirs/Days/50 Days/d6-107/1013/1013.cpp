// Link: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int total = accumulate(arr.begin(), arr.end(), 0); // calculate the total sum of the array
        // if the total sum is not divisible by 3, we cannot partition it into three equal parts
        if (total % 3 != 0)
            return false;
        // we need to find three parts with equal sum, which is total / 3
        int target = total / 3, sum = 0, parts = 0;
        // iterate through the array and keep adding elements to the sum
        for (int x : arr)
        {
            sum += x;
            // if the sum equals the target, we found one part, so we increment the parts count
            if (sum == target * (parts + 1))
                parts++;
            if (parts == 3)
                return true;
        }
        return false;
    }
};
