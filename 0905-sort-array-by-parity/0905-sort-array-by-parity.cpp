class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int Left = 0;
        int Right = static_cast<int>(nums.size()) - 1;
        
        while(Left < Right)
        {
            if(bIsOddNumber(nums[Left]))
            {
                if(!bIsOddNumber(nums[Right]))
                {
                    swap(nums[Left], nums[Right]);
                    Left++;
                }
                Right--;
            }
            else
            {
                Left++;
            }
        }
        return nums;
    }
    
private:
    inline bool bIsOddNumber(int Num)
    {
        return (Num & 1);
    }
};