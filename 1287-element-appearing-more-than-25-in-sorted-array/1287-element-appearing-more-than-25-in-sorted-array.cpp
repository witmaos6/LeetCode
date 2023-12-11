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
            if(Table[Num] > More25)
            {
                return Num;
            }
        }
        return -1;
    }
};