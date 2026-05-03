void interleave(queue<int>& q) {
    int n = q.size();
    queue<int> first;

    for(int i = 0; i < n/2; i++) {
        first.push(q.front());
        q.pop();
    }

    while(!first.empty()) {
        q.push(first.front());
        first.pop();

        q.push(q.front());
        q.pop();
    }
}
