#include<iostream>
#include<fstream>
using namespace std;
const int SIZE = 10;
void inputArray(int arr[], int size)
{
	cout<<"Enter"<<size<<"elements:"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"Element"<<i+1<<":";
		cin>>arr[i];
	}
}
void displayArray(int arr[], int size)
{
	cout<<"\nArray Elements:";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int calculateSum(int arr[], int size)
{
	int sum=0;
	for(int i=0;i<size;i++)
	{
		sum+=arr[i];
	}
	return sum;
}
void writeToFile(int arr[],int size)
{
	ofstream file("arrayData.txt");
	if(!file)
	{
		cout<<"Error opening file!"<<endl;
		return;
	}
	for(int i=0;i<size;i++)
	{
		file<<arr[i]<<" ";
	}
	file.close();
	cout<<"Data written to file successfully."<<endl;
}
void readFromFile(int arr[],int size)
{
	ifstream file("arrayData.txt");
	if(!file)
	{
		cout<<"Error opening file"<<endl;
		return;
	}
	for(int i=0;i<size;i++)
	{
		file>>arr[i];
	}
	file.close();
	cout<<"Data read from file.";
	displayArray(arr, size);
}
int main()
{
	int arr[SIZE];
	inputArray(arr,SIZE);
	int sum=calculateSum(arr, SIZE);
	cout<<"Sum of elements = "<<sum<<endl;
	writeToFile(arr, SIZE);
	readFromFile(arr, SIZE);
    return 0;
}

