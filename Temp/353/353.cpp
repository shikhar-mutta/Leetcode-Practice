// Link: https://leetcode.com/problems/design-snake-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per move  SC: O(width*height)
// Approach: deque tracks the snake body (head at back); move head, check
// wall/self collision, eat food without popping tail, else pop tail
class SnakeGame {
    int width, height;
    vector<vector<int>> food;
    int foodIdx = 0;
    deque<pair<int,int>> body;
    set<pair<int,int>> occupied;

public:
    SnakeGame(int width, int height, vector<vector<int>>& food) : width(width), height(height), food(food) {
        body.push_back({0, 0});
        occupied.insert({0, 0});
    }

    int move(string direction) {
        auto [r, c] = body.back();
        if (direction == "U") r--;
        else if (direction == "D") r++;
        else if (direction == "L") c--;
        else if (direction == "R") c++;

        if (r < 0 || r >= height || c < 0 || c >= width) return -1;

        bool ateFood = foodIdx < (int)food.size() && food[foodIdx][0] == r && food[foodIdx][1] == c;

        pair<int,int> tail = body.front();
        if (!ateFood) {
            occupied.erase(tail);
            body.pop_front();
        }

        if (occupied.count({r, c})) return -1;

        body.push_back({r, c});
        occupied.insert({r, c});
        if (ateFood) foodIdx++;

        return body.size() - 1;
    }
};
