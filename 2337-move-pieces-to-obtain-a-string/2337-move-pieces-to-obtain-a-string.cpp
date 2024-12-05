class Solution {
    const char L = 'L';
    const char R = 'R';
    const char Blank = '_';
public:
    bool canChange(string start, string target)
    {
        const int N = static_cast<int>(start.size());
        
        int i = 0;
        int j = 0;
        
        while(i <= N && j <= N)
        {
            while(i < N && start[i] == Blank)
            {
                ++i;
            }
            while(j < N && target[j] == Blank)
            {
                ++j;
            }
            
            if(i == N || j == N)
                return (i == N && j == N);
            
            if(start[i] != target[j])
                return false;
            
            if(target[j] == L)
            {
                if(i < j)
                    return false;
            }
            else
            {
                if(i > j)
                    return false;
            }
            
            ++i;
            ++j;
        }
        
        return true;
    }
};