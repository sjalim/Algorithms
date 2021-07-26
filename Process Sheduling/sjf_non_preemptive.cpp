#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pii;
struct sortSec
{
    constexpr bool operator()(
        pii const &a,
        pii const &b)
        const noexcept
    {
        return a.second.first > b.second.first;
    }
};

int n, mp[500];
vector<pii> proc;
priority_queue<pii, vector<pii>, sortSec> pq;

void check(pii x, int cpuTime)
{

    for (int i = 0; i < n; i++)
    {

        if (mp[proc[i].second.second] == 0 && cpuTime > proc[i].first)
        {

            pq.push(proc[i]);
            mp[proc[i].second.second] = 1;
        }
    }
    if (pq.empty())
    {
        for (int i = 0; i < n; i++)
        {
            if (mp[proc[i].second.second] == 0)
            {
                pq.push(proc[i]);
                break;
            }
        }
    }
}

int main()
{

    pii temp1, temp0;
    cout << "Enter the number of process:" << endl;
    cin >> n;
    int ariv[n], cpu[n], turn[n];
    double sumWait = 0, sumTurn = 0;
    cout << "Enter the cpu times:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> cpu[i];
    }
    cout << "Enter the arival times:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ariv[i];
        proc.push_back(make_pair(ariv[i], make_pair(cpu[i], i)));
    }

    sort(proc.begin(), proc.end());

    int wait[n] = {0}, i = 0;
    pq.push(proc[i]);
    while (!pq.empty())
    {
        if (i == 0)
        {
            temp0 = pq.top();
            wait[temp0.second.second] = temp0.second.first;
        }
        else
        {
            temp1 = pq.top();
            wait[temp1.second.second] += temp1.second.first + wait[temp0.second.second];
            temp0 = temp1;
        }
        mp[temp0.second.second] = 1;
        pq.pop();
        check(temp0, wait[temp0.second.second]);
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        wait[i] = wait[i] - ariv[i] - cpu[i];
        turn[i] = wait[i] + cpu[i];
        sumWait += wait[i];
        sumTurn += turn[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << " Waiting Time: " << wait[i] << " Turnaround Time: " << turn[i] << endl;
    }
    cout << "Average Waiting time: " << sumWait / n << endl;
    cout << "Average Turnaround time: " << sumTurn / n << endl;
}