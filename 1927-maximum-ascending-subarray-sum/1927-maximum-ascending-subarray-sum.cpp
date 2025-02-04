class Solution {
public:
    int maxAscendingSum(vector<int>& nums)
    {
        int MaxSubarrNum = 0;
        int PrevNum = 0;
        int SubarrNum = 0;
        for(int& Num : nums)
        {
            if(PrevNum < Num)
            {
                SubarrNum += Num;
            }
            else
            {
                SubarrNum = Num;
            }
            PrevNum = Num;
            MaxSubarrNum = max(MaxSubarrNum, SubarrNum);
        }
        return MaxSubarrNum;
    }
};