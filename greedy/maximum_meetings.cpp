#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start;
    int end;
};

// Select maximum number of non-overlapping meetings.
int maximumMeetings(vector<Meeting>& meetings) {
    sort(meetings.begin(), meetings.end(),
         [](const Meeting& a, const Meeting& b) {
             return a.end < b.end;
         });

    int count = 0;
    int lastEnd = -1;

    for (auto& meeting : meetings) {
        if (meeting.start > lastEnd) {
            count++;
            lastEnd = meeting.end;
        }
    }

    return count;
}
