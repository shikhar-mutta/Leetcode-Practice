// Link: https://leetcode.com/problems/number-of-zigzag-arrays-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * (r - l + 1)) where n is the length of the array and r - l + 1 is the range of values that can be used in the array.
// SC: O(r - l + 1) where r - l + 1 is the range of values that can be used in the array.
// Approach:
// 1. We can use dynamic programming to solve this problem.
// 2. We can use a 1D array to store the number of zigzag arrays of length n that can be formed using the values in the range [l, r].
// 3. We can initialize the array with the number of zigzag arrays of length 1 and 2.
// 4. We can then iterate through the array and for each length, we can calculate the number of zigzag arrays that can be formed using the values in the range [l, r].
// 5. We can use the formula for the number of zigzag arrays of length n that can be formed using the values in the range [l, r] to calculate the number of zigzag arrays of length n that can be formed using the values in the range [l, r].
// 6. Finally, we can return the number of zigzag arrays of length n that can be formed using the values in the range [l, r] modulo 10^9 + 7.
class Solution
{
public:
    int zigZagArrays(int n, int l, int r)
    {
        static constexpr unsigned int modulo = 1000000007U;

        int value_count = r - l + 1;

        if (n == 1)
        {
            return value_count;
        }

        if (n == 2)
        {
            return value_count * (value_count - 1);
        }

        if (value_count == 2)
        {
            return 2;
        }

        if (n == 3)
        {
            return 1LL * value_count * (value_count - 1) *
                   (2 * value_count - 1) / 3 % modulo;
        }

        if (n == 4)
        {
            return 1LL * value_count * (value_count - 1) *
                   (5LL * value_count * value_count - 5LL * value_count + 2) /
                   12 % modulo;
        }

        if (n == 5)
        {
            return 1LL * value_count * (value_count - 1) *
                   (2 * value_count - 1) *
                   (2LL * value_count * value_count - 2LL * value_count + 1) /
                   15 % modulo;
        }

#if defined(__clang__)
        __builtin_assume(n >= 6);
        __builtin_assume(value_count >= 3);
        __builtin_assume(value_count <= 2000);
#endif

        alignas(64) unsigned int current_counts[2000];

        unsigned int total_count;
        int remaining_step_count;

        if (n & 1)
        {
            unsigned int initial_count = 0;

            for (int value_index = 1; value_index < value_count;
                 ++value_index)
            {
                initial_count += value_count - value_index;
                current_counts[value_index] = initial_count;
            }

            total_count = 1LL * value_count * (value_count - 1) *
                          (2 * value_count - 1) / 6 % modulo;
            remaining_step_count = (n - 3) >> 1;
        }
        else
        {
            for (int value_index = 1; value_index < value_count;
                 ++value_index)
            {
                current_counts[value_index] = value_index;
            }

            total_count = value_count * (value_count - 1) >> 1;
            remaining_step_count = (n - 2) >> 1;
        }

        while (remaining_step_count--)
        {
            unsigned int suffix_sum = total_count;
            unsigned int running_count = 0;
            unsigned int previous_count = 0;
            unsigned long long next_total_count = 0;

            for (int value_index = 1; value_index < value_count;
                 ++value_index)
            {
                unsigned int original_count = current_counts[value_index];

                suffix_sum += modulo - previous_count;

                if (suffix_sum >= modulo)
                {
                    suffix_sum -= modulo;
                }

                running_count += suffix_sum;

                if (running_count >= modulo)
                {
                    running_count -= modulo;
                }

                current_counts[value_index] = running_count;
                next_total_count += running_count;
                previous_count = original_count;
            }

            total_count = next_total_count % modulo;
        }

        unsigned int answer = total_count + total_count;

        if (answer >= modulo)
        {
            answer -= modulo;
        }

        return answer;
    }
};