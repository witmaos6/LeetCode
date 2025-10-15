class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums)
    {
        vector<int> SubSize;
        int Count = 0;
        int Prev = INT_MIN;
        for(int& Num : nums)
        {
            if(Prev < Num)
            {
                Count++;
            }
            else
            {
                SubSize.push_back(Count);
                Count = 1;
            }
            Prev = Num;
        }
        SubSize.push_back(Count);

        int MaxIS = SubSize.back() / 2;
        const int N = static_cast<int>(SubSize.size());
        for(int i = 0; i < N - 1; i++)
        {
            if(SubSize[i] > 1)
            {
                MaxIS = max(MaxIS, SubSize[i] / 2);
            }
            int Min = min(SubSize[i], SubSize[i + 1]);
            MaxIS = max(MaxIS, Min);
        }
        return MaxIS;
    }
};