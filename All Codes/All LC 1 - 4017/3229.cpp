// Link: https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: We can use a greedy approach to solve this problem. We will iterate through the nums and target arrays and calculate the difference between the corresponding elements. We will keep track of the previous difference and the current difference. If the previous difference and the current difference have different signs, we will add the absolute value of the current difference to the answer. If they have the same sign, we will add the maximum of the absolute values of the previous and current differences to the answer. Finally, we will return the answer as the minimum number of operations required to make the nums array equal to the target array.
class Solution
{
public:
    long long minimumOperations(vector<int> &nums, vector<int> &target)
    {
        auto view{views::zip(nums, target) | views::drop(1) |
                  views::transform([](const auto &t) -> int64_t
                                   { return get<1>(t) - get<0>(t); })};

        int64_t prev{target[0] - nums[0]};
        int64_t ans{abs(prev)};
        for (const auto curr : view)
        {
            ans +=
                (prev * curr < 0) ? abs(curr) : max(abs(curr) - abs(prev), 0L);
            prev = curr;
        }
        return ans;
    }
};