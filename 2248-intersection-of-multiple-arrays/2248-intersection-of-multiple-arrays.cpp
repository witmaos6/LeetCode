class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums)
    {
        size_t N = nums.size();
        if(N == 1)
        {
            sort(nums[0].begin(), nums[0].end());
            return nums.front();
        }
        
        size_t MaxIndex = 0;
        size_t MaxSize = 0;
        for(size_t i = 0; i < N; i++)
        {
            sort(nums[i].begin(), nums[i].end());
            
            if(MaxSize < nums[i].size())
            {
                MaxIndex = i;
                MaxSize = nums[i].size();
            }
        }
        swap(nums[0], nums[MaxIndex]);
        
        vector<int> Result;
        
        for(size_t Col = 0; Col < MaxSize; Col++)
        {
            int Target = nums[0][Col];
            bool Flag = true;
            
            for(size_t Row = 1; Row < N; Row++)
            {
                if(!binary_search(nums[Row].begin(), nums[Row].end(), Target))
                {
                    Flag = false;
                    break;
                }
            }
            if(Flag)
            {
                Result.push_back(Target);
            }
        }
        
        return Result;
    }
};