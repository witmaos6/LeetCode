class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
    {
        int Count = 0;
        for(int& Num1 : arr1)
        {
            for(int& Num2 : arr2)
            {
                if(abs(Num1 - Num2) <= d)
                {
                    Count++;
                    break;
                }
            }
        }
        return arr1.size() - Count;
    }
};