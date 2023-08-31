class Solution {
public:
    int minTaps(int n, vector<int>& ranges)
    {
        vector<int> Memo(n + 1);
        const int RangeSize = static_cast<int>(ranges.size());
        
        for(int i = 0; i < RangeSize; i++)
        {
            if(ranges[i] != 0)
            {
                int Left = max(0, i - ranges[i]);
                Memo[Left] = max(Memo[Left], i + ranges[i]);
            }
        }
        
        int End = 0;
        int Reach = 0;
        int Count = 0;
        
        for(int i = 0; i <= n; i++)
        {
            if(i > End)
            {
                if(Reach <= End)
                {
                    return -1;
                }
                
                End = Reach;
                Count++;
            }
            Reach = max(Reach, Memo[i]);
        }
        
        if(End < n)
        {
            Count++;
        }
        return Count;
    }
};