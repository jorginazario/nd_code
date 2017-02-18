#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	int j,domain;
	double i;
	float y=0;
	float min=0;
	float max=0;
	float n=0;
	float b=0;
	
	cout<<"Input the domain of the function: ";
	cin>>domain;
	cout<<"This is the plot of the graph of y=3(1-sinx) from x=0 to "<<domain<<endl;
	cout<<"X"<<"\t";
	cout<<"Y"<<"\t"<<endl;
	
	for(i=0;i<=domain;i+=0.25){
		y=(5*(2-sin(i)));
		cout<<i<<"\t"<<y<<"\t"<<setw(5);
		if (min<=y){
		min=y;
		b=i;
		}
		if(max>=y){
		max=y;
		n=i;
		}
		
		for(j=1;j<=ceil(y);j++){
		cout<<"#";
		}
		cout<<endl;
		}
		cout<<"The maximum of "<<min<<"was at x= "<<b<<endl;
		cout<<"The minimum of "<<max<<" was at x= "<<n;		
}
