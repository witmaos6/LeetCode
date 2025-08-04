class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        int LastFruit = -1;
        int SecondLastFruit = -1;
        int LastFruitCount = 0;
        int MaxCount = 0;
        int CurrCount = 0;
        
        for(int Fruit: fruits)
        {
            if(Fruit == LastFruit || Fruit == SecondLastFruit)
            {
                CurrCount++;
            }
            else
            {
                CurrCount = LastFruitCount + 1;
            }

            if(Fruit == LastFruit)
            {
                LastFruitCount++;
            }
            else
            {
                LastFruitCount = 1;
                SecondLastFruit = LastFruit;
                LastFruit = Fruit;
            }
            MaxCount = max(MaxCount, CurrCount);
        }
        return MaxCount;
    }
};