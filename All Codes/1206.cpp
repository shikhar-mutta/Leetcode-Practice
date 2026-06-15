// Link: https://leetcode.com/problems/design-skiplist/description/

#include <bits/stdc++.h>
using namespace std;

class Skiplist {
    static const int MAX_LEVEL = 16;
    struct Node {
        int val;
        vector<Node *> next;
        Node(int v, int level) : val(v), next(level, nullptr) {}
    };
    Node *head;
    int level; // current highest active level (>=1)

    int randomLevel() {
        int lvl = 1;
        while ((rand() & 1) && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }

public:
    Skiplist() {
        head = new Node(-1, MAX_LEVEL);
        level = 1;
    }

    bool search(int target) {
        Node *cur = head;
        for (int i = level - 1; i >= 0; i--)
            while (cur->next[i] && cur->next[i]->val < target)
                cur = cur->next[i];
        cur = cur->next[0];
        return cur && cur->val == target;
    }

    void add(int num) {
        vector<Node *> update(MAX_LEVEL, head);
        Node *cur = head;
        for (int i = level - 1; i >= 0; i--) {
            while (cur->next[i] && cur->next[i]->val < num)
                cur = cur->next[i];
            update[i] = cur;
        }
        int lvl = randomLevel();
        if (lvl > level)
            level = lvl;
        Node *node = new Node(num, lvl);
        for (int i = 0; i < lvl; i++) {
            node->next[i] = update[i]->next[i];
            update[i]->next[i] = node;
        }
    }

    bool erase(int num) {
        vector<Node *> update(MAX_LEVEL, head);
        Node *cur = head;
        for (int i = level - 1; i >= 0; i--) {
            while (cur->next[i] && cur->next[i]->val < num)
                cur = cur->next[i];
            update[i] = cur;
        }
        cur = cur->next[0];
        if (!cur || cur->val != num)
            return false;
        for (int i = 0; i < level; i++) {
            if (update[i]->next[i] != cur)
                break;
            update[i]->next[i] = cur->next[i];
        }
        delete cur;
        while (level > 1 && head->next[level - 1] == nullptr)
            level--;
        return true;
    }
};
