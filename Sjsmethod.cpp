   // sjs can be divided into two types 
   // 1. non- preemptive
   // 2. preemptive  


        // SJS NON-PREEMPTIVE
//         #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of processes: ";
//     cin >> n;

//     int bt[20], wt[20], tat[20], p[20];

//     for (int i = 0; i < n; i++) {
//         p[i] = i + 1;
//         cout << "Enter Burst Time for P" << i + 1 << ": ";
//         cin >> bt[i];
//     }

//     // Sort according to Burst Time
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (bt[i] > bt[j]) {
//                 swap(bt[i], bt[j]);
//                 swap(p[i], p[j]);
//             }
//         }
//     }

//     wt[0] = 0;

//     for (int i = 1; i < n; i++) {
//         wt[i] = wt[i - 1] + bt[i - 1];
//     }

//     for (int i = 0; i < n; i++) {
//         tat[i] = wt[i] + bt[i];
//     }

//     cout << "\nProcess\tBT\tWT\tTAT\n";

//     for (int i = 0; i < n; i++) {
//         cout << "P" << p[i] << "\t"
//              << bt[i] << "\t"
//              << wt[i] << "\t"
//              << tat[i] << endl;
//     }

//     return 0;
// }

   //  SJF -PREEMPTIVE (STRF)
   #include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[20], bt[20], rt[20];
    int ct[20], wt[20], tat[20];

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for P"
             << i + 1 << ": ";
        cin >> at[i] >> bt[i];

        rt[i] = bt[i];
    }

    int completed = 0;
    int time = 0;

    while (completed < n) {

        int shortest = -1;
        int minRT = 9999;

        // Find process with shortest remaining time
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < minRT) {
                minRT = rt[i];
                shortest = i;
            }
        }

        // If no process has arrived
        if (shortest == -1) {
            time++;
            continue;
        }

        // Execute for 1 unit
        rt[shortest]--;
        time++;

        // Process completed
        if (rt[shortest] == 0) {
            completed++;

            ct[shortest] = time;

            tat[shortest] = ct[shortest] - at[shortest];

            wt[shortest] = tat[shortest] - bt[shortest];

            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
    }

    cout << "\nProcess\tAT\tBT\tCT\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;
}