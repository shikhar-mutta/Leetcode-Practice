// Link: https://leetcode.com/problems/palindrome-partitioning-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n^2)
// Approach: Palindromic Tree (Eertree) + Dynamic Programming
class Solution
{
public:
    struct Node
    {
        int len, link;
        int next[26];
        int diff, seriesLink;
        int seriesAns;
        Node(int l = 0)
        {
            len = l;
            link = diff = seriesLink = seriesAns = 0;
            memset(next, 0, sizeof(next));
        }
    };

    int minCut(string s)
    {
        int n = s.size();
        vector<Node> tree(n + 3);
        vector<int> dp(n + 1, 1e9);

        int last = 2, sz = 2;

        tree[1] = Node(-1);
        tree[1].link = 1;

        tree[2] = Node(0);
        tree[2].link = 1;

        dp[0] = -1;

        for (int i = 1; i <= n; i++)
        {

            int cur = last;
            int c = s[i - 1] - 'a';

            while (true)
            {
                int curlen = tree[cur].len;
                if (i - 2 - curlen >= 0 && s[i - 2 - curlen] == s[i - 1])
                    break;
                cur = tree[cur].link;
            }

            if (!tree[cur].next[c])
            {

                tree[++sz] = Node(tree[cur].len + 2);
                int newnode = sz;

                int link = tree[cur].link;

                while (true)
                {
                    int len = tree[link].len;
                    if (i - 2 - len >= 0 && s[i - 2 - len] == s[i - 1])
                        break;
                    link = tree[link].link;
                }

                tree[newnode].link = tree[link].next[c];
                if (tree[newnode].link == 0)
                    tree[newnode].link = 2;

                tree[cur].next[c] = newnode;

                tree[newnode].diff =
                    tree[newnode].len - tree[tree[newnode].link].len;

                if (tree[newnode].diff ==
                    tree[tree[newnode].link].diff)
                    tree[newnode].seriesLink =
                        tree[tree[newnode].link].seriesLink;
                else
                    tree[newnode].seriesLink = tree[newnode].link;
            }

            last = tree[cur].next[c];

            for (int v = last; tree[v].len > 0; v = tree[v].seriesLink)
            {

                tree[v].seriesAns =
                    dp[i - (tree[tree[v].seriesLink].len + tree[v].diff)];

                if (tree[v].diff == tree[tree[v].link].diff)
                    tree[v].seriesAns = min(tree[v].seriesAns,
                                            tree[tree[v].link].seriesAns);

                dp[i] = min(dp[i], tree[v].seriesAns + 1);
            }
        }

        return dp[n];
    }
};