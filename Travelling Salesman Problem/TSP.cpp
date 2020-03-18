#include<iostream>

using namespace std;

int ary[10][10],completed[10],n,cost=0;

void takeInput()
{
	int i,j;

	cout<<"Enter the number of nodes: ";
	cin>>n;

	cout<<"\nEnter the Cost Matrix\n";

	for(i=0;i < n;i++)
	{
		cout<<"\nEnter Elements of "<<i+1<<" Row: \n";

		for( j=0;j < n;j++)
			cin>>ary[i][j];

		completed[i]=0;
	}

	cout<<"\n\nThe cost list is:";

	for( i=0;i < n;i++)
	{
		cout<<"\n";

		for(j=0;j < n;j++)
			cout<<"\t"<<ary[i][j];
	}
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;

	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}

	if(min!=999)
		cost+=kmin;

	return nc;
}

void mincost(int matrix)
{
	int i,nmatrix;

	completed[matrix]=1;

	cout<<matrix+1<<"--->";
	nmatrix=least(matrix);

	if(nmatrix==999)
	{
		nmatrix=0;
		cout<<nmatrix+1;
		cost+=ary[matrix][nmatrix];

		return;
	}

	mincost(nmatrix);
}

int main()
{
	takeInput();

	cout<<"\n\nThe Path is:\n";
	mincost(0); //passing 0 because starting vertex

	cout<<"\n\nMinimum cost is "<<cost;

	return 0;
}
