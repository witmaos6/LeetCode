class Solution {
public:
    int countVowelPermutation(int n)
    {
        const int Mod = 1e9 + 7;
        const int A = 0;
        const int E = 1;
        const int I = 2;
        const int O = 3;
        const int U = 4;
        
        vector<long long> Vowels(5, 1);
        vector<long long> Next(5);
        
        for(int i = 1; i < n; i++)
        {
            Next[A] = Vowels[E];
            Next[E] = (Vowels[A] + Vowels[I]) % Mod;
            Next[I] = (Vowels[A] + Vowels[E] + Vowels[O] + Vowels[U]) % Mod;
            Next[O] = (Vowels[I] + Vowels[U]) % Mod;
            Next[U] = Vowels[A];
            
            for(int j = 0; j < 5; j++)
            {
                Vowels[j] = Next[j];
            }
        }
        
        long long Result = 0;
        for(int i = 0; i < 5; i++)
        {
            Result = (Result + Vowels[i]) % Mod;
        }
        return static_cast<int>(Result);
    }
};