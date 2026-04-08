int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());

    int i=0,j=0,plat=0,res=0;

    while(i<arr.size()){
        if(arr[i]<=dep[j]){
            plat++; i++;
        } else {
            plat--; j++;
        }
        res=max(res,plat);
    }
    return res;
}
