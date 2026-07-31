// Link: https://leetcode.com/problems/create-sorted-array-through-instructions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
//  Approach: We can use a Binary Indexed Tree (BIT) to efficiently count the number of elements less than and greater than the current element as we iterate through the input array. The BIT allows us to perform prefix sum queries and updates in logarithmic time. For each element, we query the BIT to find the number of elements less than the current element (left) and the number of elements greater than the current element (right). The cost for each element is the minimum of these two counts. We then update the BIT to include the current element. Finally, we return the total cost modulo 10^9 + 7.
class BIT
{
public:
    BIT(int n) : n(n + 1) { bit.resize(this->n); }

    int query(int idx)
    {
        ++idx;
        int res = 0;
        while (idx > 0)
        {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    void update(int idx, int diff)
    {
        ++idx;
        while (idx < n)
        {
            bit[idx] += diff;
            idx += idx & -idx;
        }
    }

private:
    int n;
    vector<int> bit;
};

class Solution
{
public:
    int createSortedArray(vector<int> &A)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        const int M = 1000000007;
        int cost = 0;
        const int max = *std::max_element(begin(A), end(A));
        BIT bit(max + 1);

        for (auto num : A)
        {
            int left = bit.query(num - 1);
            int right = bit.query(max) - bit.query(num);

            cost += std::min(left, right);
            cost %= M;

            bit.update(num, 1);
        }

        return cost;
    }
};
