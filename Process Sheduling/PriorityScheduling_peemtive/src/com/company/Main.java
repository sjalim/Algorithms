package com.company;


import java.util.*;

class data implements Comparable<data> {
    int ariv;
    int cpu;
    int idx;
    int priority;

    public data() {
    }

    public data(int ariv, int cpu, int idx, int priority) {
        this.ariv = ariv;
        this.cpu = cpu;
        this.idx = idx;
        this.priority = priority;
    }

    @Override
    public int compareTo(data o) {
        int compareAriv = ((data) o).ariv;
        return this.ariv - compareAriv;
    }
}

class dataQ implements Comparable<dataQ> {
    int ariv;
    int cpu;
    int idx;
    int priority;

    public dataQ() {
    }

    public dataQ(int ariv, int cpu, int idx, int priority) {
        this.ariv = ariv;
        this.cpu = cpu;
        this.idx = idx;
        this.priority = priority;
    }


    @Override
    public int compareTo(dataQ o2) {
        if (this.priority < o2.priority) {
            return -1;
        }
        if (this.priority > o2.priority) {
            return 1;
        }
        return 0;
    }


}

class pair implements Comparable<pair> {
    int idx;
    int endPoint;

    public pair() {
    }

    public pair(int idx, int endPoint) {
        this.idx = idx;
        this.endPoint = endPoint;
    }

    @Override
    public int compareTo(pair o) {
        int compareIdx = o.idx;
        return this.idx - compareIdx;
    }
}


public class Main {

    public static void main(String[] args) {

        ArrayList<data> proc = new ArrayList<>();
        PriorityQueue<dataQ> qu = new PriorityQueue<>(50);
        dataQ temp;
        ArrayList<pair> chart = new ArrayList<>();
        Scanner scan = new Scanner(System.in);
        int n;
        System.out.print("Enter the number of process:");
        n = scan.nextInt();

        int arriv[] = new int[n];
        int cpu[] = new int[n];
        int prio[] = new int[n];
        int wait[] = new int[n];
        int end[] = new int[n];

        int maxAriv = 0;

        System.out.print("Enter the cpu times:");
        for (int i = 0; i < n; i++) {
            cpu[i] = scan.nextInt();
        }

        System.out.print("Enter the arrive times:");
        for (int i = 0; i < n; i++) {
            arriv[i] = scan.nextInt();
            maxAriv = Math.max(maxAriv, arriv[i]);

        }

        System.out.print("Enter the priorities:");
        for (int i = 0; i < n; i++) {
            prio[i] = scan.nextInt();

        }
        int mp[] = new int[maxAriv + 1];
        for (int i = 0; i < n; i++) {
            proc.add(new data(arriv[i], cpu[i], i, prio[i]));
            mp[arriv[i]] = i + 1;
        }

        Collections.sort(proc);

        qu.add(new dataQ(proc.get(0).ariv, proc.get(0).cpu, proc.get(0).idx, proc.get(0).priority));
        int j = 1;
        while (!qu.isEmpty()) {

            temp = qu.poll();
            temp.cpu--;
            if (j <= maxAriv) {

                if (mp[j] != 0) {
                    int index = mp[j] - 1;
                    qu.add(new dataQ(arriv[index], cpu[index], index, prio[index]));

                    if (temp.priority > prio[index]) {
                        chart.add(new pair(temp.idx, j));

                    }
                }
            }
            if (temp.cpu != 0) {
                qu.add(temp);
            } else {
                chart.add(new pair(temp.idx, j));
            }
            j++;
        }

        for (pair x : chart) {
            System.out.println(x.idx + " " + x.endPoint);
        }

        Arrays.fill(mp,0);

        int i = 0;
        for (pair x : chart) {
            if (i == 0) {
                end[x.idx] = x.endPoint;
                mp[x.idx] = 1;
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
        for( j =0;j<n;j++)
        {
            System.out.println("p"+(j+1) + " \t\t\t"+ wait[j]+ "\t\t\t" + (wait[j]+cpu[j]));

            sumWait += wait[j];
            sumTurn += wait[j] + cpu[j];
        }
        System.out.println("Average Waiting time:" + sumWait/n);
        System.out.println("Average Turnaround time: " + sumTurn/n);


    }
}



