class Solution {
public:
    int findNumbers(vector<int>& nums)
    {
        int Count = 0;
        for(int& Num : nums)
        {
            if((to_string(Num).size() & 1) == 0)
            {
                Count++;
            }
        }
        return Count;
    }
};