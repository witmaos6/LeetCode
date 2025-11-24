class Solution {

public:
    vector<int> sortArray(vector<int>& nums)
    {
        int N = static_cast<int>(nums.size());
        HeapSort(nums, N);

        return nums;
    }

private:
    void HeapSort(vector<int>& nums, const int& N)
    {
        for(int i = (N / 2) - 1; i >= 0; i--)
        {
            Heapify(nums, N, i);
        }
        for(int i = N - 1; i >= 0; i--)
        {
            swap(nums[0], nums[i]);
            Heapify(nums, i, 0);
        }
    }

    void Heapify(vector<int>& nums, int N, int Index)
    {
        int Largest = Index;
		int Left = 2 * Index + 1;
		int Right = 2 * Index + 2;

		if (Left < N && nums[Left] > nums[Largest])
		{
			Largest = Left;
		}

		if (Right < N && nums[Right] > nums[Largest])
		{
			Largest = Right;
		}

		if (Largest != Index)
		{
			swap(nums[Index], nums[Largest]);
			Heapify(nums, N, Largest);
		}
    }
};