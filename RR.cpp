//Round Robin

#include<iostream>
using namespace std;
int main()
{
	int bt[10],rem_bt[10],n,tq,wt[10],t=0,flag=1,tat[10];
	float avwt=0,avtat=0;
	
	cout<<"\n\tEnter the no of processes\t:";
	cin>>n;
	cout<<"\n\tEnter the burst time of the processes\t:";
	
	for(int i=0;i<n;i++)
		{
			cout<<"\n\tProcess"<<i+1<<"\t";
			cin>>bt[i];
			rem_bt[i]=bt[i];
		}
		
	cout<<"\n\tEnter the value of time quantum\t:";
	cin>>tq;
	wt[n]=0;
	int i=0;
	while(true)
	{
		bool flag=true;
		
		for(int i=0;i<n;i++)
		{
			if(rem_bt[i]>0)
			{ 
				flag=false;
				if(rem_bt[i]>tq)
				{
					t=t+tq;
					rem_bt[i]-=tq;
				}
				else
				{	
					t=t+rem_bt[i];
					wt[i]=t-bt[i];
					rem_bt[i]=0;
					tat[i]=bt[i]+wt[i];
				}
			}
		}
		if(flag==true)
		break;
	}

	for(int i=0;i<n;i++)
	{
		cout<<"\n\tProcess"<<"\t\t"<<"Burst Time"<<"\t"<<"Waiting Time"<<"\t"<<"Turn Around Time"<<"\n";
		avwt+=wt[i];
		cout<<"\t P["<<i+1<<"]"<<"\t\t  "<<bt[i]<<"\t\t   "<<wt[i]<<"\t\t      "<<tat[i]<<"\n";
		avtat+=tat[i];
	}
	
	avwt/=n;
	avtat/=n;
	
	cout<<"\n\tAverage Waiting Time:"<<avwt;
	cout<<"\n\tAverage Turnaround Time:"<<avtat;

	return 0;
}
