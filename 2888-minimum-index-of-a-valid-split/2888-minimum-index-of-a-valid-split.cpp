class Solution {
public:
    int minimumIndex(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());

        int Count = 0;
        int X = 0;
        for(int& Num : nums)
        {
            if(Count == 0)
            {
                X = Num;
            }
            Count += (X == Num) ? 1 : -1;
        }

        int CountX = count(nums.begin(), nums.end(), X);
        int CountNum = 0;
        for(int i = 0; i < N; i++)
        {
            CountNum += (nums[i] == X);
            if(CountNum * 2 > (i + 1) && ((CountX - CountNum) * 2 > N - i - 1))
            {
                return i;
            }
        }
        return -1;
    }
};