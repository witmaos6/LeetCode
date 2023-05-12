class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions)
    {
        const int N = static_cast<int>(questions.size());
        
        vector<long long> Memo(N + 1);
        
        for(int i = N - 1; i >= 0; i--)
        {
            int Prev = questions[i][1] + i + 1;
            int ValidPrev = min(Prev, N);
            
            long long CurrPoint = questions[i][0] + Memo[ValidPrev];
            
            Memo[i] = max(CurrPoint, Memo[i + 1]);
        }
        
        return Memo[0];
    }
};