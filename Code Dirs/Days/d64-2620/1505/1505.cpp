// Link: https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(n)
//  Approach: We can use a Fenwick Tree (Binary Indexed Tree) to keep track of the number of digits that have been used. We can iterate through the digits and for each digit, we can check if there is any digit that is smaller than the current digit and can be swapped with it. If there is, we can swap the digits and update the Fenwick Tree. Finally, we can return the minimum possible integer.
class Solution
{
public:
    vector<int> bit;
    int n;

    void update(int i)
    {
        for (++i; i <= n; i += i & (-i))
        {
            bit[i]++;
        }
    }
    int query(int i)
    {
        int sum = 0;
        for (++i; i > 0; i -= i & (-i))
        {
            sum += bit[i];
        }
        return sum;
    }
    string minInteger(string num, int k)
    {
        n = num.size();
        bit.assign(n + 1, 0);

        // Group original indices by digit value
        vector<queue<int>> digitPositions(10);
        for (int i = 0; i < n; i++)
        {
            digitPositions[num[i] - '0'].push(i);
        }

        string result;
        result.reserve(n);

        for (int pos = 0; pos < n; pos++)
        {
            if (k <= 0)
            {
                int bestDigit = -1;
                int bestIdx = INT_MAX;
                for (int d = 0; d <= 9; d++)
                {
                    if (!digitPositions[d].empty() &&
                        digitPositions[d].front() < bestIdx)
                    {
                        bestIdx = digitPositions[d].front();
                        bestDigit = d;
                    }
                }
                result += ('0' + bestDigit);
                digitPositions[bestDigit].pop();
                update(bestIdx); // mark as used (though not strictly needed now
                                 // since k=0)
                continue;
            }

            for (int d = 0; d <= 9; d++)
            {
                if (digitPositions[d].empty())
                    continue;

                int idx = digitPositions[d].front();

                int usedBefore = query(idx - 1);
                int actualDistance = idx - usedBefore;
                if (actualDistance <= k)
                {
                    k -= actualDistance;
                    result += ('0' + d);
                    digitPositions[d].pop();
                    update(idx);
                    break;
                }
            }
        }

        return result;
    }
};