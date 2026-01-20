class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Answer(N, -1);

        for(int i = 0; i < N; i++)
        {
            for(int Num = 1; Num <= nums[i]; Num++)
            {
                if((Num | Num + 1) == nums[i])
                {
                    Answer[i] = Num;
                    break;
                }
            }
        }
        return Answer;
    }
};