struct FoodInfo
{
    string Name;
    string Cuisine;
    int Rating;
    
    FoodInfo() = default;
    FoodInfo(string InName, string InCuisine, int InRating) : Name{InName}, Cuisine{InCuisine}, Rating{InRating}{}

    bool operator<(const FoodInfo& first) const {
        if (Rating == first.Rating) {
            return Name < first.Name;
        }
        return Rating > first.Rating;
    }
};

class FoodRatings {
    unordered_map<string, FoodInfo> NameToInfo;
    unordered_map<string, set<FoodInfo>> CuisineToInfo;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        const size_t N = foods.size();
        
        for(size_t i = 0; i < N; i++)
        {
            FoodInfo CurrInfo = FoodInfo(foods[i], cuisines[i], ratings[i]);
            
            NameToInfo.emplace(foods[i], CurrInfo);
            CuisineToInfo[cuisines[i]].emplace(CurrInfo);
        }
    }
    
    void changeRating(string food, int newRating)
    {
        FoodInfo& UpdateInfo = NameToInfo[food];
        
        CuisineToInfo[UpdateInfo.Cuisine].erase(UpdateInfo);
        UpdateInfo.Rating = newRating;
        CuisineToInfo[UpdateInfo.Cuisine].insert(UpdateInfo);
    }
    
    string highestRated(string cuisine)
    {
        return CuisineToInfo[cuisine].begin()->Name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */