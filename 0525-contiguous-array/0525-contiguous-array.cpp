class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        unordered_map<int, int> Table;
        int Sum = 0;
        int SubLength = 0;
        
        for(int i = 0; i < N; i++)
        {
            Sum += (nums[i] == 0 ? -1 : 1);
            if(Sum == 0)
            {
                SubLength = i + 1;
            }
            else if(Table.find(Sum) != Table.end())
            {
                SubLength = max(SubLength, i - Table[Sum]);
            }
            else
            {
                Table[Sum] = i;
            }
        }
        return SubLength;
    }
};