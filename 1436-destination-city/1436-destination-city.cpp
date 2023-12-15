class Solution {
public:
    string destCity(vector<vector<string>>& paths)
    {
        unordered_set<string> FromCities;
        
        for(vector<string>& Path : paths)
        {
            FromCities.insert(Path[0]);
        }
        
        const size_t N = paths.size();
        for(size_t i = 0; i < N; i++)
        {
            if(FromCities.find(paths[i][1]) == FromCities.end())
            {
                return paths[i][1];
            }
        }
        
        return paths[0][1];
    }
};