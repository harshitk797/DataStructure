/* 
Description: Find the number of iteration to convert all the elements of an array into zero.

Step 1 - You have to take an array of any size.

Step 2 - Take the positive values from the user as per the size of array and store the value in array.

Step 3 - Find the maximum and minimum values (minimum value should be greater than 0).

step 4 - Find the max % min and replace the max value with the remainder.

Step 5 - Repeat 3 and 4 till all elements are become zero.

Step 6 - Print the iteration. 
*/
#include<iostream>
using namespace std;

int main(){
	//for taking inputs
	int n;
	cout<<"Enter the size of array : ";
	cin>>n;

	if(n<=0){
	cout<<"Invalid Input ! "<<endl;
	return 1;
    }

	int* ar = new int[n];  // Dynamically allocate memory for the array

	if(n>0){
	for(int i=0;i<n;i++){
	cout<<"Enter the "<<i+1<<" element : ";
	cin>>ar[i];

	if (ar[i] <= 0) {
            cout << "Invalid Input! Array elements must be positive." << endl;
            delete[] ar; // Free memory before exiting
            return 1;
        }
	}
    }

    // For printing an array
    cout<<"Array is : ";
    for(int i=0;i<n;i++){
	cout<<ar[i]<<" ";
	}

	int iter = 0;
	while(true){
		int maxIndex = 0, minIndex = 0;
    	int max=ar[0],min=ar[0];
	for(int i=0 ; i<n ; i++){
		if(ar[i]>max){
			max=ar[i];
			maxIndex = i;
		}
		else if(ar[i] > 0 && ar[i] < min){
			min=ar[i];
			minIndex = i;
		}
	}

	if (max==0) {
            break;
        }

    // Replace max value with max % min
        ar[maxIndex] = max % min;
        iter++;

        // Display array state after each iteration
        cout << "\nIteration count is: " << iter << endl;
        cout << "After " << iter << " iteration,"<<endl;
        cout << "The array is: ";
        for (int i = 0; i < n; i++) { // Corrected loop condition
            cout << ar[i] << " ";
        }
        cout << "\n\n" << endl;
    }

    delete[] ar;

	cout<<endl<<"-----Programm Completed------"<<endl;  
	return 0;
} 