// Link: https://leetcode.com/problems/making-file-names-unique/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //  Approach:
    //  1. Create an unordered_map to keep track of the count of each name.
    //  2. Iterate through the input vector of names.
    //  3. For each name, check if it already exists in the unordered_map.
    //  4. If it does not exist, add it to the unordered_map with a count of 0 and add it to the answer vector.
    //  5. If it does exist, increment the count for that name in the unordered_map and create a new name by appending the count in parentheses.
    //  6. Check if the new name already exists in the unordered_map. If it does, increment the count and create a new name again until a unique name is found.
    //  7. Add the unique name to the answer vector and update the unordered_map with the new name and a count of 0.
    //  8. Return the answer vector.
    vector<string> getFolderNames(vector<string> &names)
    {
        unordered_map<string, int> umap;

        vector<string> ans;
        ans.reserve(names.size());

        for (int i = 0; i < names.size(); i++)
        {
            if (umap.find(names[i]) == umap.end())
            {
                umap[names[i]] = 0;
                ans.push_back(names[i]);
                continue;
            }
            else
            {
                string p;
                do
                {
                    umap[names[i]]++;
                    p = names[i];
                    p += "(";
                    p += to_string(umap[names[i]]);
                    p += ")";
                } while (umap.find(p) != umap.end());
                ans.push_back(p);
                umap[p] = 0;
            }
        }
        return ans;
    }
};
