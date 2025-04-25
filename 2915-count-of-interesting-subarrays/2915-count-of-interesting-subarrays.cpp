class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k)
    {
        long long Reuslt = 0, Count = 0;
        unordered_map<int, long long> Table;
        Table[0] = 1;

        for(int& Num : nums)
        {
            if(Num % modulo == k)
            {
                Count++;
            }
            int Remain = Count % modulo;
            int Temp = (Remain - k + modulo) % modulo;

            Reuslt += Table[Temp];
            Table[Remain]++;
        }
        return Reuslt;
    }
};