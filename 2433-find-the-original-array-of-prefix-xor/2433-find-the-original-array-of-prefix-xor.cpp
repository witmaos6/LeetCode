class Solution {
public:
    vector<int> findArray(vector<int>& pref)
    {
        const size_t N = pref.size();
        
        vector<int> Origin(N);
        Origin[0] = pref[0];
        
        for(size_t i = 1; i < N; i++)
        {
            Origin[i] = pref[i - 1] ^ pref[i];
        }
        
        return Origin;
    }
};