class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        
        const size_t N = arr.size();
        int Diff = arr[1] - arr[0];
        
        for(size_t i = 2; i < N; i++)
        {
            if(arr[i] - arr[i - 1] != Diff)
            {
                return false;
            }
        }
        
        return true;
    }
};