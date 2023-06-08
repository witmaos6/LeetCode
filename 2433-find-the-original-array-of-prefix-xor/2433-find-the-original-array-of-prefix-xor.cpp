class Solution {
public:
    vector<int> findArray(vector<int>& pref)
    {
        const size_t N = pref.size();
        
        vector<int> Origin(N);
        Origin[0] = pref[0];
        
        for(size_t i = 1; i < N; i++)
        {
            Origin[i] = GetOrigin(pref[i - 1], pref[i]);
        }
        
        return Origin;
    }
    
private:
    int GetOrigin(int Value, int Result)
    {
        int Origin = 0;
        int Coefficient = 1;
        
        while(Value || Result)
        {
            if(Result & 1)
            {
                if((Value & 1) == 0)
                {
                    Origin += Coefficient;
                }
            }
            else
            {
                if(Value & 1)
                {
                    Origin += Coefficient;
                }
            }
            Coefficient <<= 1;
            
            Value >>= 1;
            Result >>= 1;
        }
        
        return Origin;
    }
};