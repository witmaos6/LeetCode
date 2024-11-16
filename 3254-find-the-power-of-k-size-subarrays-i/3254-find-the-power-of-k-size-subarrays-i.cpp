class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        if(k == 1)
        {
            return nums;
        }
        
        const int N = static_cast<int>(nums.size());
        const int ResultSize = N - k + 1;
        vector<int> Result(ResultSize);
        
        bool PrevIsAsc = false;
        for(int i = 0; i < ResultSize; ++i)
        {
            bool IsAsc = false;
            if(PrevIsAsc)
            {
                IsAsc = (nums[i + k - 2] + 1 == nums[i + k - 1]);
            }
            else
            {
                IsAsc = IsAscendingArr(nums, i, i + k);
            }
            
            Result[i] = IsAsc ? nums[i + k - 1] : -1;
            PrevIsAsc = IsAsc;
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