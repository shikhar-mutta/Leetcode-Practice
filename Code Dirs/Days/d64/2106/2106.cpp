// Link: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: prefix sums over fruit amounts. Two-pointer sliding window over
// the position range [left,right]; cost to cover a window depends on going
// right-then-left or left-then-right, taking the cheaper: min(2*(startPos-left)+(right-startPos), 2*(right-startPos)+(startPos-left)). Shrink from the left while cost exceeds k.
class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + fruits[i][1];

        int left = 0, best = 0;
        for (int right = 0; right < n; right++)
        {
            while (left <= right)
            {
                int l = fruits[left][0], r = fruits[right][0];
                long long distLeft = max(0, startPos - l);
                long long distRight = max(0, r - startPos);
                long long cost = min(2 * distLeft + distRight, 2 * distRight + distLeft);
                if (cost <= k)
                    break;
                left++;
            }
            long long sum = prefix[right + 1] - prefix[left];
            best = max(best, (int)sum);
        }
        return best;
    }
};
