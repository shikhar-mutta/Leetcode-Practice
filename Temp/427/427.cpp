// Link: https://leetcode.com/problems/construct-quad-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() : val(false), isLeaf(false), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool _val, bool _isLeaf) : val(_val), isLeaf(_isLeaf), topLeft(nullptr), topRight(nullptr), bottomLeft(nullptr), bottomRight(nullptr) {}
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight)
        : val(_val), isLeaf(_isLeaf), topLeft(_topLeft), topRight(_topRight), bottomLeft(_bottomLeft), bottomRight(_bottomRight) {}
};

// TC: O(n^2 log n)  SC: O(log n)
// Approach: recursively check if the current quadrant is uniform; if so
// make a leaf, otherwise split into 4 sub-quadrants and recurse
class Solution {
    bool uniform(vector<vector<int>>& grid, int r, int c, int size, int& val) {
        val = grid[r][c];
        for (int i = r; i < r + size; i++)
            for (int j = c; j < c + size; j++)
                if (grid[i][j] != val) return false;
        return true;
    }

    Node* build(vector<vector<int>>& grid, int r, int c, int size) {
        int val;
        if (uniform(grid, r, c, size, val)) return new Node(val == 1, true);

        int half = size / 2;
        Node* tl = build(grid, r, c, half);
        Node* tr = build(grid, r, c + half, half);
        Node* bl = build(grid, r + half, c, half);
        Node* br = build(grid, r + half, c + half, half);
        return new Node(true, false, tl, tr, bl, br);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
};
