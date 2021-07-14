#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double avgWait = 0, avgTurn = 0;
    vector<pair<int, int>> proc;

    cout << "Enter the number of process:";
    cin >> n;

    int ariv[n], cpu[n], start[n], wait[n], turn[n];

    cout << "Enter the CPU times:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> cpu[i];
    }
    cout << "Enter the arrival times:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> ariv[i];
    }

    for (int i = 0; i < n; i++)
    {

        proc.push_back(make_pair(ariv[i], i));
    }

    sort(proc.begin(), proc.end());
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            start[proc[i].second] = 0;
        }
        else
        {
            start[proc[i].second] = (cpu[proc[i - 1].second] + start[proc[i - 1].second]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        wait[i] = start[i] - ariv[i];
        turn[i] = wait[i] + cpu[i];

        avgWait += wait[i];
        avgTurn += turn[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << "Waiting Time: " << wait[i] << " Turnaround Time: " << turn[i] << endl;
    }
    cout << "Average Waiting time: " << avgWait / n << endl;
    cout << "Average Turnaround time: " << avgTurn / n << endl;
}