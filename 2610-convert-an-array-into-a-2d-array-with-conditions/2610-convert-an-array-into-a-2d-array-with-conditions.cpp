class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        const int N = static_cast<int>(nums.size());
        vector<vector<int>> Result;
        Result.push_back({nums[0]});
        
        for(int i = 1; i < N; i++)
        {
            int Index = 0;
            while (Index < Result.size() && Result[Index].back() == nums[i])
            {
                Index++;
            }
            if(Index < Result.size())
            {
                Result[Index].push_back(nums[i]);
            }
            else
            {
                Result.push_back({nums[i]});
            }
        }
        
        return Result;
    }
};