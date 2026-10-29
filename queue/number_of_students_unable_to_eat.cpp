#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for (int student : students) {
            q.push(student);
        }

        int index = 0;
        int rotations = 0;
        int n = students.size();

        while (!q.empty() && index < n && rotations < q.size()) {
            if (q.front() == sandwiches[index]) {
                q.pop();
                index++;
                rotations = 0;
            } else {
                q.push(q.front());
                q.pop();
                rotations++;
            }
        }

        return q.size();
    }
};
