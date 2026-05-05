string simplifyPath(string path) {
    stack<string> st;
    string curr;

    for(int i = 0; i <= path.size(); i++) {
        if(i == path.size() || path[i] == '/') {
            if(curr == "..") {
                if(!st.empty()) st.pop();
            }
            else if(curr != "" && curr != ".") {
                st.push(curr);
            }
            curr = "";
        } else {
            curr += path[i];
        }
    }

    string res = "";
    while(!st.empty()) {
        res = "/" + st.top() + res;
        st.pop();
    }

    return res.empty() ? "/" : res;
}
