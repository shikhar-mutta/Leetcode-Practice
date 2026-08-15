// Link: https://leetcode.com/problems/minimum-genetic-mutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N * 8 * 4) where N is the size of the bank, 8 is the length of the gene, and 4 is the number of possible genes (A, C, G, T)
    // SC: O(N) for the visited set and queue
    // Approach:
    //  1. Use BFS to explore all possible mutations from the startGene.
    //  2. For each gene, try changing each position to one of the 4 possible genes (A, C, G, T).
    //  3. If the mutated gene is in the bank and has not been visited, add it to the queue for further exploration.
    //  4. Keep track of the number of mutations (steps) taken to reach the endGene.
    //  5. If the endGene is reached, return the number of steps. If the queue is exhausted without finding the endGene, return -1.
    // 6. Return -1 if the endGene is not in the bank.
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene))
            return -1;

        unordered_set<string> visited;
        queue<string> q;
        q.push(startGene);
        visited.insert(startGene);

        string genes = "ACGT";
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                string cur = q.front();
                q.pop();
                if (cur == endGene)
                    return steps;

                for (int pos = 0; pos < (int)cur.size(); pos++)
                {
                    char orig = cur[pos];
                    for (char g : genes)
                    {
                        if (g == orig)
                            continue;
                        cur[pos] = g;
                        if (bankSet.count(cur) && !visited.count(cur))
                        {
                            visited.insert(cur);
                            q.push(cur);
                        }
                    }
                    cur[pos] = orig;
                }
            }
            steps++;
        }
        return -1;
    }
};
