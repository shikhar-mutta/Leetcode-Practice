// Link: https://leetcode.com/problems/all-oone-data-structure/description/

#include <bits/stdc++.h>
using namespace std;

class AllOne {
    struct Bucket {
        int count;
        unordered_set<string> keys;
        Bucket *prev, *next;
        Bucket(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    Bucket *head, *tail;                       // sentinels: low side / high side
    unordered_map<string, Bucket*> where;      // key -> its current bucket

    Bucket* insertAfter(Bucket* node, int count) {
        Bucket* nb = new Bucket(count);
        nb->prev = node;
        nb->next = node->next;
        node->next->prev = nb;
        node->next = nb;
        return nb;
    }
    void unlink(Bucket* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Bucket(0);
        tail = new Bucket(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (where.count(key)) {
            Bucket* cur = where[key];
            int nc = cur->count + 1;
            Bucket* nb = (cur->next == tail || cur->next->count != nc)
                             ? insertAfter(cur, nc) : cur->next;
            nb->keys.insert(key);
            where[key] = nb;
            cur->keys.erase(key);
            if (cur->keys.empty()) unlink(cur);
        } else {
            Bucket* first = head->next;
            Bucket* nb = (first == tail || first->count != 1)
                             ? insertAfter(head, 1) : first;
            nb->keys.insert(key);
            where[key] = nb;
        }
    }

    void dec(string key) {
        if (!where.count(key)) return;
        Bucket* cur = where[key];
        int nc = cur->count - 1;
        if (nc == 0) {
            where.erase(key);   
        } else {
            Bucket* nb = (cur->prev == head || cur->prev->count != nc)
                             ? insertAfter(cur->prev, nc) : cur->prev;
            nb->keys.insert(key);
            where[key] = nb;
        }
        cur->keys.erase(key);
        if (cur->keys.empty()) unlink(cur);
    }

    string getMaxKey() {
        return tail->prev == head ? "" : *tail->prev->keys.begin();
    }
    string getMinKey() {
        return head->next == tail ? "" : *head->next->keys.begin();
    }
};
