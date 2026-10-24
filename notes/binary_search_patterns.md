# Binary Search Patterns

## 1. Introduction
Binary Search is an efficient searching algorithm that works on sorted arrays or search spaces with a monotonic property.

## 2. Time and Space Complexity
- Time Complexity: O(log N)
- Iterative Space Complexity: O(1)
- Recursive Space Complexity: O(log N)

## 3. Basic Binary Search
```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
