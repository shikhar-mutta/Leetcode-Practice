// Link: https://leetcode.com/problems/word-search-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(M*N*4^L) SC: O(M*N + L) where M is the number of rows, N is the number of columns, and L is the length of the longest word in the list.
// SC: O(M*N + L) where M is the number of rows, N is the number of columns, and L is the length of the longest word in the list.
// Approach:
// 1. We can use a Trie data structure to store the words in the list.
// 2. We can then perform a depth-first search (DFS) on the board, starting from each cell, and check if the current path forms a word in the Trie.
// 3. If it does, we add it to the result list and mark the cell as visited by changing its value to '#' to avoid revisiting it in the same path.

class Solution
{
private:
    int n;
    int m;

    struct Node
    {
        Node *next[26]{};
        Node *parent = nullptr;
        const string *ref = nullptr;
        int count = 0;
        char c;

        Node(char ch)
        {
            c = ch;
        }
    };

    void addWord(vector<Node> &nodes, const string &word)
    {
        Node *node = &nodes[0];
        for (const char c : word)
        {
            if (node->next[c - 'a'] == nullptr)
            {
                nodes.emplace_back(c);
                node->next[c - 'a'] = &nodes.back();
                node->count++;
            }
            Node *next = node->next[c - 'a'];
            next->parent = node;
            node = next;
        }
        node->ref = &word;
    }

    void addWordBackward(vector<Node> &nodes, const string &word)
    {
        Node *node = &nodes[0];
        for (int i = word.size() - 1; i >= 0; i--)
        {
            const char c = word[i];

            if (node->next[c - 'a'] == nullptr)
            {
                nodes.emplace_back(c);
                node->next[c - 'a'] = &nodes.back();
                node->count++;
            }
            Node *next = node->next[c - 'a'];
            next->parent = node;
            node = next;
        }
        node->ref = &word;
    }

    struct NodePtr
    {
        set<Node *> *ptrs = new set<Node *>();
    };

    bool dfs(
        vector<vector<char>> &board,
        Node *dfsCur,
        vector<string> &result,
        int i, int j,
        Node *dfsRoot)
    {
        const char c = board[i][j];
        if (c < 'a' || dfsCur->c != c)
            return false;
        if (dfsCur->parent->parent == nullptr)
        {
            result.push_back(
                *dfsRoot->ref);
            dfsRoot->ref = nullptr;
            return true;
        }

        Node *dfsNext = dfsCur->parent;
        board[i][j] = 'a' - 1; // make sure dfs does not overlap.
        bool done = (j < m - 1 && dfs(board, dfsNext, result, i, j + 1, dfsRoot)) || (j > 0 && dfs(board, dfsNext, result, i, j - 1, dfsRoot)) || (i < n - 1 && dfs(board, dfsNext, result, i + 1, j, dfsRoot)) || (i > 0 && dfs(board, dfsNext, result, i - 1, j, dfsRoot));
        board[i][j] = c;

        return done;
    }

    void exist(
        vector<vector<char>> &board,
        Node *trie,
        vector<string> &result)
    {
        vector<NodePtr> dp(n * m);

        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (trie->next[board[i][j] - 'a'] == nullptr)
                    continue;
                Node *node = trie->next[board[i][j] - 'a'];

                if (node->ref != nullptr)
                {
                    result.push_back(*node->ref);
                    node->ref = nullptr;
                }
                if (node->count > 0)
                {
                    count++;
                    dp[i + n * j].ptrs->insert(node);
                }
            }

        while (count > 0)
        {
            NodePtr tmp = NodePtr();
            vector<NodePtr> lastRow(m);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    const char c = board[i][j];

                    NodePtr node = move(tmp);
                    node.ptrs->clear();
                    update(c, lastRow[j], node, board, i, j, result);
                    if (j > 0)
                        update(c, lastRow[j - 1], node, board, i, j, result);
                    if (i < n - 1)
                        update(c, dp[i + n * j + 1], node, board, i, j, result);
                    if (j < m - 1)
                        update(c, dp[i + n * j + n], node, board, i, j, result);

                    count -= dp[i + n * j].ptrs->size();
                    count += node.ptrs->size();

                    tmp = move(lastRow[j]);
                    lastRow[j] = move(dp[i + n * j]);
                    dp[i + n * j] = move(node);
                }
        }
    }

    void update(
        const char c,
        NodePtr &from,
        NodePtr &to,
        vector<vector<char>> &board,
        int i, int j,
        vector<string> &result)
    {
        for (Node *parent : *from.ptrs)
        {
            Node *node = parent->next[c - 'a'];
            if (node != nullptr)
            {
                if (node->ref != nullptr)
                    if (!dfs(board, node, result, i, j, node))
                        continue;
                if (node->count > 0)
                    to.ptrs->insert(node);
            }
        }
    }

public:
    vector<string> findWords(vector<vector<char>> &board, const vector<string> &words)
    {
        n = board.size();
        m = board[0].size();

        vector<Node> forward;
        forward.reserve(1 + 10 * words.size()); // make sure the array is not resized
        forward.emplace_back(0);                // each word is at most 10 characters

        vector<Node> backward;
        backward.reserve(1 + 10 * words.size());
        backward.emplace_back(0);

        for (int i = 0; i < words.size(); i++)
        {
            addWordBackward(
                backward,
                words[i]);
            addWord(
                forward,
                words[i]);
        }

        vector<string> result;
        result.reserve(words.size());

        // make sure dp is as fast as possible
        // This is the difference between 3ms and 100ms
        if (forward.size() < backward.size())
            exist(board, &forward[0], result);
        else
            exist(board, &backward[0], result);
        return result;
    }
};