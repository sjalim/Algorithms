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

    public static void shwq(PriorityQueue<data> x) {

        while (!x.isEmpty()) {
            System.out.println(x.poll().idx);
        }
        System.out.println("\n");

    }

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

        System.out.print("Enter the cpu times:");
        for (int i = 0; i < n; i++) {
            cpu[i] = scan.nextInt();
        }

        System.out.print("Enter the arrive times:");
        for (int i = 0; i < n; i++) {
            arriv[i] = scan.nextInt();
        }

        System.out.print("Enter the priorities:");
        for (int i = 0; i < n; i++) {
            prio[i] = scan.nextInt();

        }

        for (int i = 0; i < n; i++) {
            proc.add(new data(arriv[i], cpu[i], i, prio[i]));
        }

        Collections.sort(proc);

        qu.add(new dataQ(proc.get(0).ariv,proc.get(0).cpu,proc.get(0).idx,proc.get(0).priority));
        int cnt = 0, i = 1;
        while (!qu.isEmpty()) {
//            PriorityQueue<data> r = qu;
//            shwq(qu);
//            qu = r;

            qu.forEach(data -> System.out.println(data.idx));
            System.out.println("");
            temp = qu.poll();

            cnt += temp.cpu;
            chart.add(new pair(temp.idx, cnt));

            if (i < n) {
                while (proc.get(i).ariv <= cnt) {
                    qu.add(new dataQ(proc.get(i).ariv,proc.get(i).cpu,proc.get(i).idx,proc.get(i).priority));
                    i++;
                    if (i >= n) {
                        break;
                    }
                }

            }
        }

//        for (pair x : chart) {
//            System.out.println(x.idx + " " + x.endPoint);
//        }


//        Collections.sort(chart);

        int j =0;
        for(pair x : chart)
        {


            if(j ==0)
            {
                wait[x.idx] = 0;
            }
            else
            {
                wait[x.idx] = chart.get(j-1).endPoint - arriv[x.idx];
            }

            j++;
        }
        System.out.println("\t\tWaiting Time\tTurnaround Time");

        double sumWait =0,sumTurn =0;
        for(int k =0;k<n;k++)
        {
            System.out.println("p"+(k+1)+ " \t\t\t" + wait[k] + "\t\t\t" + (wait[k]+cpu[k]));
            sumWait += wait[k];
            sumTurn += wait[k] + cpu[k];
        }

        System.out.println("Average Waiting Time:" + sumWait/n);
        System.out.println("Average Turnaround Time:"+sumTurn/n);

    }
}
