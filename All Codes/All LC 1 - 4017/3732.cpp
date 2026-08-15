// Link: https://leetcode.com/problems/maximum-product-of-three-elements-after-one-replacement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    //  Approach:
    //  1. We can find the maximum product of three elements by finding the two largest and two smallest elements in the array.
    //  2. The maximum product of three elements can be obtained by either multiplying the two largest elements with the largest element or multiplying the two smallest elements with the largest element.
    //  3. We can also consider the maximum and minimum values in the array to handle the case where the maximum product can be obtained by replacing one of the elements with the maximum or minimum value in the array.
    //  4. We can iterate through the array and keep track of the two largest and two smallest elements, as well as the maximum and minimum values in the array. We can then calculate the maximum product of three elements after one replacement by considering the two largest and two smallest elements, as well as the maximum and minimum values in the array.
    //  5. Finally, we can return the maximum product of three elements after one replacement.
    long long maxProduct(vector<int> &nums)
    {
        const int n = static_cast<int>(nums.size());
        long long int largest = max(nums[0], nums[1]);
        long long int second_largest = min(nums[0], nums[1]);
        long long int smallest = min(nums[0], nums[1]);
        long long int second_smallest = max(nums[0], nums[1]);
        const long long int max_val = 1e5;
        const long long int min_val = -1e5;
        long long int max_three_product = LLONG_MIN;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] >= largest)
            {
                second_largest = largest;
                largest = nums[i];
            }
            else if (nums[i] >= second_largest)
            {
                second_largest = nums[i];
            }
            if (nums[i] <= smallest)
            {
                second_smallest = smallest;
                smallest = nums[i];
            }
            else if (nums[i] <= second_smallest)
            {
                second_smallest = nums[i];
            }
            const long long int max_two_product = max(largest * second_largest, smallest * second_smallest);
            const long long int min_two_product = min(smallest * second_smallest, largest * smallest);
            max_three_product = max(max(max_val * max_two_product, min_val * min_two_product), max_three_product);
        }
        return max_three_product;
    }
};
