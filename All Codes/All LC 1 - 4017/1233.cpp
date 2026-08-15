// Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n is the number of root folders and m is the average length of the folder paths.
// SC: O(n * m) for storing the root folders and their corresponding hashes in the roots array.
// Approach:
// 1. We will use a hash table to store the root folders and their corresponding hashes.
// 2. We will iterate through the root_folder array and for each folder, we will calculate its hash and check if it is a subfolder of any existing root folder in the hash table.
// 3. If it is not a subfolder, we will add it to the hash table and the result vector. If it is a subfolder, we will skip it.
// 4. Finally, we will return the result vector containing the root folders that are not subfolders of any other folder.
static const auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
#define MAX_ROOT_FOLDER_SIZE 40000
#define MAX_FILENAME_SIZE_INDEX 101
static unsigned short buckets[MAX_FILENAME_SIZE_INDEX],
    order[MAX_ROOT_FOLDER_SIZE];
static std::vector<unsigned short> *roots[0x1'0000];
class Solution
{
public:
    std::vector<std::string>
    removeSubfolders(std::vector<std::string> &root_folder)
    {
        // init
        const size_t rf_size = root_folder.size();
        std::memset(roots, 0, sizeof(roots));
        std::memset(buckets, 0, sizeof(buckets));
        std::vector<std::string> res;
        std::vector<unsigned short> valid_hashes;
        unsigned short curr_hash, curr_ind;

        // bucket sort
        for (const string &s : root_folder)
            buckets[s.size()]++;
        for (unsigned char i = 1; i != MAX_FILENAME_SIZE_INDEX; ++i)
            buckets[i] += buckets[i - 1];
        for (unsigned short i = 0; i != rf_size; ++i)
            order[--buckets[root_folder[i].size()]] = i;

        // perform logic:
        for (unsigned short i = 0; i != rf_size; ++i)
        {
            curr_ind = order[i];
            curr_hash = 0;
            for (unsigned char j = 1; j < root_folder[curr_ind].size(); ++j)
            {
                if (root_folder[curr_ind][j] != '/')
                    curr_hash =
                        ((curr_hash & 0x7fff) << 1) ^ root_folder[curr_ind][j];
                else if (roots[curr_hash])
                {
                    std::string cur_sub = root_folder[order[i]].substr(0, j);
                    if (std::any_of(
                            roots[curr_hash]->begin(), roots[curr_hash]->end(),
                            [&cur_sub, &root_folder](unsigned short root_ind)
                            {
                                return cur_sub == root_folder[root_ind];
                            }))
                    {
                        curr_ind = USHRT_MAX;
                        break;
                    }
                }
            }
            if (curr_ind != USHRT_MAX)
            {
                if (!roots[curr_hash])
                {
                    roots[curr_hash] = new std::vector<unsigned short>();
                    valid_hashes.push_back(curr_hash);
                }
                roots[curr_hash]->push_back(curr_ind);
            }
        }
        // free memory, write to ans
        for (unsigned short hash : valid_hashes)
        {
            for (unsigned short valid_file_index : *roots[hash])
                res.push_back(root_folder[valid_file_index]);
            delete (roots[hash]);
        }
        return res;
    }
};