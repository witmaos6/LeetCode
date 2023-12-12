class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        pair<int, int> MaxPair = {0, 0};
        
        for(int Num : nums)
        {
            if(Num > MaxPair.first)
            {
                MaxPair.second = MaxPair.first;
                MaxPair.first = Num;
            }
            else if(Num > MaxPair.second)
            {
                MaxPair.second = Num;
            }
        }
        
        return (MaxPair.first - 1) * (MaxPair.second - 1);
    }
};