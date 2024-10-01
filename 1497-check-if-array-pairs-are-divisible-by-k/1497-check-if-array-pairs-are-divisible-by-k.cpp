class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
        vector<int> Freq(k, 0);
        
        for (int Num : arr)
        {
            int Remain = Num % k;
            if (Remain < 0)
            {
                Remain += k;
            }
            
            Freq[Remain]++;
        }
        
        if (Freq[0] % 2 != 0)
        {
            return false;
        }
        
        for (int i = 1; i <= k / 2; i++)
        {
            if (Freq[i] != Freq[k - i])
            {
                return false;
            }
        }
        
        return true;
    }
};