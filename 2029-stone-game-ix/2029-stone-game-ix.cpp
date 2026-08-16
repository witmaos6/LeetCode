class Solution {
public:
    bool stoneGameIX(vector<int>& stones)
    {
        int A = 0;
        int B = 0;
        int C = 0;

        for(int& Stone : stones)
        {
            if(Stone % 3 == 0)
            {
                A++;
            }
            else if(Stone % 3 == 1)
            {
                B++;
            }
            else 
            {
                C++;
            }
        }
        if(A % 2 == 0)
        {
            return B > 0 && C > 0;
        }
        return abs(B - C) > 2;
    }
};