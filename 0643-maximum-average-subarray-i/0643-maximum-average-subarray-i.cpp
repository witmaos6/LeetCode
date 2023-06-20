class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        const int N = static_cast<int>(nums.size());
        
        double PrefixSum = 0;
        double MaxAvgs = INT_MIN;
        int NrOfSum = 1;
        
        for(int i = 0; i < N; i++)
        {
            PrefixSum += static_cast<int>(nums[i]);
            
            if(NrOfSum == k)
            {
                double Temp = PrefixSum / k;
                MaxAvgs = max(MaxAvgs, Temp);
                
                PrefixSum -= nums[i - k + 1];
            }
            else
            {
                NrOfSum++;
            }
        }
        
        return MaxAvgs;
    }
};