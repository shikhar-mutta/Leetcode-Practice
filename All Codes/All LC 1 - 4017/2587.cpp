// Link: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n)
    // SC: O(n)
    //   Approach:
    //   1. Count the number of positive, negative and zero elements in the array
    //   2. If there are positive elements, we can include all of them in the prefix score, and we can also include all zero elements, as they do not affect the prefix score.
    //   3. If there are no positive elements, we cannot include any negative elements, as they will decrease the prefix score. In this case, we return 0.
    //   4. If there are positive elements, we can include negative elements in the prefix score, but we need to be careful. We can include negative elements only if the sum of the prefix score is still positive after including them. We can sort the negative elements in ascending order and include them one by one, checking if the sum of the prefix score is still positive after including each negative element. If the sum becomes non-positive, we stop including negative elements and return the count of positive and zero elements included in the prefix score.
    //   5. Return the count of positive and zero elements included in the prefix score, plus the count of negative elements included in the prefix score.
    int maxScore(vector<int> &v)
    {
        vector<int> mi;
        long long n = v.size(), c = 0, s = 0, z = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > 0)
            {
                c++;
                s += v[i];
            }
            else if (v[i] == 0)
                z++;
            else
                mi.push_back(v[i]);
        }
        if (c > 0)
            c += z;
        else
            return 0;
        if (c == n)
            return n;
        sort(mi.begin(), mi.end());
        for (int i = mi.size() - 1; i >= 0; i--)
        {
            if (s + mi[i] <= 0)
                return c;
            else
            {
                s += mi[i];
                c++;
            }
        }
        return c;
    }
};
