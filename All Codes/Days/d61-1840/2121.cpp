// Link: https://leetcode.com/problems/intervals-between-identical-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the number of elements in the array.
// SC: O(n), where n is the number of elements in the array.
// Approach:
//  1. We use a 2D array total to store the sum of indices and the count of occurrences for each unique element in the input array arr. The first column of total stores the sum of indices for each unique element, and the second column stores the count of occurrences for each unique element.
//  2. We initialize the total array to zero using the reset function.
//  3. We iterate through the input array arr and for each element, we update the total array with the current index and increment the count of occurrences for that element. We also calculate the contribution of the current element to the result array res using the formula: res[i] = -2 * total[k][0] + 2 * total[k][1] * i, where k is the current element and i is the current index. This formula calculates the sum of distances from the current index to all previous occurrences of the same element.
//  4. After processing all elements, we iterate through the input array arr again and for each element, we add the contribution of all subsequent occurrences of the same element to the result array res using the formula: res[i] += total[k][0] - total[k][1] * i. This formula calculates the sum of distances from the current index to all subsequent occurrences of the same element.
//  5. Finally, we return the result array res, which contains the sum of distances for each element in the input array arr.
long long total[100001][2]; // sum , n
void reset()
{
    for (int i = 0; i < 100001; i++)
    {
        total[i][0] = total[i][1] = 0;
    }
}

class Solution
{
public:
    vector<long long> getDistances(vector<int> &arr)
    {
        int n = arr.size();
        vector<long long> res(n);
        reset();
        for (int i = 0; i < n; i++)
        {
            int k = arr[i];
            total[k][0] += i;
            total[k][1]++;
            res[i] = -2 * total[k][0] + 2 * total[k][1] * i;
        }

        for (int i = 0; i < n; i++)
        {
            int k = arr[i];
            res[i] += total[k][0] - total[k][1] * i;
        }
        return res;
    }
};