class Solution {
public:
    int longestSquareStreak(vector<int>& nums)
    {
        unordered_map<int, int> Table;
        sort(nums.begin(), nums.end());

        int MaxLength = -1;
        
        for(int Num : nums)
        {
            int Sqrt = static_cast<int>(sqrt(Num));
            
            if(Sqrt * Sqrt == Num && Table.find(Sqrt) != Table.end())
            {
                Table[Num] = Table[Sqrt] + 1;
                MaxLength = max(MaxLength, Table[Num]);
            }
            else
            {
                Table[Num] = 1;
            }
        }
        
        return MaxLength;
    }
};