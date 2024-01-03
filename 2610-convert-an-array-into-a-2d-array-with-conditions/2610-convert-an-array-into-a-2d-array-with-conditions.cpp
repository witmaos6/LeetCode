class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        unordered_map<int, int> Table;
        int MaxNum = 0;
        for(int Num : nums)
        {
            Table[Num]++;
            MaxNum = max(MaxNum, Table[Num]);
        }
        
        vector<vector<int>> Result(MaxNum);
        
        for(auto& [Num, Freq] : Table)
        {
            for(int i = 0; i < Freq; i++)
            {
                Result[i].emplace_back(Num);
            }
        }
        
        return Result;
    }
};