class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        int Low = ranges::min(nums);
        int Moves = 0;
        for(int& Num : nums)
        {
            Moves += Num - Low;
        }
        return Moves;
    }
};