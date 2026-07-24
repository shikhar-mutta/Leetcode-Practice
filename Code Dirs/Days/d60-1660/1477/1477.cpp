// Link: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //  Approach:
    //  1. Initialize a variable ans to store the minimum sum of lengths of two non-overlapping sub-arrays with the target sum. Set it to a large value (1e9).
    //  2. Create a vector best of size n to store the minimum length of a sub-array with the target sum that ends at each index. Initialize all elements to a large value (1e9).
    //  3. Initialize two pointers l and r to represent the left and right boundaries of the current sub-array, and a variable sum to keep track of the sum of the current sub-array.
    //  4. Iterate through the array arr using the right pointer r.
    //  5. Add the current element arr[r] to the sum.
    //  6. While the sum is greater than the target, move the left pointer l to the right and subtract arr[l] from the sum.
    //  7. If the sum is equal to the target, calculate the length of the current sub-array (len = r - l + 1). If there is a valid sub-array ending before the current one (best[l - 1] != 1e9), update ans with the minimum of ans and the sum of the lengths of the two sub-arrays (len + best[l - 1]). Update best[r] with the minimum of best[r] and len.
    //  8. If r > 0, update best[r] with the minimum of best[r] and best[r - 1] to ensure that best[r] always contains the minimum length of a sub-array with the target sum that ends at or before index r.
    //  9. After iterating through the array, if ans is still equal to 1e9, return -1 to indicate that there are no two non-overlapping sub-arrays with the target sum. Otherwise, return ans.
    int minSumOfLengths(vector<int> &arr, int target)
    {
        int n = arr.size();
        int ans = 1e9;
        vector<int> best(n, 1e9);

        int sum = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            sum += arr[r];

            while (sum > target)
            {
                sum -= arr[l];
                l++;
            }
            if (sum == target)
            {
                int len = r - l + 1;
                if (l > 0 && best[l - 1] != 1e9)
                {
                    ans = min(ans, len + best[l - 1]);
                }
                best[r] = len;
            }
            if (r > 0)
            {
                best[r] = min(best[r - 1], best[r]);
            }
        }
        if (ans == 1e9)
            return -1;
        return ans;
    }
};