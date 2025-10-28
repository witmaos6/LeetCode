class Solution {
public:
    int countValidSelections(vector<int>& nums)
    {
        int Total = accumulate(nums.begin(), nums.end(), 0);
        int Left = 0;
        int Case = 0;

        for(int& Num : nums)
        {
            int Right = Total - Left - Num;
            if(Num == 0)
            {
                if(Left == Right)
                {
                    Case += 2;
                }
                else if(Left == Right - 1 || Left - 1 == Right)
                {
                    Case++;
                }
            }
            Left += Num;
        }
        return Case;
    }
};