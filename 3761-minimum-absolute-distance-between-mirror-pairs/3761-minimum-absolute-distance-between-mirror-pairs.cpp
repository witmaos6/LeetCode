class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums)
    {
        unordered_map<int, int> Table;
        const int N = nums.size();
        int Result = INT_MAX;

        for(int i = N - 1; i >= 0; i--)
        {
            int Reverse = ReverseNum(nums[i]);

            if(Table.count(Reverse))
            {
                int Dist = Table[Reverse] - i;
                Result = min(Result, Dist);
            }
            
            Table[nums[i]] = i;
        }
        return (Result == INT_MAX) ? -1 : Result;
    }

    int ReverseNum(int Num)
    {
        int Reverse = 0;

        while(Num > 0)
        {
            int Digit = Num % 10;
            Num /= 10;

            Reverse = Reverse * 10 + Digit;
        }
        return Reverse;
    }
};