vector<int> firstNeg(vector<int>& arr, int k){
    deque<int> dq;
    vector<int> res;

    for(int i=0;i<arr.size();i++){
        if(arr[i]<0) dq.push_back(i);

        if(i>=k-1){
            if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            res.push_back(dq.empty()?0:arr[dq.front()]);
        }
    }
    return res;
}
