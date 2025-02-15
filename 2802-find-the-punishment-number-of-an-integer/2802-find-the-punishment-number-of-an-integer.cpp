class Solution {
public:
    int punishmentNumber(int n)
    {
        int Sum = 0;
        for(int i = 1; i <= n; i++)
        {
            const int Square = i * i;

            Sum += Partition(Square, i) ? Square : 0;
        }
        return Sum;
    }

private:
    bool Partition(const int Square, int Target)
    {
        if(Square == Target)
            return true;

        if(Square == 0)
            return Target == 0;

        const int PartitionRange = min(Square, 1000);

        for(int PartitionSize = 10; PartitionSize <= PartitionRange; PartitionSize *= 10)
        {
            if(Partition(Square / PartitionSize, Target - Square % PartitionSize))
                return true;
        }
        return 0;
    }
};