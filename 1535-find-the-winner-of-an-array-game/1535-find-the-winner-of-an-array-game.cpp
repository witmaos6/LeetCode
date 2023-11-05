class Solution {
public:
    int getWinner(vector<int>& arr, int k)
    {
        const int N = static_cast<int>(arr.size());
        if(k == 1)
        {
            return max(arr[0], arr[1]);
        }
        if(k >= N)
        {
            return *max_element(arr.begin(), arr.end());
        }
        
        int CurrentWinner = arr[0];
        int WinCount = 0;
        
        for(int i = 1; i < N; i++)
        {
            if(CurrentWinner > arr[i])
            {
                WinCount++;
            }
            else
            {
                CurrentWinner = arr[i];
                WinCount = 1;
            }
            
            if(WinCount == k)
            {
                return CurrentWinner;
            }
        }
        
        return CurrentWinner;
    }
};