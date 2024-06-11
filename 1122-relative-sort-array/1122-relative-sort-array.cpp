class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        const int N = static_cast<int>(arr1.size());
        int LastIndex = 0;
        int Left = -1;
        
        for(int Num : arr2)
        {
            for(int Right = Left + 1; Right < N; Right++)
            {
                if(arr1[Right] == Num)
                {
                    Left++;
                    swap(arr1[Left], arr1[Right]);
                }
            }
        }
        
        sort(arr1.begin() + Left + 1, arr1.end());
        return arr1;
    }
};