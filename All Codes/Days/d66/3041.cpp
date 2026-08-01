// Link: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(1)
//  Approach: Sort the array and use two counters to track the maximum number of consecutive elements that can be selected after modification. The first counter (c1) tracks the number of consecutive elements that can be selected without modification, while the second counter (c2) tracks the number of consecutive elements that can be selected with modification. The maximum of the two counters is returned as the result.
class Solution
{
public:
    int maxSelectedElements(vector<int> &A)
    {
        sort(A.begin(), A.end());
        int pre = -10, res = 1, c1 = 1, c2 = 1;
        for (int &a : A)
        {
            if (a == pre)
            {
                c2 = c1 + 1;
            }
            else if (a == pre + 1)
            {
                c1++;
                c2++;
            }
            else if (a == pre + 2)
            {
                c1 = c2 + 1;
                c2 = 1;
            }
            else
            {
                c1 = c2 = 1;
            }
            res = max(res, max(c1, c2));
            pre = a;
        }
        return res;
    }
};