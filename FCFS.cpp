#include<iostream>
using namespace std;
int main()
{
	cout<<"Enter number of processes: ";
	int n;
	cin>>n;
	int AT[n],BT[n],CT[n],WT[n],TAT[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter ARRIVAL TIME of PROCESS "<<i+1<<": ";
		cin>>AT[i];
		cout<<"Enter EXECUTION TIME of PROCESS "<<i+1<<": ";
		cin>>BT[i];
	}
	CT[0]=AT[0]+BT[0];
	for(int i=1;i<n;i++)
	{
		if(CT[i-1]>AT[i])
		{
			CT[i]=CT[i-1]+BT[i];
		}
		else
		CT[i]=AT[i]+BT[i];
	}
	float AVG_TAT=0.0,AVG_WT=0.0,AVG_CT=0.0;
	for(int i=0;i<n;i++)
	{
		TAT[i]=CT[i]-AT[i];
		WT[i]=TAT[i]-BT[i];
		AVG_CT+=CT[i];
		AVG_TAT+=TAT[i];
		AVG_WT+=WT[i];
		cout<<"\nCOMPLITION TIME OF PROCESS "<<i+1<<" : "<<CT[i];
		cout<<"\nTURN AROUND TIME OF PROCESS "<<i+1<<" : "<<TAT[i];
		cout<<"\nWAITING TIME OF PROCESS "<<i+1<<" : "<<WT[i];
	}
		cout<<"\nAVERAGE COMPLITION TIME OF PROCESS "<<AVG_CT/n;
		cout<<"\nAVERAGE TURN AROUND TIME OF PROCESS "<<AVG_TAT/n;
		cout<<"\nAVERAGE WAITING TIME OF PROCESS "<<AVG_WT/n;
}
