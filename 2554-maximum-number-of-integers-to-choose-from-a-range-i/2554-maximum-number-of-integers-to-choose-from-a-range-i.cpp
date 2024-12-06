class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {
        vector<bool> BannedTable(n + 1);
        for(int& Num : banned)
        {
            if(Num <= n)
            {
                BannedTable[Num] = true;
            }
        }
        
        int Sum = 0;
        int Count = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(BannedTable[i] == false)
            {
                if(Sum + i > maxSum)
                    break;
                
                Sum += i;
                ++Count;
            }
        }
        
        return Count;
    }
};