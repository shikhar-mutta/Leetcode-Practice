// Link: https://leetcode.com/problems/count-prime-gap-balanced-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n) SC: O(n)
// Approach: Sliding window with monotonic queues. Maintain a window of prime numbers, and for each new prime number, check if the difference between the maximum and minimum prime numbers in the window exceeds k. If it does, shrink the window from the left until the condition is satisfied. Count the number of valid subarrays by calculating the number of subarrays that can be formed with the current window.
// Use monotonic queues to efficiently track the minimum and maximum prime numbers in the current window. The minQ maintains the indices of the minimum prime numbers, while the maxQ maintains the indices of the maximum prime numbers. The idx array stores the indices of prime numbers in the original array, allowing for efficient access to their values.
class Solution
{
public:
    int primeSubarray(vector<int> &nums, int k)
    {
        const auto n{nums.size()};
        array<size_t, 50000> minQ;
        array<size_t, 50000> maxQ;
        array<size_t, 50002> idx;
        size_t mnFront{0};
        size_t mnBack{0};
        size_t mxFront{0};
        size_t mxBack{0};
        size_t zelmoricad{0};
        idx[zelmoricad++] = ~0UL;
        for (size_t i{0}; i < n; ++i)
        {
            if (!isPrime[nums[i]])
                continue;

            idx[zelmoricad++] = i;
        }
        idx[zelmoricad] = n;
        int ans{0};
        for (size_t l{0}, r{1}; r < zelmoricad; ++r)
        {
            const auto num{nums[idx[r]]};
            while (mnFront < mnBack && nums[idx[minQ[mnBack - 1]]] > num)
            {
                --mnBack;
            }
            minQ[mnBack++] = r;
            while (mxFront < mxBack && nums[idx[maxQ[mxBack - 1]]] < num)
            {
                --mxBack;
            }
            maxQ[mxBack++] = r;
            while (l + 1 < r &&
                   nums[idx[maxQ[mxFront]]] - nums[idx[minQ[mnFront]]] > k)
            {
                ++l;
                if (minQ[mnFront] == l)
                    ++mnFront;

                if (maxQ[mxFront] == l)
                    ++mxFront;
            }
            if (l + 1 < r)
                ans += (idx[r - 1] - idx[l]) * (idx[r + 1] - idx[r]);
        }
        return ans;
    }

private:
    static constexpr auto isPrime{[]()
                                  {
                                      static constexpr size_t N{50001};
                                      array<bool, N> isPrime;
                                      fill(isPrime.begin(), isPrime.end(), true);
                                      isPrime[1] = false;
                                      for (size_t k{2}; k < N; ++k)
                                      {
                                          if (!isPrime[k])
                                              continue;

                                          for (size_t i{k * k}; i < N; i += k)
                                          {
                                              isPrime[i] = false;
                                          }
                                      }
                                      return isPrime;
                                  }()};
};