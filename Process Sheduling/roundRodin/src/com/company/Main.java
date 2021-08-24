package com.company;

import java.util.*;

class pair {
    int idx;
    int endPoint;

    public pair() {
    }

    public pair(int idx, int endPoint) {
        this.idx = idx;
        this.endPoint = endPoint;
    }
}

class data implements Comparable<data> {
    int ariv;
    int cpu;
    int idx;

    public data(int ariv, int cpu, int idx) {
        this.ariv = ariv;
        this.cpu = cpu;
        this.idx = idx;
    }

    public data() {
    }

    @Override
    public int compareTo(data o) {
        int compareAriv = ((data) o).ariv;
        return this.ariv - compareAriv;
    }
}

public class Main {



    public static void main(String[] args) {

        Deque<data> qu = new ArrayDeque<data>(50);
        ArrayList<data> proc = new ArrayList<>();
        ArrayList<pair> chart = new ArrayList<>();

        data temp;

        int n;
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the number of process:");
        n = scan.nextInt();
        int arriv[] = new int[n];
        int cpu[] = new int[n];

        int wait[] = new int[n];
        int end[] = new int[n];
        int mp[] = new int[n];

        System.out.print("Enter the process arrival times:");
        for (int i = 0; i < n; i++) {
            arriv[i] = scan.nextInt();
        }
        System.out.print("Enter the process cpu times:");
        for (int i = 0; i < n; i++) {
            cpu[i] = scan.nextInt();
        }

        System.out.print("Enter the time quantum:");
        int quantum = scan.nextInt();
        for (int i = 0; i < n; i++) {
            proc.add(new data(arriv[i], cpu[i], i));
        }

        Collections.sort(proc);

        qu.push(proc.get(0));
        int cnt = 0, i = 1;
        while (!qu.isEmpty()) {

            temp = qu.getFirst();
            qu.pop();

            if (temp.cpu >= quantum) {
                temp.cpu -= quantum;
                cnt += quantum;
            } else {
                cnt += temp.cpu;
                temp.cpu = 0;
            }
            chart.add(new pair(temp.idx, cnt));
            if (temp.cpu != 0) {
                if (i < n) {
                    if (proc.get(i).ariv > cnt && qu.isEmpty()) {
                        qu.addFirst(temp);
                    } else {
                        while (proc.get(i).ariv <= cnt) {
//                            System.out.println("check " + proc.get(i).idx + " " + proc.get(i).ariv);
                            qu.addLast(proc.get(i));
                            i++;
                            if (i >= n) {
                                break;
                            }
                        }
                        qu.addLast(temp);
                    }
                } else {
                    qu.addLast(temp);
                }
            }
        }

        i = 0;
        for (pair x : chart) {
            if (i == 0) {
                end[x.idx] = x.endPoint;
            } else {
                if (x.idx == chart.get(i - 1).idx) {
                    end[x.idx] = x.endPoint;
                    mp[x.idx] = 1;
                } else {
                    if (mp[x.idx] != 0) {
                        wait[x.idx] += chart.get(i - 1).endPoint - end[x.idx];
                        end[x.idx] = x.endPoint;
                    } else {
                        mp[x.idx] = 1;
                        end[x.idx] = x.endPoint;
                        wait[x.idx] += chart.get(i - 1).endPoint - arriv[x.idx];
                    }
                }
            }
            i++;
        }
        System.out.println("\tWaiting Time \tTurnAround Time" );
       double sumWait=0,sumTurn =0;
        for(int j =0;j<n;j++)
        {
            System.out.println("p"+(j+1) + " \t\t\t"+ wait[j]+ "\t\t\t" + (wait[j]+cpu[j]));

            sumWait += wait[j];
            sumTurn += wait[j] + cpu[j];
        }
        System.out.println("Average Waiting time:" + sumWait/n);
        System.out.println("Average Turnaround time: " + sumTurn/n);
    }
}
