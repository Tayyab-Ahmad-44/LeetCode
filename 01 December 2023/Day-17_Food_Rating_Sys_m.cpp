#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class custom_comparator
{
public:
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) const
    {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};

class FoodRatings
{
public:
    // Hash Function :
    // H1(food_name) = { cuisine_name, current_rating }

    unordered_map<string, pair<string, int>> food_info;

    // Hash Function :
    // H2(cuisine_name) = SET({ food_name, current_rating } : ordered by current_rating DESCENDING)

    unordered_map<string, set<pair<string, int>, custom_comparator>> cuisine_info;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) // Time : 0(n)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        const int n = (int)foods.size();

        for (int i = 0; i < n; ++i)
        {
            food_info[foods[i]] = {cuisines[i], ratings[i]};
            cuisine_info[cuisines[i]].insert(make_pair(foods[i], ratings[i]));
        }
    }

    void changeRating(string food, int new_rating) // Time : 0(log N)
    {
        pair<string, int> &f = food_info[food];
        int old_rating = f.second;

        set<pair<string, int>, custom_comparator> &st = cuisine_info[f.first];

        // Remove { food, old_rating } record from cuisine_info

        st.erase({food, old_rating});

        // Update new rating of the food in food_info and its cuisine_info

        f.second = new_rating;
        st.insert(make_pair(food, new_rating));

        return;
    }

    string highestRated(string cuisine) // Tine : 0(1)
    {
        return cuisine_info[cuisine].begin()->first;
    }

    //!                  Damnnnnnnnnnnnnnnnnnnn          TLE
    /*FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        this->foods = foods;
        this->cuisines = cuisines;
        this->ratings = ratings;
    }

    void changeRating(string food, int newRating)
    {
        int len = foods.size();

        for (size_t i = 0; i < len; i++)
            if (foods[i] == food)
            {
                ratings[i] = newRating;
                return;
            }
    }

    string highestRated(string cuisine)
    {
        int len = foods.size();
        int rating = -1;
        string res;

        for (size_t i = 0; i < len; i++)
            if (cuisines[i] == cuisine)
                if (ratings[i] >= rating)
                    if (ratings[i] == rating)
                        res = (foods[i] < res) ? foods[i] : res;
                    else
                    {
                        res = foods[i];
                        rating = ratings[i];
                    }
        return res;
    }*/
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main()
{

    return 0;
}

/*

2353. Design a Food Rating System
Medium

Design a food rating system that can do the following:

Modify the rating of a food item listed in the system.
Return the highest-rated food item for a type of cuisine in the system.
Implement the FoodRatings class:

FoodRatings(String[] foods, String[] cuisines, int[] ratings) Initializes the system. The food items are described by foods, cuisines and ratings, all of which have a length of n.
foods[i] is the name of the ith food,
cuisines[i] is the type of cuisine of the ith food, and
ratings[i] is the initial rating of the ith food.
void changeRating(String food, int newRating) Changes the rating of the food item with the name food.
String highestRated(String cuisine) Returns the name of the food item that has the highest rating for the given type of cuisine. If there is a tie, return the item with the lexicographically smaller name.
Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.



Example 1:

Input
["FoodRatings", "highestRated", "highestRated", "changeRating", "highestRated", "changeRating", "highestRated"]
[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]], ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]
Output
[null, "kimchi", "ramen", null, "sushi", null, "ramen"]

Explanation
FoodRatings foodRatings = new FoodRatings(["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], ["korean", "japanese", "japanese", "greek", "japanese", "korean"], [9, 12, 8, 15, 14, 7]);
foodRatings.highestRated("korean"); // return "kimchi"
                                    // "kimchi" is the highest rated korean food with a rating of 9.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // "ramen" is the highest rated japanese food with a rating of 14.
foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "sushi"
                                      // "sushi" is the highest rated japanese food with a rating of 16.
foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
foodRatings.highestRated("japanese"); // return "ramen"
                                      // Both "sushi" and "ramen" have a rating of 16.
                                      // However, "ramen" is lexicographically smaller than "sushi".


*/