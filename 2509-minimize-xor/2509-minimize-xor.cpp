class Solution {
public:
    int minimizeXor(int num1, int num2)
    {
        int Num2BitCount = GetBitCount(num2);
        
        int FindNum = 0;
        for(int i = 31; i>= 0; i--)
        {
            int Mark = (1 << i);
            
            if(Mark & num1)
            {
                if(Num2BitCount > 0)
                {
                    FindNum |= Mark;
                    Num2BitCount--;
                }
            }
        }

        for(int i = 0; i < 32; i++)
        {
            if(Num2BitCount <= 0)
                break;

            int Mark = (1 << i);

            if((FindNum & Mark) == 0)
            {
                FindNum |= Mark;
                Num2BitCount--;
            }
        }

        return FindNum;
    }

private:
    int GetBitCount(int Num)
    {
        int Count = 0;
        while(Num > 0)
        {
            if((Num % 2) == 1)
            {
                Count++;
            }
            Num /= 2;
        }
        return Count;
    }
};