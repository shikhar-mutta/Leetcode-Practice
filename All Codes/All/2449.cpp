// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(NlogN), SC: O(1)
// Approach: Sort both arrays. For each odd number in nums, find the corresponding odd number in target and add the difference/2 to ops. Do the same for even numbers. Return ops/2.
// Note: We divide by 2 at the end because each operation can change two numbers (one in nums and one in target).
class Solution
{
public:
    long long makeSimilar(vector<int> &nums, vector<int> &target)
    {
        int n = nums.size();
        int odd = 0;
        int even = 0;
        long long ops = 0;
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        for (int &i : nums)
        {
            if (i % 2)
            {
                while (target[odd] % 2 == 0)
                {
                    odd++;
                }
                ops += abs(target[odd] - i) / 2;
                odd++;
            }
            else
            {
                while (target[even] % 2)
                {
                    even++;
                }
                ops += abs(target[even] - i) / 2;
                even++;
            }
        }
        return ops / 2;
    }
};