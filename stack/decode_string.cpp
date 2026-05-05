string decodeString(string s) {
    stack<int> count;
    stack<string> st;
    string curr = "";
    int num = 0;

    for(char c : s) {
        if(isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else if(c == '[') {
            count.push(num);
            st.push(curr);
            num = 0;
            curr = "";
        }
        else if(c == ']') {
            string temp = curr;
            curr = st.top(); st.pop();

            int k = count.top(); count.pop();
            while(k--) curr += temp;
        }
        else {
            curr += c;
        }
    }
    return curr;
}
