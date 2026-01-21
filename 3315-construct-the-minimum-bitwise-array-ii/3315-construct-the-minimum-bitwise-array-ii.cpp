class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Answer(N, -1);

        for(int i = 0; i < N; i++)
        {
            if(nums[i] != 2)
            {
                int Num = nums[i];

                int Bit = (Num - ((Num + 1) & (-Num - 1)) / 2);
                Answer[i] = Bit;
            }
        }
        return Answer;
    }
};