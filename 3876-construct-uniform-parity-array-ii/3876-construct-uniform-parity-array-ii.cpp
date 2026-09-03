class Solution {
    int MinOdd = INT_MAX;
public:
    bool uniformArray(vector<int>& nums1)
    {
        for(int& Num : nums1)
        {
            if(Num & 1)
            {
                MinOdd = min(MinOdd, Num);
            }
        }

        return AllOdd(nums1) || AllEven(nums1);
    }
private:
    bool AllOdd(vector<int>& Nums)
    {
        for(int& Num : Nums)
        {
            if((Num & 1) == 0 && Num <= MinOdd)
            {
                return false;
            }
        }
        return true;
    }

    bool AllEven(vector<int>& Nums)
    {
        for(int& Num : Nums)
        {
            if((Num & 1) == 1 && Num <= MinOdd)
            {
                return false;
            }
        }
        return true;
    }
};