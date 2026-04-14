int merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m+1, inv = 0;

    while(i <= m && j <= r) {
        if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else {
            temp.push_back(arr[j++]);
            inv += (m - i + 1);
        }
    }

    while(i <= m) temp.push_back(arr[i++]);
    while(j <= r) temp.push_back(arr[j++]);

    for(int k = l; k <= r; k++) arr[k] = temp[k - l];
    return inv;
}

int mergeSort(vector<int>& arr, int l, int r) {
    if(l >= r) return 0;
    int m = (l + r) / 2;
    return mergeSort(arr, l, m)
         + mergeSort(arr, m+1, r)
         + merge(arr, l, m, r);
}
