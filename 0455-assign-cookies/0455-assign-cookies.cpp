class Solution {
public:
    int findContentChildren(vector<int>& Children, vector<int>& Cookies)
    {
        sort(Children.begin(), Children.end());
        sort(Cookies.begin(), Cookies.end());
        const int N = static_cast<int>(Children.size());
        const int M = static_cast<int>(Cookies.size());
        
        int i = 0;
        int j = 0;
        int Count = 0;
        
        while(i < N && j < M)
        {
            if(Children[i] <= Cookies[j])
            {
                Count++;
                i++;
            }
            j++;
        }
        
        return Count;
    }
};