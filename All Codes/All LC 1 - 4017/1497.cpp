// Link: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(k)
    //    Approach:
    //    1. Create a vector cnt of size k to count the occurrences of each remainder when the elements of arr are divided by k.
    //    2. Iterate through each element x in arr, and increment the count of the corresponding remainder in cnt. The remainder is calculated as ((x % k) + k) % k to handle negative numbers correctly.
    //    3. Check if the count of elements with remainder 0 is even, as they can only be paired with each other.
    //    4. For each remainder r from 1 to k/2, check if the count of elements with remainder r is equal to the count of elements with remainder k - r. If they are not equal, return false as they cannot be paired.
    //    5. If all checks pass, return true, indicating that the array can be rearranged into pairs such that the sum of each pair is divisible by k.
    //    6. Special case: If r == k - r (which occurs when k is even), ensure that the count of elements with that remainder is even, as they can only be paired with each other.
    //    7. If all conditions are satisfied, return true.
    bool canArrange(vector<int> &arr, int k)
    {
        vector<int> cnt(k, 0);
        for (int x : arr)
            ++cnt[((x % k) + k) % k];
        if (cnt[0] % 2)
            return false;
        for (int r = 1; r <= k / 2; ++r)
        {
            if (r == k - r)
            {
                if (cnt[r] % 2)
                    return false;
            }
            else if (cnt[r] != cnt[k - r])
                return false;
        }
        return true;
    }
};
