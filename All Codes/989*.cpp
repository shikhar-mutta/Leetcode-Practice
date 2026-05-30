// Link: https://leetcode.com/problems/add-to-array-form-of-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> result; // Create a result vector to store the sum of the array form of the integer and k
        int carry = 0;
        int i = num.size() - 1; // Initialize a pointer to the last element of the num vector

        while (i >= 0 || k > 0 || carry > 0) // Iterate through the num vector and k until we have processed all digits and any remaining carry
        {
            int sum = carry; // Initialize the sum with the carry from the previous iteration

            if (i >= 0) // If there are still digits in the num vector to process, add the current digit to the sum and move the pointer to the left
            {
                sum += num[i]; // Add the current digit to the sum
                i--;
            }

            if (k > 0) // If there are still digits in k to process, add the last digit of k to the sum and remove it from k
            {
                sum += k % 10; // Add the last digit of k to the sum
                k /= 10;
            }

            result.push_back(sum % 10); // Add the last digit of the sum to the result vector
            carry = sum / 10;           // Update the carry for the next iteration
        }

        reverse(result.begin(), result.end()); // Reverse the result vector to get the correct order of digits
        return result;                         // Return the result vector containing the sum of the array form of the integer and k
    }
};
