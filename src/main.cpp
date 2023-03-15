#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
 
//bubble sort -nu-i cel mai eficient dar e usor de explicat
//merge sort -unul dintre alg divide and conquer- O(nlogn)
//merge- prima data e inpartit in 2 jumatati
//merge-si tot asa pana cand ai cate un array de un singur elem 
//merge- apoi incepe reconstructia (merge)si sortarea in acelasi timp

void merge(std::vector<int>& arr,int left, int middle, int right)
{
int n1=middle-left+1;
int n2=right-middle;
std::vector<int> left_arr(n1),right_arr(n2);
    for (int i=0;i<n1;i++)
    {
    left_arr[i]=arr[left+i];
    }

    for (int i=0;i<n2;i++)
    {
    right_arr[i]=arr[middle+1+i];
    }
int i=0,j=0,k=left;

while (i<n1 && j<n2)
{
    if(left_arr[i]<=right_arr[j])
    {
        arr[k++]=left_arr[i++];
    }
    else
    {
        arr[k++]=right_arr[j++];
    }
}

while(i<n1)
{
    arr[k++]=left_arr[i++];
}
while(j<n2)
{
    arr[k++]=right_arr[j++];
}

} 

void mergeSort(std::vector<int> &arr,int left, int right)
{
    if(left<right)
    {
        int middle=left+(right-left)/2;
        mergeSort(arr,left,middle);
        mergeSort(arr, middle+1,right);

        merge(arr,left,middle,right);
    }
}


void swap(int *a, int *b)
{
int aux=*a;
*a=*b;
*b=aux;
}
 
void printArray(int myArr[],int size)
{
    for(int i=0;i<size;++i)
    {
    std::cout<<myArr[i]<<" ";
    }
    std::cout<<std::endl;
}
//O(n^2)
void bubbleSort(int arr[],int n)
{
bool swapped;
int i,j;
for(i=0;i<n-1;i++)
    {
    swapped=false;
    
    for(j=0;j<n-i-1;j++)
        {
        if(arr[j]>arr[j+1])
            {        
            swap(&arr[j],&arr[j+1]);
            swapped=true;
            }
        }
   
    if(swapped==false)
   break;
    }
}


 
int main()
{
// int arr[]={64,34,25,12,22,11,90};
// int n=sizeof(arr)/sizeof(arr[0]);
// printArray(arr,n);
 
// bubbleSort(arr, n);
// printArray(arr,n);
// bubbleSort(arr, n);
// printArray(arr,n);

 
// std::vector<int> v={10,22,5,3,9,75};
// std::sort(v.begin(),v.end());
// for(auto data:v)
// {
//     std::cout<<data<<" ";
// }
// std::cout<<std::endl;    

std::vector<int> v={38,27,43,3,9,82,10};
std::cout<<"inainte de sortare: \n";
for (auto elem:v)
{
    std::cout<<elem<<" ";
}
std::cout<<std::endl;

mergeSort(v,0,v.size()-1);

std::cout<<"dupa de sortare: \n";
for (auto elem:v)
{
    std::cout<<elem<<" ";
}
std::cout<<std::endl;

    return 0;
}
