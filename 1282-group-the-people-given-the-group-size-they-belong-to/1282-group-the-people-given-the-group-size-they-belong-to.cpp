class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes)
    {
        unordered_map<int, vector<int>> Table;
        vector<vector<int>> Result;
        int N = static_cast<int>(groupSizes.size());
        
        for(int i = 0; i < N; i++)
        {
            int Size = groupSizes[i];
            Table[Size].push_back(i);
            
            if(Table[Size].size() == Size)
            {
                Result.push_back(Table[Size]);
                
                Table.erase(Size);
            }
        }
        
        return Result;
    }
};