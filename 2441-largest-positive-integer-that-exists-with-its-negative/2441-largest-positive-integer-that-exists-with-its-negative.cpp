class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        int MaxInt = INT_MIN;
        array<int, 2001> Table = {0};
        
        for(int Num : nums)
        {
            if(Table[-Num + 1000] == 1)
            {
                MaxInt = max(MaxInt, abs(Num));
            }
            Table[Num + 1000] = 1;
        }
        return MaxInt == INT_MIN ? -1 : MaxInt;
    }
};