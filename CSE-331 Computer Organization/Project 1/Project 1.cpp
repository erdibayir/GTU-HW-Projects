#include<iostream> 
using namespace std;
#define MAX_SIZE 25
int CheckSumPossibility(int num,int arr[], int size) 
{
    int all_subset = 1<<size;
    for (int i=0; i<all_subset; i++){ 
        int sums = 0; 
        for (int j=0; j<size; j++){ 
            if (i & (1<<j)){
                sums += arr[j];
            }
        }
        if(sums == num){
        return 1; 
        } 
    }
    return 0;   
}
int main(){ 
    int arraySize;
	int arr[MAX_SIZE];
	int num;
	int returnVal;

	cin >> arraySize;
	cin >> num;

	for(int i=0; i < arraySize; i++)
	{
		cin >> arr[i];
	}

	returnVal = CheckSumPossibility(num, arr, arraySize);

	if(returnVal == 1)
	{
		cout << "Possible!" << endl;
	}else
	{
		cout << "Not possible!" << endl;
	}
	return 0; 
} 