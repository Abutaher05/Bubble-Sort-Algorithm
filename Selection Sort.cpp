#include<iostream>
#include<fstream>
using namespace std;
void swaparray(int *p,int *q)       ///Swap Two number using Reference
{
    int temp= *p;
    *p=*q;
    *q=temp;
}
void selection(int arr[],int n1)        /// Sort Algorithm
{
    int minimum;
    for(int i=0;i<n1-1;i++)
    {
        minimum = i;
        for(int j=i+1;j<n1;j++)
        {
            if(arr[j]<arr[minimum])
            {
                minimum=j;
            }
        }
        swaparray(&arr[i],&arr[minimum]);
    }
}
void printarray(int arr[],int n)        ///print array elements
{
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<ends;
    }
    cout<<endl;
}
int main()
{
    fstream fp;             ///file Pointer
    int c=0,i=0,n,arr[100000];
    fp.open("Data1000.txt",ios:: in);       ///open file read mode
    if(!fp)
    {
        cout<<"File Does not exits "<<endl;
    }
    else
    {
        while(!fp.eof())
        {
            fp>>n;                  ///read data form file
            arr[i++]=n;             ///store data in array one by one
            c++;                    ///counter or length of array
        }
        selection(arr,c-1);         ///c-1 in the actual length of array
        printarray(arr,c-1);

    }
    fp.close();                     ///close file pointer


    return 0;
}
