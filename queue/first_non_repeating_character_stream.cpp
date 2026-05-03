string firstNonRepeating(string s) {
    vector<int> freq(26, 0);
    queue<char> q;
    string result;

    for(char c : s) {
        freq[c - 'a']++;
        q.push(c);

        while(!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        result += q.empty() ? '#' : q.front();
    }
    return result;
}
