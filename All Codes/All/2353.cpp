// Link: https://leetcode.com/problems/design-a-food-rating-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n), where n is the number of foods in the cuisine.
// SC: O(n), where n is the number of foods in the cuisine.
//  Approach:
//   1. We use two hash maps to store the food ratings and the cuisine ratings. The food_map stores the rating and cuisine of each food, while the cuisine_map stores a priority queue of foods for each cuisine, sorted by rating and lexicographical order.
//   2. The constructor initializes the food_map and cuisine_map with the given foods, cuisines, and ratings.
//  3. The changeRating function updates the rating of a food in the food_map and adds the new rating to the corresponding cuisine's priority queue in the cuisine_map.
//  4. The highestRated function retrieves the highest-rated food for a given cuisine by checking the top of the priority queue and ensuring that the rating matches the current rating in the food_map. If not, it pops the outdated entry from the priority queue until it finds a valid entry.
class FoodRatings
{
    using pis = pair<int, string>;
    unordered_map<string, pis> food_map;
    unordered_map<string, priority_queue<pis, vector<pis>, greater<>>>
        cuisine_map;

public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines,
                vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            auto &food = foods[i];
            auto &cuisine = cuisines[i];
            int rating = ratings[i];
            food_map[food] = {rating, cuisine};
            cuisine_map[cuisine].emplace(-rating, food);
        }
    }

    void changeRating(string food, int newRating)
    {
        auto &[rating, cuisine] = food_map[food];
        cuisine_map[cuisine].emplace(-newRating, food);
        rating = newRating;
    }

    string highestRated(string cuisine)
    {
        auto &pq = cuisine_map[cuisine];
        while (-pq.top().first != food_map[pq.top().second].first)
            pq.pop();
        return pq.top().second;
    }
};
