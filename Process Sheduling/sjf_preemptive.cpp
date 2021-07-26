#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
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
int main()
{

    int n, sumCpu = 0;
    pii temp, nw;
    vector<pii> proc;
    vector<pi> gnCrt;
    priority_queue<pii, vector<pii>, sortSec> pq;
    cout << "enter the number of process:";
    cin >> n;

    int ariv[n], cpu[n], wait[n] = {0}, endTime[n] = {0}, turn[n];

    cout << "Enter the arrival times for the processes:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ariv[i];
    }

    cout << "Enter the cpu times for the processes:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> cpu[i];
        sumCpu += cpu[i];
    }

    for (int i = 0; i < n; i++)
    {
        proc.push_back(make_pair(ariv[i], make_pair(cpu[i], i)));
    }
    sort(proc.begin(), proc.end());
    pq.push(proc[0]);

    int mpAriv[sumCpu] = {0};

    for (int i = 1; i < n; i++)
    {
        mpAriv[ariv[i]] = i;
    }
    int cnt = 0;
    while (!pq.empty())
    {
        temp = pq.top();
        if (mpAriv[cnt])
        {
            for (int i = 0; i < n; i++)
            {
                if (proc[i].second.second == mpAriv[cnt])
                {
                    nw = proc[i];
                    pq.push(proc[i]);
                    break;
                }
            }
            if (temp.second.first > nw.second.first)
            {
                gnCrt.push_back(make_pair(temp.second.second, cnt));
            }
        }

        temp = pq.top();
        temp.second.first--;
        pq.pop();
        cnt++;
        if (temp.second.first)
        {
            pq.push(temp);
        }
        else
        {
            gnCrt.push_back(make_pair(temp.second.second, cnt));
        }
    }

    for (int i = 0; i < gnCrt.size(); i++)
    {

        if (i > 0)
        {
            wait[gnCrt[i].first] += gnCrt[i - 1].second - endTime[gnCrt[i].first];
        }
        endTime[gnCrt[i].first] = gnCrt[i].second;
    }

    double sumWait = 0, sumTurn = 0;
    for (int i = 0; i < n; i++)
    {
        wait[i] = wait[i] - ariv[i];
        turn[i] = wait[i] + cpu[i];
        sumWait += wait[i];
        sumTurn += turn[i];
    }
    cout << "process\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << wait[i] << "\t" << turn[i] << endl;
    }

    cout << "Average Waiting Time:" << sumWait / n << endl;
    cout << "Average Turnaround Time:" << sumTurn / n << endl;
}