#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x){
    if(rear == SIZE-1){
        cout<<"Queue Full\n";
        return;
    }

    if(front==-1) front=0;

    queue[++rear] = x;
}

void dequeue(){
    if(front==-1 || front>rear){
        cout<<"Queue Empty\n";
        return;
    }

    cout<<"Removed "<<queue[front++]<<endl;
}

void display(){
    for(int i=front;i<=rear;i++)
        cout<<queue[i]<<" ";
}

int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
}
