class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> BuffToInt1 = SplitString(version1);
        vector<int> BuffToInt2 = SplitString(version2);

        const int N = static_cast<int>(BuffToInt1.size());
        const int M = static_cast<int>(BuffToInt2.size());
        int Range = max(N, M);

        for(int i = 0; i < Range; i++)
        {
            int Num1 = (i < N) ? BuffToInt1[i] : 0;
            int Num2 = (i < M) ? BuffToInt2[i] : 0;

            if(Num1 > Num2)
            {
                return 1;
            }
            else if(Num1 < Num2)
            {
                return -1;
            }
        }

        return 0;
    }
    
    vector<int> SplitString(const string& Str)
    {
        istringstream SS1(Str);
        string Buffer;
        vector<int> BuffToInt;
        while(getline(SS1, Buffer, '.'))
        {
            BuffToInt.push_back(stoi(Buffer));
        }
        return BuffToInt;
    }
};