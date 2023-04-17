class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold)
    {
        int N = static_cast<int>(arr.size());
        
        int Value = 0;
        
        for(int i = 0; i < k; i++)
        {
            Value += arr[i];
        }
        
        int Result = 0;
        int i = 0;
        
        while(i + k - 1 < N)
        {
            if(Value / k >= threshold)
            {
                Result++;
            }
            Value -= arr[i];
            
            if(i + k < N)
            {
                Value += arr[i + k];
            }
            else
            {
                break;
            }
            i++;
        }
        
        return Result;
    }
};