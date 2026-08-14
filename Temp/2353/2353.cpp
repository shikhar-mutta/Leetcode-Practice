// Link: https://leetcode.com/problems/design-a-food-rating-system/description/

#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    unordered_map<string,string> foodCuisine;
    unordered_map<string,int> foodRating;
    unordered_map<string, set<pair<int,string>>> cuisineFoods; // (-rating, name)
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < (int)foods.size(); i++) {
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        int oldRating = foodRating[food];
        cuisineFoods[cuisine].erase({-oldRating, food});
        foodRating[food] = newRating;
        cuisineFoods[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second;
    }
};
