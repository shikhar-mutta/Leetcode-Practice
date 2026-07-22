// Link: https://leetcode.com/problems/replace-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), where n is the total number of characters in the dictionary and m is the total number of characters in the sentence.
// SC: O(n), where n is the total number of characters in the dictionary.
// Approach: Trie
// 1. Build a trie from the dictionary words.
// 2. For each word in the sentence, traverse the trie to find the shortest root that can replace the word. If no root is found, keep the original word.
// 3. Construct the final sentence by joining the replaced words with spaces.
// 4. Return the final sentence.

class Solution
{
    static constexpr int MAX_NODES = 100001;
    static constexpr int ALPHABET = 26;
    static int trie_[MAX_NODES][ALPHABET];
    static bool end_[MAX_NODES];
    static int cnt_;

public:
    static auto replaceWords(std::vector<std::string> &dictionary,
                             const std::string &sentence) -> std::string
    {
        cnt_ = 1;
        memset(trie_[0], 0, sizeof(trie_[0]));
        end_[0] = false;

        for (const auto &word : dictionary)
        {
            int node = 0;
            for (char const chr : word)
            {
                int const idx = chr - 'a';
                if (trie_[node][idx] == 0)
                {
                    trie_[node][idx] = cnt_;
                    memset(trie_[cnt_], 0, sizeof(trie_[cnt_]));
                    end_[cnt_] = false;
                    ++cnt_;
                }
                node = trie_[node][idx];
            }
            end_[node] = true;
        }

        std::string res;
        res.reserve(sentence.size());
        const char *const str = sentence.c_str();
        int const num = static_cast<int>(sentence.size());
        int pos = 0;

        while (pos < num)
        {
            int end = pos;
            while (end < num && str[end] != ' ')
            {
                ++end;
            }
            if (!res.empty())
            {
                res += ' ';
            }
            int node = 0;
            int len = end - pos;
            for (int idx = 0; idx < len; ++idx)
            {
                int const char_idx = str[pos + idx] - 'a';
                if (trie_[node][char_idx] == 0)
                {
                    break;
                }
                node = trie_[node][char_idx];
                if (end_[node])
                {
                    len = idx + 1;
                    break;
                }
            }
            res.append(str + pos, len);
            pos = end + 1;
        }
        return res;
    }
};

int Solution::trie_[Solution::MAX_NODES][Solution::ALPHABET];
bool Solution::end_[Solution::MAX_NODES];
int Solution::cnt_;