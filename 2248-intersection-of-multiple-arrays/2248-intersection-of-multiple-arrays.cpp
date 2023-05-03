class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums)
    {
        vector<int> Count(1001);
        
        for(vector<int>& Row : nums)
        {
            for(int& Col : Row)
            {
                Count[Col]++;
            }
        }
        
        int N = static_cast<int>(nums.size());
        vector<int> Result;
        
        for(int i = 1; i < 1001; i++)
        {
            if(Count[i] == N)
            {
                Result.push_back(i);
            }
        }
        
        return Result;
    }
};