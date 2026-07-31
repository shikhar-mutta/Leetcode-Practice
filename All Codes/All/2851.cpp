// Link: https://leetcode.com/problems/string-transformation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q * 26), SC: O(n * 26)
// Approach: We can use a depth-first search (DFS) to traverse the tree and keep track of the number of times each character appears in the path from the root to the current node. We can also keep track of the depth of each node and the parent of each node. Then, for each query, we can find the lowest common ancestor (LCA) of the two nodes in the query and calculate the number of times each character appears in the path from the root to both nodes, subtracting the counts from the LCA. The answer for each query will be the total number of characters in both paths minus the maximum count of any character in both paths.
class Solution
{
public:
    static const int mod = 1e9 + 7;
    // kmp algo will return the no of matches target will have in s
    int Kmp(string thread, string needle)
    {
        // first build the lps array from needle string
        int ns = needle.size();
        int ts = thread.size();
        vector<int> lps(ns, 0);
        // build the longest prefix which is also a suffix
        int f = 1, b = 0;
        while (f < ns)
        {
            if (needle[f] == needle[b])
            {
                // there is a match with suffix and prefix -> so prefix length will be increased
                lps[f++] = ++b;
            }
            else
            {
                if (b != 0)
                {
                    b = lps[b - 1];
                }
                else
                {
                    b = 0;
                    f++;
                }
            }
        }
        // now match with the thread
        int i = 0, j = 0;
        int count = 0;
        while (i < ts && j < ns)
        {
            if (thread[i] == needle[j])
            {
                i++;
                j++;
                if (j == ns)
                {
                    // there is a match
                    j = lps[j - 1];
                    if (i < ts)
                        count++;
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    j = 0;
                    i++;
                }
            }
        }

        return count;
    }
    // code for matrix expo
    struct Matrix
    {
        int a[2][2] = {{0, 0}, {0, 0}};
        Matrix operator*(const Matrix &other)
        {
            Matrix prod;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        prod.a[i][k] = (prod.a[i][k] + (long long)a[i][j] * other.a[j][k]) % mod;
                    }
                }
            }
            return prod;
        }
    };

    Matrix expo_matrix(Matrix base, long long k)
    {
        Matrix res;
        for (int i = 0; i < 2; i++)
        {
            res.a[i][i] = 1;
        }
        while (k > 0)
        {
            if (k % 2)
            {
                res = res * base;
            }
            base = base * base;
            k = k / 2;
        }
        return res;
    }

    int numberOfWays(string s, string t, long long k)
    {
        string ss = s + s;

        int good = Kmp(ss, t);
        cout << good << endl;
        int bad = t.size() - good;

        Matrix base;
        base.a[0][0] = good - 1;
        base.a[0][1] = good;
        base.a[1][0] = bad;
        base.a[1][1] = bad - 1;
        Matrix res = expo_matrix(base, k);
        if (s == t)
            return res.a[0][0];
        else
            return res.a[0][1];
    }
};
