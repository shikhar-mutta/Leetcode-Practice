// Link: https://leetcode.com/problems/design-memory-allocator/description/

#include <bits/stdc++.h>
using namespace std;

class Allocator {
    vector<int> mem;
public:
    Allocator(int n) {
        mem.assign(n, 0);
    }

    int allocate(int size, int mID) {
        int n = mem.size();
        int i = 0;
        while (i < n) {
            if (mem[i] != 0) { i++; continue; }
            int j = i;
            while (j < n && mem[j] == 0 && j - i < size) j++;
            if (j - i == size) {
                for (int k = i; k < j; k++) mem[k] = mID;
                return i;
            }
            i = j;
        }
        return -1;
    }

    int freeMemory(int mID) {
        int count = 0;
        for (int i = 0; i < (int)mem.size(); i++) {
            if (mem[i] == mID) {
                mem[i] = 0;
                count++;
            }
        }
        return count;
    }
};
