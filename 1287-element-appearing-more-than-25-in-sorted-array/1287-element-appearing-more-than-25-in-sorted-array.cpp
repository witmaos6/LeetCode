class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());
        const int More25 = N / 4;
        
        vector<int> Table(100001);
        for(int Num : arr)
        {
            Table[Num]++;
        }
        
        for(int i = 0; i < 100001; i++)
        {
            if(Table[i] > More25)
            {
                return i;
            }
        }
        return -1;
    }
};