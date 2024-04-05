class Solution {
public:
    int maxDepth(string s)
    {
        int Count = 0;
        int MaxNum = 0;
        for (char C : s)
        {
            if (C == '(')
            {
                Count++;
                if(MaxNum < Count)
                {
                    MaxNum = Count;
                }
                    
            }
            else if (C == ')')
            {
                Count--;
            }
        }
        return MaxNum;
    }
};