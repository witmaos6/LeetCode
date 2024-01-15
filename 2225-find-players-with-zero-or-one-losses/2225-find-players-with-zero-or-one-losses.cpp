class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        map<int, int> LoseTable;
        
        for(vector<int>& Match : matches)
        {
            LoseTable[Match[0]];
            LoseTable[Match[1]]++;
        }
        
        vector<vector<int>> Answer(2);
        for(auto& [Player, Lose] : LoseTable)
        {
            if(Lose == 0)
            {
                Answer[0].push_back(Player);
            }
            else if(Lose == 1)
            {
                Answer[1].push_back(Player);
            }
        }
        return Answer;
    }
};