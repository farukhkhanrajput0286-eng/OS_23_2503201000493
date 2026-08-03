#include <iostream>
using namespace std;

class Process
{
public:
    int pid;
    int at;     // Arrival Time
    int bt;     // Burst Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
};

int main()
{
    int n;

    cout << "Enter Number of Processes : ";
    cin >> n;

    Process p[20];

    // Input
    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        cout << "\nProcess P" << p[i].pid << endl;

        cout << "Arrival Time : ";
        cin >> p[i].at;

        cout << "Burst Time : ";
        cin >> p[i].bt;
    }

    // Sort according to Arrival Time (Bubble Sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate Completion Time
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            p[i].ct = p[i].at + p[i].bt;
        }
        else
        {
            if (p[i].at > p[i - 1].ct)
            {
                p[i].ct = p[i].at + p[i].bt;
            }
            else
            {
                p[i].ct = p[i - 1].ct + p[i].bt;
            }
        }

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Display Gantt Chart
    cout << "\n\nGantt Chart:\n";
    cout << "|";

    for (int i = 0; i < n; i++)
    {
        cout << " P" << p[i].pid << " |";
    }

    cout << "\n";

    if (n > 0)
    {
        cout << p[0].at;

        for (int i = 0; i < n; i++)
        {
            cout << "    " << p[i].ct;
        }

        cout << endl;
    }

    // Output Table
    float avgWT = 0;
    float avgTAT = 0;

    cout << "\n-----------------------------------------------------------------\n";
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "-----------------------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << "P" << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << endl;

        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    cout << "-----------------------------------------------------------------\n";

    cout << "\nAverage Waiting Time = " << avgWT / n << endl;
    cout << "Average Turnaround Time = " << avgTAT / n << endl;

    return 0;
}