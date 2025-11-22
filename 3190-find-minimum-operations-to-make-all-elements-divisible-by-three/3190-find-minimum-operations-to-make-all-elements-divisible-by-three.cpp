class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int Count = 0;
        for(int& Num : nums)
        {
            if(Num % 3 != 0)
            {
                Count++;
            }
        }
        return Count;
    }
};