// Link: https://leetcode.com/problems/product-of-the-last-k-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(n)
//  Approach:
//  1. We can use a prefix product array to store the product of all the numbers added so far.
//  2. When we add a new number, we can multiply it with the last product in the prefix array and push it to the back of the array.
//  3. When we want to get the product of the last k numbers, we can simply divide the last product in the prefix array by the product of the first (n-k) numbers in the prefix array, where n is the total number of numbers added so far. If k is greater than or equal to n, we return 0 since the product of any number with 0 is 0.
class ProductOfNumbers
{
    vector<int> prefix;

public:
    ProductOfNumbers() { prefix.push_back(1); }
    void add(int num)
    {
        if (num == 0)
            prefix = {1};
        else
            prefix.push_back(prefix.back() * num);
    }
    int getProduct(int k)
    {
        if (k >= (int)prefix.size())
            return 0;
        return prefix.back() / prefix[prefix.size() - 1 - k];
    }
};
