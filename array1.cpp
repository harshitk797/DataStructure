#include<iostream>
using namespace std;

int main(){
	//for taking inputs
	int n;
	int ar[n];
	cout<<"Enter the size of array : ";
	cin>>n;
	if(n>0){
	for(int i=0;i<n;i++){
	cout<<"Enter the "<<i+1<<" element : ";
	cin>>ar[i];
	}
}
	else{
	cout<<"Invalid Input ! "<<endl;
    }

    // For printing an array
    cout<<"Array is : ";
    for(int i=0;i<n;i++){
	cout<<ar[i];
	cout<<" ";
	}


	cout<<endl<<"-----Programm Completed------"<<endl;  
} 