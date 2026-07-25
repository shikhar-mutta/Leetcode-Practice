// Link: https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n)
//  Approach:
//    1. We can use a greedy approach to find the k-th smallest number by generating the next permutation of the digits k times.
//    2. We can then use a two-pointer approach to find the minimum number of adjacent swaps needed to transform the original number into the k-th smallest number.
//    3. We can iterate through the digits of the original number and the k-th smallest number, and for each digit in the original number, we can find the corresponding digit in the k-th smallest number and count the number of adjacent swaps needed to move that digit to the correct position.
//    4. We can keep track of the total number of swaps needed and return it as the answer.
class Solution
{
public:
    int getMinSwapsTwoLists(std::vector<int> &source,
                            std::vector<int> &target)
    {
        int answer = 0;
        int slow = 0;
        int fast = 0;
        int sourceLength = source.size();
        while (slow < sourceLength)
        {
            while (source[fast] != target[slow])
            {
                ++fast;
            }
            for (int i = fast; i > slow; --i)
            {
                int prev = source[i - 1];
                source[i - 1] = source[i];
                source[i] = prev;
            }
            answer += (fast - slow);
            ++slow;
            fast = slow;
        }
        return answer;
    }
    int getMinSwaps(string num, int k)
    {
        std::vector<int> digits;
        for (char digit : num)
        {
            digits.push_back(digit - '0');
        }
        std::vector<int> final = digits;
        int target = 0;
        std::vector<int> frequencies(10, 0);
        int permutations = 1;
        int end = final.size();
        int fast = final.size() - 1;
        ++frequencies[final[fast]];
        while (target < k)
        {
            int currentDigit = final[fast];
            int previousDigit = final[fast - 1];
            while (currentDigit <= previousDigit)
            {
                ++frequencies[previousDigit];
                --fast;
                permutations = static_cast<int>((permutations * (end - fast)) /
                                                frequencies[previousDigit]);
                currentDigit = previousDigit;
                previousDigit = final[fast - 1];
            }
            int offset = 0;
            for (int i = 0; i <= previousDigit; ++i)
            {
                offset += frequencies[i];
            }
            final[fast - 1] = final[end - offset - 1];

            --frequencies[final[end - offset - 1]];
            int numerator = 1 + frequencies[final[end - offset - 1]];
            final[end - offset - 1] = previousDigit;
            ++frequencies[final[end - offset - 1]];
            int denominator = frequencies[final[end - offset - 1]];
            permutations =
                static_cast<int>((permutations * numerator) / denominator);
            target += permutations;
        }
        while (fast <
               end)
        { // now we need to swap. We know the fast - 1 from before
            permutations = static_cast<int>(
                (permutations * frequencies[final[fast]]) / (end - fast));
            while (target - permutations >= k)
            {
                target -= permutations;
                int offset = 0;
                for (int i = 0; i < final[fast]; ++i)
                {
                    offset += frequencies[i];
                }
                int numerator = frequencies[final[end - offset]];
                int denominator = frequencies[final[fast]];
                permutations =
                    static_cast<int>((permutations * numerator) / denominator);
                int switched = final[end - offset];
                final[end - offset] = final[fast];
                final[fast] = switched;
            }
            --frequencies[final[fast]];
            if (target == k)
            {
                break;
            }
            ++fast;
        }
        return getMinSwapsTwoLists(digits, final);
    }
};
