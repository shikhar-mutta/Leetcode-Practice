// Link: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach: We can use a recursive approach to solve this problem. We can create a binary search tree (BST) from the given array and then count the number of ways to reorder the array to get the same BST. We can use a depth-first search (DFS) approach to traverse the BST and count the number of ways to reorder the left and right subtrees. We can use combinatorics to calculate the number of ways to combine the left and right subtrees. Finally, we return the total number of ways modulo 10^9 + 7.

static const int MOD = 1e9 + 7;
static vector<int> factorial;

class Solution
{
public:
    Solution()
    {
        if (!factorial.empty())
            return;
        factorial.resize(1001);

        factorial.front() = 1;
        for (int i = 1; i <= 1000; i++)
            factorial[i] = multiplication(factorial[i - 1], i);
    }

    int numOfWays(vector<int> &nums)
    {
        const int n = nums.size();
        edges.resize(n + 1);

        for (int i : nums)
        {
            int x = 0;

            while (true)
            {
                if (x < i)
                {
                    if (!edges[x].second)
                    {
                        edges[x].second = i;
                        break;
                    }
                    x = edges[x].second;
                }
                else
                {
                    if (!edges[x].first)
                    {
                        edges[x].first = i;
                        break;
                    }
                    x = edges[x].first;
                }
            }
        }
        return DFS(edges[0].second).first - 1;
    }

protected:
    int multiplication(const long long x, const long long y)
    {
        return x * y % MOD;
    }

    int power(long long x, long long y)
    {
        long long res = 1;
        x %= MOD;

        while (y)
        {
            if (y & 1)
                res = multiplication(res, x);
            x = multiplication(x, x);
            y >>= 1;
        }
        return res;
    }

    int modularInverse(long long a) { return power(a, MOD - 2); }

    int division(long long a, long long b)
    {
        return (a * modularInverse(b)) % MOD;
    }

    int NCR(const int n, const int r)
    {
        return division(factorial[n],
                        multiplication(factorial[r], factorial[n - r]));
    }

private:
    vector<pair<int, int>> edges;

    pair<int, int> DFS(int node)
    {
        if (!node)
            return {1, 0};
        pair<int, int> ans, left = DFS(edges[node].first),
                            right = DFS(edges[node].second);
        ans.second = 1 + left.second + right.second;
        ans.first = multiplication(left.first, right.first);
        ans.first = multiplication(
            ans.first, NCR(left.second + right.second, left.second));

        return ans;
    }
};