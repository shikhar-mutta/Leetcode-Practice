// Link: https://leetcode.com/problems/combinations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k * C(n, k)) where C(n, k) is the number of combinations
// SC: O(k) for the temporary combination vector
// Approach:
// 1. Calculate the total number of combinations using the combination formula C(n, k)
// 2. Use a temporary vector to store the current combination.
// 3. Start with the first combination [1, 2, ..., k] and generate the next combination by incrementing the last element that can be incremented without exceeding n.
// 4. If the last element reaches its maximum value, move to the previous element and increment it, then reset all subsequent elements to the smallest possible values.
// 5. Repeat until all combinations are generated and stored in the result vector, which is then returned.

class Solution
{
private:
    int combinationNums(int n, int k)
    {
        long long res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) / (i + 1);
        }
        return (int)res;
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        result.reserve(combinationNums(n, k));

        vector<int> tmpCombination(k);
        for (int i = 0; i < k; i++)
        {
            tmpCombination[i] = i + 1;
        }

        while (true)
        {
            result.push_back(tmpCombination);
            int cur = k - 1;
            while (cur >= 0 && tmpCombination[cur] == n - k + 1 + cur)
                cur--;

            if (cur < 0)
                break;

            tmpCombination[cur]++;
            for (int i = cur + 1; i < k; i++)
            {
                tmpCombination[i] = tmpCombination[i - 1] + 1;
            }
        }

        return result;
    }
};