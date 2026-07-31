// Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: We can count the frequency of each character in the first half of the string. Then, we can use combinatorial counting to determine the k-th smallest palindromic rearrangement. We build the first half of the palindrome and then mirror it to form the complete palindrome. If k exceeds the number of possible palindromic arrangements, we return an empty string.
class Solution
{
public:
    std::string smallestPalindrome(std::string s, int k)
    {
        std::vector<int> count(26);

        for (int i = 0; i < std::size(s) / 2; ++i)
        {
            ++count[s[i] - 'a'];
        }

        int total = 0, counting = 1, remain = 0;
        int i;

        for (i = std::size(count) - 1; i >= 0; --i)
        {
            for (int c = 1; c <= count[i]; ++c)
            {
                ++total;
                counting = counting * total / c;
                if (counting >= k)
                {
                    remain = count[i] - c;
                    break;
                }
            }

            if (counting >= k)
            {
                break;
            }
        }

        if (counting < k)
        {
            return "";
        }

        std::string hasil(std::size(s), 0);
        int l = 0;

        for (int j = 0; j <= i; ++j)
        {
            const char x = 'a' + j;
            const int c = j != i ? count[j] : remain;

            for (int _ = 0; _ < c; ++_)
            {
                --count[j];
                hasil[l++] = x;
            }
        }

        while (total)
        {
            for (int j = i; j < std::size(count); ++j)
            {
                if (!count[j])
                {
                    continue;
                }

                const auto new_count =
                    static_cast<int64_t>(counting) * count[j] / total;

                if (new_count < k)
                {
                    k -= new_count;
                    continue;
                }

                counting = new_count;
                --count[j];
                --total;
                hasil[l++] = 'a' + j;
                break;
            }
        }

        if (std::size(s) % 2)
        {
            hasil[l++] = s[std::size(s) / 2];
        }

        for (int i = l - 1 - std::size(s) % 2; i >= 0; --i)
        {
            hasil[l++] = hasil[i];
        }
        return hasil;
    }
};