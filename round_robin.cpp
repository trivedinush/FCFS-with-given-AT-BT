#include<iostream>
using namespace std;
int main()
{
	int n,q,t=0,s=0;
	float avg_wt=0.0,avg_tat=0.0;
	cout<<"Enter the number of processes: "; cin>>n;
	cout<<"\nEnter the quantum size: "; cin>>q;
	float BT[n],WT[n],TAT[n],CT[n],rem_BT[n];
	cout<<"\nEnter the burst time of the processes: ";
	for(int i=0;i<n;i++)
	cin>>BT[i];
	for(int i=0;i<n;i++)
	rem_BT[i]=BT[i];
	for(int i=0;i<n;i++)
	s+=BT[i];
	while(t<s)
	{
		for(int i=0;i<n;i++)
		{
			if(rem_BT[i]>0)
			{
				if(rem_BT[i]>q)
				{
					t=t+q;
					rem_BT[i]=rem_BT[i]-q;
				}	
				else
				{
					t=t+rem_BT[i];
					rem_BT[i]=0;
					WT[i]=t-BT[i];
					TAT[i]=t;
					cout<<"\nTurn Around time: "<<TAT[i];
					cout<<"\nWaiting time: "<<WT[i];
				}
			}
			
		}
		
	}
	for(int i=0;i<n;i++)
		{
			avg_wt+=WT[i];
			avg_tat+=TAT[i];
		}
		cout<<"\n********************************";
		cout<<"\nAVERAGE WAITING TIME OF PROCESS "<<avg_wt/n<<endl;
		cout<<"\nAVERAGE TURN AROUND TIME OF PROCESS "<<avg_tat/n;
		cout<<"\n********************************";
}
