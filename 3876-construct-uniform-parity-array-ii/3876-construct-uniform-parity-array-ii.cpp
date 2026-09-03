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

        return AllTargetMod(nums1, 0) || AllTargetMod(nums1, 1);
    }
private:
    bool AllTargetMod(vector<int>& Nums, const int Target)
    {
        for(int& Num : Nums)
        {
            if((Num & 1) == Target && Num <= MinOdd)
            {
                return false;
            }
        }
        return true;
    }
};