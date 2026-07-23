// Link: https://leetcode.com/problems/fruit-into-baskets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the number of fruits. We iterate through the fruits array once, and each fruit is processed in constant time.
    // SC: O(1), since we only use a fixed amount of extra space for the basket array and a few integer variables, regardless of the input size.
    // Approach:
    //    1. We use a sliding window approach to keep track of the current subarray of fruits that can be collected in the two baskets. We maintain two pointers, left and right, to represent the current window of fruits.
    //    2. We use a basket array of size 2 to store the types of fruits currently in the baskets. We initialize both baskets to -1, indicating that they are empty.
    //    3. We iterate through the fruits array using the right pointer. For each fruit, we check if it can be added to one of the baskets. If it can, we expand the window by moving the right pointer. If it cannot, we update the left pointer to the position of the last fruit type that was added to the baskets, effectively shrinking the window from the left until we can add the new fruit type to one of the baskets.
    //    4. We keep track of the maximum length of the window (subarray) that can be collected in the two baskets and return it as the result.
    int totalFruit(vector<int> &fruits)
    {
        vector<int> basket(2, -1);
        int n = fruits.size();
        int left = 0, right = 0;
        int len = 0;
        int max_len = 1;
        while (left < n && right < n)
        {
            len = right - left;
            while (right < n)
            {
                if (basket[0] == -1)
                {
                    basket[0] = fruits[right];
                }
                else if (fruits[right] != basket[0] && basket[1] == -1)
                {
                    basket[1] = fruits[right];
                }
                else if (fruits[right] == basket[0] || fruits[right] == basket[1])
                    ;
                else
                {
                    basket[1] = fruits[right];
                    basket[0] = fruits[right - 1];
                    break;
                }
                if (fruits[right] != fruits[left])
                    left = right;
                right++;
                len++;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
