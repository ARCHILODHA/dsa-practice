int maxActivities(vector<pair<int,int>>& arr) {
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });

    int count = 1, last = arr[0].second;

    for(int i=1;i<arr.size();i++){
        if(arr[i].first >= last){
            count++;
            last = arr[i].second;
        }
    }
    return count;
}
