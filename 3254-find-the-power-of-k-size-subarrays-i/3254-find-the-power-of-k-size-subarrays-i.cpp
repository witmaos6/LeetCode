class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        const int ResultSize = N - k + 1;
        vector<int> Result(ResultSize);
        
        for(int i = 0; i < ResultSize; ++i)
        {
            Result[i] = IsAscendingArr(nums, i, i + k) ? nums[i + k - 1] : -1;
        }
        
        return Result;
    }
    
private:
    bool IsAscendingArr(const vector<int>& Nums, int Begin, int End)
    {
        for(int i = Begin; i < End - 1; ++i)
        {
            if(Nums[i] + 1 != Nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};