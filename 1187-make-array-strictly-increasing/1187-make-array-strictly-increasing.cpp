class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        
        const int N = static_cast<int>(arr1.size());
        arr1.insert(arr1.begin(), INT_MIN);
        arr1.push_back(INT_MAX);
        
        vector<int> Memo(N + 2, INT_MAX);
        Memo[0] = 0;
        
        for(int i = 1; i < N + 2; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(arr1[j] < arr1[i] && Memo[j] != INT_MAX)
                {
                    int Change = GetValidNum(arr1, arr2, j, i);
                    
                    if(Change >= 0)
                    {
                        Memo[i] = min(Memo[i], Memo[j] + Change);
                    }
                }
            }
        }
        
        if(Memo[N + 1] != INT_MAX)
        {
            return Memo[N + 1];
        }
        
        return -1;
    }
private:
    int GetValidNum(vector<int>& Arr1, vector<int>& Arr2, int Begin, int End)
    {
        if(Begin + 1 == End)
        {
            return 0;
        }
        
        int MinValue = Arr1[Begin];
        int MaxValue = Arr1[End];
        
        int Index = upper_bound(Arr2.begin(), Arr2.end(), MinValue) - Arr2.begin();
        
        int MaxCount = End - Begin - 1;
        int EndIndex = Index + MaxCount - 1;
        
        if(EndIndex < Arr2.size() && Arr2[EndIndex] < MaxValue)
        {
            return MaxCount;
        }
        return -1;
    }
};