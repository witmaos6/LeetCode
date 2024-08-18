class Solution {
public:
    int nthUglyNumber(int n)
    {
        vector<int> Memo(n);
        Memo[0] = 1;
        
        vector<int> Multiple(3);
        
        for(int i = 1; i < n; i++)
        {
            int TwoMultiple = Memo[Multiple[0]] * 2;
            int ThreeMultiple = Memo[Multiple[1]] * 3;
            int FiveMultiple = Memo[Multiple[2]] * 5;
            
            int Temp = min(ThreeMultiple, FiveMultiple);
            Memo[i] = min(TwoMultiple, Temp);
            
            if(Memo[i] == TwoMultiple)
            {
                Multiple[0]++;
            }
            if(Memo[i] == ThreeMultiple)
            {
                Multiple[1]++;
            }
            if(Memo[i] == FiveMultiple)
            {
                Multiple[2]++;
            }
        }
        
        return Memo.back();
    }
};