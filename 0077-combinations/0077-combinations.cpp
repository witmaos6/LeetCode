class Solution {
    vector<vector<int>> Combines;
public:
    vector<vector<int>> combine(int n, int k)
    {
        int PossibleBegin = n - k + 1;
        
        for(int i = 1; i <= PossibleBegin; i++)
        {
            vector<int> Temp = {i};
            
            SetCombine(n, k, i + 1, Temp);
        }
        
        return Combines;
    }
    
private:
    void SetCombine(int N, int K, int Num, vector<int>& Temp)
    {
        if(Temp.size() == K)
        {
            Combines.push_back(Temp);
            return;
        }
        
        for(int i = Num; i <= N; i++)
        {
            Temp.push_back(i);
            
            SetCombine(N, K, i + 1, Temp);
            
            Temp.pop_back();
        }
    }
};