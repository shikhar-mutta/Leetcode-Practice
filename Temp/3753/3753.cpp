// Link: https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(digits * 11 * 11 * 2 * 10)  SC: O(digits * 11 * 11 * 2)
//  Approach: answer = f(num2) - f(num1-1), where f(x) sums waviness (count of strict local peak/valley digits, excluding the first/last digit and any leading zeros) over [0,x] via digit DP. State = (position, previous digit, digit before that, still-in-leading-zeros, tight-to-bound); at each choice of next digit, credit the previous digit as a peak/valley (times the number of ways to complete the suffix) whenever it's a real middle digit strictly greater/less than both neighbors.
class Solution
{
    static vector<int> patterns;
    void create_patterns()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = i + 1; j < 10; j++)
            {
                for (int k = 0; k < j; k++)
                {
                    patterns.push_back(i * 100 + j * 10 + k);
                }
            }
            for (int j = 0; j < i; j++)
            {
                for (int k = j + 1; k < 10; k++)
                {
                    patterns.push_back(i * 100 + j * 10 + k);
                }
            }
        }
    }
    long long helper(long long num)
    {
        long long count = 0;
        int curr = num % 1000, last_d;
        long long prefix = num / 1000, suffix = 0, power = 1;
        while (!(prefix == 0 && curr < 100))
        {
            for (int p : patterns)
            {
                count += max(0ll, prefix + (curr > p) - (p < 100)) * power +
                         (curr == p) * (suffix + 1);
            }
            last_d = prefix % 10;
            suffix += (curr % 10) * power;
            curr = curr / 10 + last_d * 100;
            prefix = prefix / 10ll;
            power *= 10ll;
        }
        return count;
    }

public:
    Solution()
    {
        if (patterns.size() > 0)
            return;
        create_patterns();
        // cout << patterns.size() << endl;
    }
    long long totalWaviness(long long num1, long long num2)
    {
        // base pattern is len=3:
        // case 1:
        // 010, 020, 021 ...
        // case 2:
        // 121, 131, 132, ...
        // e.g. 1324
        // 132: (for < 132) (prefix=0 + 1 - type) * 10
        // 132: (for   132) (prefix=0 - type) * 10 + suffix+1
        // 132: (for > 132) (prefix=0 - type) * 10
        if (num2 < num1)
            return totalWaviness(num2, num1);
        return helper(num2) - helper(num1 - 1);
    }
};
vector<int> Solution::patterns;
