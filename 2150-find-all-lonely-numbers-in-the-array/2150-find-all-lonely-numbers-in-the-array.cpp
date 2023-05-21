class Solution {
    const int ExistAdj = -1;
public:
    vector<int> findLonely(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        
        int N = static_cast<int>(nums.size());
        int Temp = -1;
        for(int i = 1; i < N; i++)
        {
            if(Temp == -1)
            {
                if(bIsAdjNum(nums[i], nums[i - 1]))
                {
                    Temp = nums[i];
                    nums[i - 1] = ExistAdj;
                    nums[i] = ExistAdj;
                }
            }
            else
            {
                if(bIsAdjNum(nums[i], Temp))
                {
                    Temp = nums[i];
                    nums[i] = ExistAdj;
                }
                else
                {
                    Temp = -1;
                }
            }
        }
        
        vector<int> LonelyNums;
        for(int& Num : nums)
        {
            if(Num != ExistAdj)
            {
                LonelyNums.push_back(Num);
            }
        }
        
        return LonelyNums;
    }
    
private:
    bool bIsAdjNum(int Num1, int Num2)
    {
        if(Num1 == Num2 || Num1 - 1 == Num2)
        {
            return true;
        }
        return false;
    }
};