struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for(auto &j : jobs) maxDeadline = max(maxDeadline, j.deadline);

    vector<int> slot(maxDeadline + 1, -1);
    int profit = 0;

    for(auto &job : jobs) {
        for(int d = job.deadline; d > 0; d--) {
            if(slot[d] == -1) {
                slot[d] = job.id;
                profit += job.profit;
                break;
            }
        }
    }
    return profit;
}
