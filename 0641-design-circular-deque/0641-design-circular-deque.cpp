class MyCircularDeque {
    vector<int> Deque;
    int Front = 0;
    int Last = 0;
    int Size = 0;
    int Capacity = 0;
public:
    MyCircularDeque(int k)
    {
        Deque = vector<int>(k, -1);
        Front = 0;
        Last = 0;
        Size = 0;
        Capacity = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
        {
            return false;
        }

        if (Front == 0)
        {
            Front = Capacity - 1;
        } 
        else
        {
            Front--;
        }

        Deque[Front] = value;
        Size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
        {
            return false;
        }

        Deque[Last] = value;

        if (Last == Capacity - 1)
        {
            Last = 0;
        } 
        else
        {
            Last++;
        }
        
        Size++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }

        Deque[Front] = -1;

        if (Front == Capacity - 1)
        {
            Front = 0;
        } 
        else
        {
            Front++;
        }
        
        Size--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }

        if (Last == 0)
        {
            Last = Capacity - 1;
        } 
        else 
        {
            Last--;
        }
        Deque[Last] = -1;
        
        Size--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        
        return Deque[Front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        if (Last == 0)
        {
            return Deque[Capacity - 1];
        } 

        return Deque[Last - 1];
    }

    bool isEmpty() { return (Size == 0); }

    bool isFull() { return (Size == Capacity); }
};