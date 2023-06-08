class Solution {
public:
    vector<int> findArray(vector<int>& pref)
    {
        const size_t N = pref.size();
        
        int Prev = 0;
        for(size_t i = 1; i < N; i++)
        {
            Prev ^= pref[i - 1];
            pref[i] ^= Prev;
        }
        
        return pref;
    }
};