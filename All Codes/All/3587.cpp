// Link: https://leetcode.com/problems/minimum-adjacent-swaps-to-alternate-parity/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//   Approach: Use a frequency array to count occurrences of each value. For each middle element, calculate the number of valid triplets using the frequency array.
//  For the minimum adjacent swaps to alternate parity problem, we can count the number of odd and even elements in the array. If the counts are equal, we can try both starting with an odd or even element. If one count is greater by one, we must start with that parity. If the counts differ by more than one, it's impossible to alternate parities, and we return -1. The count function calculates the number of swaps needed to achieve the desired arrangement.
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        const auto &count = [&](int j)
        {
            int result = 0;
            for (int i = 0; i < size(nums); ++i)
            {
                if (nums[i] % 2)
                {
                    result += abs(j - i);
                    j += 2;
                }
            }
            return result;
        };

        const auto &cnt = accumulate(
            cbegin(nums), cend(nums), 0,
            [](const auto &accu, const auto &x)
            { return accu + x % 2; });
        if (cnt == size(nums) - cnt)
        {
            return min(count(0), count(1));
        }
        if (cnt == (size(nums) - cnt) + 1)
        {
            return count(0);
        }
        if (cnt + 1 == size(nums) - cnt)
        {
            return count(1);
        }
        return -1;
    }
};