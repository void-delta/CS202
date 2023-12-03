#include <iostream>
#include <algorithm>
using namespace std;

class Job {
public:
    int no;
    int profit;
    int deadline;
};

bool compare(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

void job_sequencing(Job *jobs, int num, int time) {
    Job *job_final = new Job[time];
    bool *slot = new bool[time];
    for (int i = 0; i < time; i++)
        slot[i] = false;

    for (int i = 0; i < num; i++) {
        // Find a free slot for this job 
        // (Note that we start from the last possible slot)
        for (int j = min(time, jobs[i].deadline) - 1; j >= 0; j--) {
            // Free slot found
            if (slot[j] == false) {
                job_final[j] = jobs[i]; // Add this job to result
                slot[j] = true;         // Make this slot occupied
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < time; i++) {
        sum += job_final[i].profit;
    }
    cout << "The profit is " << sum;
}

int main() {
    int n, t;
    cin >> n >> t;
    Job *jobs = new Job[n];
    for (int i = 0; i < n; i++) {
        int num, pr, dl;
        cin >> num >> pr >> dl;
        jobs[i].no = num;
        jobs[i].profit = pr;
        jobs[i].deadline = dl;
    }

    sort(jobs, jobs + n, compare);
    job_sequencing(jobs, n, t);

    delete[] jobs;

    return 0;
}
