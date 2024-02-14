class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<int> Positive;
        vector<int> Negative;
        Positive.reserve(N / 2);
        Negative.reserve(N / 2);
        
        for(int Num : nums)
        {
            if(Num > 0)
            {
                Positive.push_back(Num);
            }
            else if(Num < 0)
            {
                Negative.push_back(Num);
            }
        }
        
        vector<int> Result(N);
        for(int i = 0; i < N; i += 2)
        {
            Result[i] = Positive[i / 2];
            Result[i + 1] = Negative[i / 2];
        }
        
        return Result;
    }
};