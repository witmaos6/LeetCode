class Solution {
public:
    double new21Game(int n, int k, int maxPts)
    {
        if(k == 0 || n >= k - 1 + maxPts)
        {
            return 1.0;
        }
        
        vector<double> Memo(n + 1);
        Memo[0] = 1.0;
        double Probability = 0.0;
        double Temp = 1.0;
        
        for(int i = 1; i <= n; i++)
        {
            Memo[i] = Temp / maxPts;
            
            if(i < k)
            {
                Temp += Memo[i];
            }
            else
            {
                Probability += Memo[i];
            }
            
            if(i >= maxPts)
            {
                Temp -= Memo[i - maxPts];
            }
        }
        
        return Probability;
    }
};