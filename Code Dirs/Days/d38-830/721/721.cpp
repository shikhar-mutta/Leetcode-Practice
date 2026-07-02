// Link: https://leetcode.com/problems/accounts-merge/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(A * log A), where A is the total number of emails in all accounts. The log factor comes from sorting the emails in each component.
    // SC: O(A), the space used by the Union-Find data structure and the
    // Approach: We can model the problem as a graph problem. Each email is a node, and there is an edge between two emails if they belong to the same account. Then, the problem reduces to finding the connected components of the graph. We can use Union-Find to find the connected components efficiently.
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // Assign each distinct email a node id; remember its owner name.
        unordered_map<string, int> id;
        unordered_map<string, string> name;
        int cnt = 0;
        for (auto &a : accounts)
            for (int i = 1; i < (int)a.size(); i++)
            {
                if (!id.count(a[i]))
                    id[a[i]] = cnt++;
                name[a[i]] = a[0];
            }

        // Union-Find over email ids.
        vector<int> parent(cnt);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x)
        {
            while (parent[x] != x)
                x = parent[x] = parent[parent[x]];
            return x;
        };
        for (auto &a : accounts)
            for (int i = 2; i < (int)a.size(); i++)
                parent[find(id[a[1]])] = find(id[a[i]]);

        // Group emails by their component root.
        unordered_map<int, vector<string>> groups;
        for (auto &[email, i] : id)
            groups[find(i)].push_back(email);

        vector<vector<string>> res;
        for (auto &[root, emails] : groups)
        {
            sort(emails.begin(), emails.end());
            vector<string> row;
            row.push_back(name[emails[0]]);
            for (auto &e : emails)
                row.push_back(e);
            res.push_back(row);
        }
        return res;
    }
};
