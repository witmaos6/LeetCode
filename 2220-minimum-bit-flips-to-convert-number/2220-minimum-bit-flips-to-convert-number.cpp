class Solution {
public:
    int minBitFlips(int start, int goal)
    {
        int Count = 0;
        
        while(start > 0 || goal > 0)
        {
            if((start & 1) != (goal & 1))
            {
                Count++;
            }
            start >>= 1;
            goal >>= 1;
        } 
        
        return Count;
    }
};