// Link: https://leetcode.com/problems/count-pairs-with-xor-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode* child[2] = {nullptr, nullptr};
        int count = 0;
    };
    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;
        for (int b = 14; b >= 0; b--) {
            int bit = (num >> b) & 1;
            if (!node->child[bit]) node->child[bit] = new TrieNode();
            node = node->child[bit];
            node->count++;
        }
    }

    int countLess(int num, int limit) {
        TrieNode* node = root;
        int count = 0;
        for (int b = 14; b >= 0 && node; b--) {
            int bit = (num >> b) & 1;
            int limBit = (limit >> b) & 1;
            if (limBit == 1) {
                if (node->child[bit]) count += node->child[bit]->count;
                node = node->child[1 - bit];
            } else {
                node = node->child[bit];
            }
        }
        return count;
    }

    int countPairs(vector<int>& nums, int low, int high) {
        int result = 0;
        for (int num : nums) {
            result += countLess(num, high + 1) - countLess(num, low);
            insert(num);
        }
        return result;
    }
};
