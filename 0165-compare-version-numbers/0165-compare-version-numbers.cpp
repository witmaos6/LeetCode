class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        istringstream SS1(version1);
        string Buffer;
        vector<int> BuffToInt1;
        while(getline(SS1, Buffer, '.'))
        {
            BuffToInt1.push_back(stoi(Buffer));
        }

        istringstream SS2(version2);
        Buffer.clear();
        vector<int> BuffToInt2;
        while(getline(SS2, Buffer, '.'))
        {
            BuffToInt2.push_back(stoi(Buffer));
        }

        const int N = static_cast<int>(BuffToInt1.size());
        const int M = static_cast<int>(BuffToInt2.size());
        int Range = min(N, M);
        for(int i = 0; i < Range; i++)
        {
            if(BuffToInt1[i] > BuffToInt2[i])
            {
                return 1;
            }
            else if(BuffToInt1[i] < BuffToInt2[i])
            {
                return -1;
            }
        }

        if(N > M)
        {
            if(IsBigger(BuffToInt1, Range))
            {
                return 1;
            }
        }
        else if(N < M)
        {
            if(IsBigger(BuffToInt2, Range))
            {
                return -1;
            }
        }

        return 0;
    }

private:
    bool IsBigger(vector<int>& Arr, int Range)
    {
        int N = static_cast<int>(Arr.size());
        for(int i = Range; i < N; i++)
        {
            if(Arr[i] > 0)
            {
                return true;
            }
        }
        return false;
    }
};