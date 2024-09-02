class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        const int N = static_cast<int>(chalk.size());
        long long PrefixSum = 0;
        
        for(int i = 0; i < N; i++)
        {
            PrefixSum += chalk[i];
        }
        
        int RemainingChalk = k % PrefixSum;
        
        for(int i = 0; i < N; i++)
        {
            if(RemainingChalk < chalk[i])
            {
                return i;
            }
            RemainingChalk -= chalk[i];
        }
        
        return 0;
    }
};