class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivotIndex = low + rand() % (high - low + 1);
        
        int temp = nums[pivotIndex];
        nums[pivotIndex] = nums[high];
        nums[high] = temp;

        int pivot = nums[high];
        int i = low;

        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
                i++;
            }
        }

        int t = nums[i];
        nums[i] = nums[high];
        nums[high] = t;

        return i;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        int p = partition(nums, low, high);
        quickSort(nums, low, p - 1);
        quickSort(nums, p + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
