// Link: https://leetcode.com/problems/sum-of-unique-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }

        int sum = 0;
        for (const auto &[num, count] : freq)
        {
            if (count == 1)
            { //   If the count of the number is 1, it means it's unique
                sum += num;
            }
        }

        return sum;
    }
};
