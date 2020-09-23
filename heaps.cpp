#include<bits/stdc++.h>
using namespace std;
vector <int> heap;
void heapifyTopDown(int root){
    int left = 2*root + 1;
    int right = 2*root + 2;
    int maxi = root;
    int size = heap.size();
    if(left < size && heap[left] > heap[maxi])
        maxi = left;
    if(right < size && heap[right] > heap[maxi]) 
        maxi = right;
    if(maxi != root){
        int t = heap[root];
        heap[root] = heap[maxi];
        heap[maxi] = t;
        heapifyTopDown(maxi);
    }       
}
void heapifyBottomUp(int child){
    int parent = (child - 1) / 2;
    if(heap[parent] < heap[child]){
        int t = heap[parent];
        heap[parent] = heap[child];
        heap[child] = t;
        heapifyBottomUp(parent);
    }
}
void addElement(int value){
    heap.push_back(value);
    int index = heap.size() - 1;
    heapifyBottomUp(index);
    cout << "element successfully added" << endl;
}
void getMax(){
    if(heap.size() == 0){
        cout << "heap is empty, add an element first" << endl;
    } else {
        cout << "max element is " << heap[0] << endl;
    }
}
void deleteMax(){
    if(heap.size() == 0){
        cout << "heap is empty, add an element first" << endl;
    } else {
        int last = heap.size() - 1;
        int t = heap[0];
        heap[0] = heap[last];
        heap[last] = t;
        heap.pop_back();
        heapifyTopDown(0);
        cout << "deleted max element successfully" << endl;
    }
}
int main(){
    bool status = true;
    while(status){
        cout << "Enter 1.Add element to heap 2.Get max element 3.Delete max element 4.exit" << endl;
        int choice;
        cin >> choice;
        switch(choice){
            case 1: cout << "enter element to be added" << endl;
                    int val;
                    cin >> val;
                    addElement(val);
                    break;
            case 2: getMax();
                    break;
            case 3: deleteMax();
                    break;
            case 4: status = false;
                    break;                            
            default: cout << "wrong choice" << endl;
                    break;
        }
    }    
    return 0;
}