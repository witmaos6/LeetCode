class Solution {
public:
    string triangleType(vector<int>& nums)
    {
        vector<string> Triangle = {"equilateral", "isosceles", "scalene"};

        int MaxLength = 0;
        int Sum = 0;
        for(int i = 0; i < 3; i++)
        {
            MaxLength = max(MaxLength, nums[i]);
            Sum += nums[i];
        }

        if(MaxLength >= Sum - MaxLength)
            return "none";

        if(IsEquilateral(nums))
            return Triangle[0];

        if(nums[0] == nums[1])
        {
            return Triangle[1];
        }
        if(nums[1] == nums[2])
        {
            return Triangle[1];
        }
        if(nums[2] == nums[0])
        {
            return Triangle[1];
        }
        
        return Triangle[2];
    }

private:
    bool IsEquilateral(vector<int>& Nums)
    {
        int OneLength = Nums[0];
        for(int i = 1; i < 3; i++)
        {
            if(OneLength != Nums[i])
                return false;
        }
        return true;
    }
};