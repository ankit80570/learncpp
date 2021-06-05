#include<bits/stdc++.h>
using namespace std;

void upheapify(vector<int> &heap, int idx){
    if(idx == 0)
    return;
    int pi = (idx-1)/2;
    if(heap[pi]<heap[idx]){
        int temp = heap[pi];
        heap[pi] = heap[idx];
        heap[idx] = temp;
        upheapify(heap,pi);
    }else {
        return;
    }
}
void downheapify(vector<int> &heap, int i){
    int li = 2*i+1;
    int ri = 2*i+2;
    if(li>=heap.size() and ri>= heap.size())
        return;
    int largestidx = i;
    if(li<heap.size() and heap[li] > heap[largestidx]){
        largestidx = li;
    }
    if(ri<heap.size() and heap[ri] > heap[largestidx]){
        largestidx = ri;
    }
    if(largestidx == i)
        return;
    swap(heap[i], heap[largestidx]);
    downheapify(heap, largestidx);
}
void deletepeek(vector<int> &heap){
    swap(heap[0],heap[heap.size() -1]);
    heap.pop_back();
    downheapify(heap,0);
}
void buildheap(vector<int> &heap){
    for(int i = heap.size(); i>=0; i--){
        downheapify(heap,i);
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

vector<int> heap;
int n,x;
cin>>n;
for(int i=0; i<n; i++){
    cin>>x;
    heap.push_back(x);
    upheapify(heap,i);
}
for(int i=0; i<heap.size(); i++){
    cout<<heap[i]<<" ";
}
deletepeek(heap);
cout<<endl;
for(int i=0; i<heap.size(); i++){
    cout<<heap[i]<<" ";
}
cout<<endl;
vector<int> arr = {2, 3, 10, -1, 5, 4, 19, 7, 0, 12};
for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
}
buildheap(arr);
cout<<endl;
for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
}
return 0;

}