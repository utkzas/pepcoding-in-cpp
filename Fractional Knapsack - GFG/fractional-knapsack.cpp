// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(Item a, Item b){
    double r1= (double)a.value/(double)a.weight;
    double r2= (double)b.value/(double)b.weight;
    return r1>r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int cap, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        int currweight=0;
        double finalvalue=0.0;
        
        for(int i=0;i<n;i++){
            if(currweight+arr[i].weight<=cap){ //if fitting completely
             currweight+=arr[i].weight; //add it wholly
             finalvalue+=arr[i].value;
            }
              else {
                 int remain=cap-currweight; // jitna ho paye utha lo
                 finalvalue+=(arr[i].value/(double)arr[i].weight)*(double)remain;
                 break;
            }
        }
    return finalvalue;

    }
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends