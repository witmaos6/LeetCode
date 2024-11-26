class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges)
    {
        vector<bool> IsChampion(n, true);
        
        for(vector<int>& Edge : edges)
        {
            IsChampion[Edge[1]] = false;
        }
        
        int ChampionNum = -1;
        for(int i = 0; i < n; ++i)
        {
            if(IsChampion[i])
            {
                if(ChampionNum != -1)
                {
                    return -1;
                }
                ChampionNum = i;
            }
        }
        
        return ChampionNum;
    }
};