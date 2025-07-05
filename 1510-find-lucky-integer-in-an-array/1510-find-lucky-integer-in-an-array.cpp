class Solution {
public:
    int findLucky(vector<int>& arr)
    {
        array<int, 501> Table;
        for(int& Num : arr)
        {
            Table[Num]++;
        }

        int Lucky = -1;
        for(int i = 1; i < 501; i++)
        {
            if(i == Table[i])
            {
                Lucky = i;
            }
        }
        return Lucky;
    }
};