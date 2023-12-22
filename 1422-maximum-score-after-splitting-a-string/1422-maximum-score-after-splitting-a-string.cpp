class Solution {
public:
    int maxScore(string s)
    {
        const size_t N = s.size();
        int LeftZeros = (s[0] == '0') ? 1 : 0;
        int RightOnes = 0;
        for(size_t i = 1; i < N; i++)
        {
            if(s[i] == '1')
            {
                RightOnes++;
            }
        }
        
        int MaxScore = LeftZeros + RightOnes;
        for(size_t i = 1; i < N - 1; i++)
        {
            if(s[i] == '1')
            {
                RightOnes--;
            }
            else if(s[i] == '0')
            {
                LeftZeros++;
            }
            
            MaxScore = max(MaxScore, LeftZeros + RightOnes);
        }
        
        return MaxScore;
    }
};