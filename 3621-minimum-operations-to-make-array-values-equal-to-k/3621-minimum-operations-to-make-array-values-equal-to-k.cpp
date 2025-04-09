class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        vector<int> Table(101);
        for(int& Num : nums)
        {
            if(Num < k)
                return -1;

            Table[Num]++;
        }

        int Count = 0;
        for(int i = 100; i > k; i--)
        {
            if(Table[i] > 0)
            {
                Count++;
            }
        }
        return Count;
    }
};