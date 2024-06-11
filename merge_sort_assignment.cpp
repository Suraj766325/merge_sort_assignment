// // Q1) Given an array of integers, sort it in descending order using merge sort algorithm.
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&a,vector<int>&b,vector<int>&v)
{
    int i=0,j=0,k=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]>=b[j]) v[k++]=a[i++];
        else           v[k++]=b[j++];
    }
    while(i<a.size())  v[k++]=a[i++];
    while(j<b.size())  v[k++]=b[j++];
}
void mergesort(vector<int>&v)
{
    int n=v.size();
    if(n==1) return;
    vector<int>a(v.begin(),v.begin()+n/2);
    vector<int>b(v.begin()+n/2,v.end());
    //magic or recursion
    mergesort(a);
    mergesort(b);
    //merge a and b
    merge(a,b,v);
    //delete
    a.clear();
    b.clear();
}
int main()
{
    vector<int>v={5,1,3,0,4,9,6};
    mergesort(v);
    for(int ele:v) cout<<ele<<" ";
}




// Q2) Reverse Pairs (Leetcode Problem) : Given an integer array nums, return the number of reverse pairs in the array.
#include<iostream>
#include<vector>
int c=0;
using namespace std;
void inversion(vector<int>&a, vector<int>&b)
    {
        int i=0,j=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]>(2*b[j])){
                c+=a.size()-i;
                j++;
            }
            else i++;
        }
    }
    void merge(vector<int>&a, vector<int>&b, vector<int>&v)
    {
        int i=0,j=0,k=0;
        while(i<a.size() && j<b.size())
        {
            if(a[i]<=b[j]) v[k++]=a[i++];
            else           v[k++]=b[j++];
        }
        while(i<a.size()) v[k++]=a[i++];
        while(j<b.size()) v[k++]=b[j++];
    }
    void mergesort(vector<int>&v)
    {
        int n=v.size();
        if(n==1) return;
        //divide
        vector<int>a(v.begin(),v.begin()+n/2);
        vector<int>b(v.begin()+n/2,v.end());
        //magic or recursion
        mergesort(a);
        mergesort(b);
        //count inversion
        inversion(a,b);
        //merge
        merge(a,b,v);
    }
int main()
{
    vector<int>v={2,4,3,5,1};
    mergesort(v);
    cout<<c;
}