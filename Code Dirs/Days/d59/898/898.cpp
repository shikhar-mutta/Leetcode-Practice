// Link: https://leetcode.com/problems/bitwise-ors-of-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) in worst case, where n is the size of the input array A.
// SC: O(n*32) in worst case, where n is the size of the input array A.
// Approach:
//     1. We iterate through the input array A and for each element, we calculate the bitwise OR of all subarrays ending at that element. We maintain a vector result to store the bitwise OR results of all subarrays.
//     2. For each element A[i], we initialize two variables: withoutcurr to store the bitwise OR of the subarray without the current   element, and withcurr to store the bitwise OR of the subarray with the current element. We start by adding the current element A[i] to the result vector.
//     3. We then iterate backwards through the array from index i-1 to 0, updating withoutcurr and withcurr at each step. If withoutcurr becomes equal to withcurr, we break out of the loop since further iterations will not yield new results. Otherwise, we add withcurr to the result vector.
//     4. After processing all elements, we sort the result vector and count the number of unique elements to get the final answer.
class Solution
{
public:
    int subarrayBitwiseORs(const vector<int> &A)
    {
        vector<unsigned int> result;
        const size_t n = A.size();
        result.reserve(n * 32);
        /* subarray= Array ending at element 'i' for 0<= i< n;
       Hence number of Subarrays = A.size;
       Max distinct ORs for each subarray =32 (32 bit ints).
       hence max possible size of result vector = A.size()*32 */

        result.push_back(A[0]);
        for (size_t i = 1; i < n; ++i)
        {
            const unsigned curr = A[i];
            unsigned withoutcurr = 0, withcurr = curr;
            result.push_back(curr);
            for (size_t j = i; j-- > 0;)
            {
                /*using this method in reverse loop to use size_t while avoiding underflow risks */
                withoutcurr |= A[j];
                withcurr = withoutcurr | curr;
                if (withoutcurr == withcurr)
                {
                    break;
                }
                result.push_back(withcurr);
            }
        }

        /*counting only unique elements from the result vector*/
        std::sort(result.begin(), result.end());
        unsigned int ans = 1;
        for (size_t k = 1; k < result.size(); k++)
        {
            if (result[k] != result[k - 1])
            {
                ans++;
            }
        }
        return ans;
    }
};

/*How is this Better than generic solutions
1. Uses Contiguous and fast vectors instead of hash table based sets
2.relies on monotonically increasing property of ORs instead of sets for duplicate checking
3.prevents deep copies
4. passes orignal vector A by reference instead of by value
5. pre-reserves space for vectors to prevent dynamic allocation overhead
6. replacing heap fragmentation with contiguous memory and no destructor calling for elements*/