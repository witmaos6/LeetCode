class Solution {
public:
    int numberOfSubstrings(string s)
    {
        const int N = static_cast<int>(s.size());
        vector<int> LastIndex(3, -1);
        int Count = 0;

        for(int i = 0; i < N; i++)
        {
            LastIndex[s[i] - 'a'] = i;
            
            if(AllValidIndex(LastIndex))
            {
                int Temp = *min_element(LastIndex.begin(), LastIndex.end());
                Count += 1 + Temp;
            }
        }
        return Count;
    }

private:
    bool AllValidIndex(const vector<int>& Arr)
    {
        for(const int& Num : Arr)
        {
            if(Num == -1)
                return false;
        }
        return true;
    }
};