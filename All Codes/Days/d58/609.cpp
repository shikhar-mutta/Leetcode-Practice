// Link: https://leetcode.com/problems/find-duplicate-file-in-system/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m), where n is the number of strings in the input vector and m is the average length of each string. We iterate through each string and process its characters to extract file paths and contents.
    // SC: O(n * m), where n is the number of unique file contents and m is the average length of the file paths. We store the file paths in an unordered_map based on their contents, which can take up space proportional to the number of unique contents and the length of the file paths.
    // Approach:
    // 1. We use an unordered_map to group file paths by their contents. The key is the file content, and the value is a vector of file paths that have that content.
    // 2. We iterate through each string in the input vector, extracting the root directory, file names, and their contents. We build the full file path and store it in the unordered_map.
    // 3. After processing all strings, we iterate through the unordered_map and collect the file paths that have duplicate contents (i.e., those with more than one file path in the vector).
    // 4. Finally, we return a vector of vectors containing the duplicate file paths.
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        vector<vector<string>> sol;
        unordered_map<string, vector<string>> umap;
        for (string &str : paths)
        {
            vector<string> files;
            string root = "", file = "", content = "";
            int i = 0;
            while (str[i] != ' ')
            {
                root += str[i];
                i++;
            }
            root += '/';
            while (i < str.size())
            {
                if (str[i] == ' ')
                {
                    i++;
                    continue;
                }
                if (str[i] == ')')
                {
                    i++;
                    umap[content].push_back(root + file);
                    content = "";
                    file = "";
                    continue;
                }
                if (str[i] == '(')
                {
                    while (str[i] != ')')
                    {
                        content += str[i];
                        i++;
                    }
                }
                else
                {
                    file += str[i];
                    i++;
                }
            }
        }
        for (auto &pair : umap)
        {
            if (pair.second.size() > 1)
            {
                sol.push_back(move(pair.second));
            }
        }
        return sol;
    }
};