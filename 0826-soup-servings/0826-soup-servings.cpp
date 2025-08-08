class Solution {
    unordered_map<int, double> Memo;
public:
    double soupServings(int n)
    {
        if(n > 4800)
        {
            return 1.0;
        }
        
        n = (n + 24) / 25;
        
        return DP(n, n);
    }
    
private:
    double DP(int SoupA, int SoupB)
    {
        if(SoupA <= 0 && SoupB <= 0)
        {
            return 0.5;
        }
        if(SoupA <= 0)
        {
            return 1.0;
        }
        if(SoupB <= 0)
        {
            return 0.0;
        }
        
        int Key = SoupA * 5000 + SoupB;
        
        if(Memo.find(Key) != Memo.end())
        {
            return Memo[Key];
        }
        
        double Value = 0.0;
        
        for(int i = 1; i <= 4; i++)
        {
            int NextA = SoupA - i;
            int NextB = SoupB - (4 - i);
            
            Value += 0.25 * DP(NextA, NextB);
        }
        
        Memo[Key] = Value;
        return Memo[Key];
    }
};