class Solution {
public:
    int maxDiff(int num)
    {
        string Str1 = to_string(num);
        string Str2 = Str1;
        const int N = static_cast<int>(Str1.size());

        int Index = 0;
        for(int i = 0; i < N; i++)
        {
            if(Str1[i] != '9')
            {
                Index = i;
                break;
            }
        }

        char Ele1 = Str1[Index];
        for(int i = 0; i < N; i++)
        {
            if(Str1[i] == Ele1) Str1[i] = '9';
        }
        
        char Ele2 = Str2[0];
        char Replace = '1';
        if(Ele2 == '1')
        {
            for(int i = 1; i < N; i++)
            {
                if(Str2[i] != '0' && Str2[i] != '1')
                {
                    Ele2 = Str2[i];
                    Replace = '0';
                    break;
                }
            }
        }

        for(int i = 0; i < N; i++)
        {
            if(Str2[i] == Ele2)
            {
                Str2[i] = Replace;
            }
        }

        return stoi(Str1) - stoi(Str2);
    }
};