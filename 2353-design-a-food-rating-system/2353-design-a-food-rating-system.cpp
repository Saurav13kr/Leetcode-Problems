class FoodRatings {
    unordered_map<string,set<pair<int,string>>> cuisines_foods;
    unordered_map<string,string> food_cuisines;
    unordered_map<string,int> food_ratings;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            cuisines_foods[cuisines[i]].insert({-ratings[i],foods[i]});
            food_cuisines[foods[i]]=cuisines[i];
            food_ratings[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        pair<int,string> p={-newRating,food};
        string cuisine= food_cuisines[food];
        cuisines_foods[cuisine].erase({-food_ratings[food],food});
        cuisines_foods[cuisine].insert(p);
        food_ratings[food]=newRating;
    }
    
    string highestRated(string cuisine) {
        for(auto it:cuisines_foods[cuisine]){
            return it.second;
        }
        return "-1";
    }
};