//C++ program to implement merge sorting using threading
#include<iostream>
#include<pthread.h>
#include<time.h>

//Number of elements in an array
#define MAX 20
//Number of threads
#define Max_Thread 4

using namespace std;
//array of size MAX
int arr[MAX];
int p=0;

//merging functions for merging the array
void merge(int low, int mid, int high)
{
    int* left =new int[mid-low+1];
    int* right = new int[high-mid];

    //n1 is the size of left part
    //n2 is the size of right part
    int n1 =mid-low+1;
    int n2 =high-mid;
    int i,j;
  
    
    // storing values in the left array 
    for(i=0;i<n1;i++)
        left[i] = arr[i+low];

    //storing values in the right array
    for(i=0;i<n2;i++)
        right[i]=arr[i+mid+1];

int k=low;
i=j=0;

//merging the left and right part of the array 
//ascending order
while(i<n1 && j<n2)
   {
      if(left[i]<=right[j])
         arr[k++]=left[i++];
      else
         arr[k++]=right[j++];
   }

//storing the remaining values of the left part
while(i<n1)
   {
       arr[k++]=left[i++];
   }

//storing the remaining values of the right part
while(j<n2)
   {
	arr[k++]=right[j++];
   }
}

//recursive merge sort function
void merge_sort(int low, int high)
{
  //calculating the middle term of the array
  int mid = low+(high-low)/2;
	if(low<high)
	  {
		//function to call first half
		merge_sort(low, mid);
		//function to call second half
     		merge_sort(mid+1, high);
		//function to merge the two halves
		merge(low, mid, high);
           }
}

//thread function
void* merge_sort(void* arg)
{
   //which thread out of the four thread
   int tpart=p++;

   //calculating the low and high
   int low=tpart * (MAX/4);
   int high=(tpart+1) * (MAX/4)-1;

//evaluating middle term
int mid = low+(high-low)/2;
if(low<high)
	  {
		merge_sort(low, mid);
     		merge_sort(mid+1, high);
		merge(low, mid, high);
           }
}


int main()
{
   //for generating different random values
   srand(time(0)); 

//generating random numbers in an array
for(int i=0; i<MAX; i++)
   arr[i] = rand() % 100;

   //t1 and t2 for computing the time 
   //for merge sort 
   clock_t t1,t2;

   t1= clock();
   pthread_t threads[Max_Thread];

//creating four threads
for(int i=0;i< Max_Thread; i++)
    pthread_create(&threads[i], NULL, merge_sort, (void*)NULL);

//joining the four threads
                                                                                                                                                                                                            for(int i=0;i<4;i++) 
    pthread_join(threads[i], NULL);

//mergingthe final four threads
    merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1); 
    merge(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1); 
    merge(0, (MAX - 1)/2, MAX - 1); 

t2=clock();

//diplaying the sorted array
cout<<"Sorted array:";
for(int i=0;i<MAX;i++)
   cout<<arr[i]<<" ";

//time taken by merge sort per seconds
cout<<"\nTime taken:"<<(t2-t1)/(double)(CLOCKS_PER_SEC)<<"sec"<<endl;

return 0;
}
