class Solution {
public:
    int numberOfMatches(int n)
    {
        int MatchCount = 0;
        while(n > 1)
        {
            int Temp = n >> 1;
            int Match = (n & 1) ? Temp + 1 : Temp;
            MatchCount += Match;
            n >>= 1;
        }
        
        return MatchCount;
    }
};