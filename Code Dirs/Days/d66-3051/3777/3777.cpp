// Link: https://leetcode.com/problems/minimum-deletions-to-make-alternating-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q log n)  SC: O(n)
//  Approach: We can use a Fenwick tree (also known as a Binary Indexed Tree) to efficiently keep track of the number of adjacent characters that are the same in the string. We can initialize the Fenwick tree with the number of adjacent characters that are the same in the string. For each query, we can update the Fenwick tree if the query is of type 1 (i.e., change the character at index i) and we can query the Fenwick tree to get the number of adjacent characters that are the same in the substring from index i to j if the query is of type 2 (i.e., get the number of adjacent characters that are the same in the substring from index i to j). The answer to the query of type 2 will be the length of the substring minus the number of adjacent characters that are the same in the substring.
int ft[100000], N;

void update(int i, int x)
{
    for (; i < N; i |= i + 1)
        ft[i] += x;
}

int eval(int i)
{
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        res += ft[i];
    return res;
}

class Solution
{
public:
    vector<int> minDeletions(string s, vector<vector<int>> &queries)
    {
        int N = size(s);
        ::N = N;
        for (int i = 1; i < N; ++i)
            ft[i] = (s[i] - s[i - 1]) & 1;
        for (int i = 1; i < N; ++i)
            if (int j = i | (i + 1); j < N)
                ft[j] += ft[i];

        vector<int> res;
        for (const auto &q : queries)
        {
            int i = q[1];
            if (q[0] == 1)
            {
                s[i] = s[i] ^ 1;
                if (i)
                    update(i, 2 * ((s[i] - s[i - 1]) & 1) - 1);
                update(i + 1, 2 * ((s[i] - s[i + 1]) & 1) - 1);
            }
            else
            {
                int j = q[2];
                int d = eval(j) - eval(i);
                res.push_back(j - i - d);
            }
        }
        return res;
    }
};