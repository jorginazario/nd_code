#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int trows=0;
	int tcolumns=0;
	
	// Identify how many rows and columns:
	cout<<"Enter the amount of rows: ";
	cin>>trows;
	
	cout<<"Enter the amount of columns:";
	cin>>tcolumns;
	
	cout<<"*"<<"\t";
	for (int i=1; i<=tcolumns;i++){
		cout<<i<<"\t";				
	}
	cout<<endl;
	
	for (int i=1; i<=trows; i++){
		 cout<<i<<"\t";
	 	 for (int j=1; j<=tcolumns; j++){
	 	 cout<<i*j<<"\t";
	 	 }
	 	 cout<<endl; 
	}
	 
 
}

