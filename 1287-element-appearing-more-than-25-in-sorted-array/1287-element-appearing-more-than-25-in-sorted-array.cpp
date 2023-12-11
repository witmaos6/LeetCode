class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());
        if(N == 1)
        {
            return arr[0];
        }
        const int More25 = N / 4;
        int Freq = 1;
        
        for(int i = 0; i < N - 1; i++)
        {
            if(arr[i] == arr[i + 1])
            {
                Freq++;
                
                if(Freq > More25)
                {
                    return arr[i];
                }
            }
            else
            {
                Freq = 1;
            }
        }
        
        return -1;
    }
};