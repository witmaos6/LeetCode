class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int L = 0, R = 0;
        int Maxsum = 0, Sum = 0;
        vector<int> Table(10001, -1);

        while(R < N)
        {
            if(Table[nums[R]] != -1)
            {
                while(L <= Table[nums[R]])
                {
                    Sum -= nums[L];
                    L++;
                }
            }
            Sum += nums[R];
            Maxsum = max(Maxsum, Sum);
            Table[nums[R]] = R;
            R++;
        }

        return Maxsum;
    }
};