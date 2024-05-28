class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        const int N = static_cast<int>(s.size());
        int MaxLength = 0;
        int CurrCost = 0;
        int Left = 0;
        
        for(int Right = 0; Right < N; Right++)
        {
            int Cost = abs(s[Right] - t[Right]);
            CurrCost += Cost;
            
            while(CurrCost > maxCost)
            {
                int LeftCost = abs(s[Left] - t[Left]);
                CurrCost -= LeftCost;
                Left++;
            }
            
            MaxLength = max(MaxLength, Right - Left + 1);
        }
        
        return MaxLength;
    }
};