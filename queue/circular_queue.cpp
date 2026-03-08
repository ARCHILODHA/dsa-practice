#include <iostream>
using namespace std;

#define SIZE 5

int cq[SIZE];
int front=-1,rear=-1;

void enqueue(int x){

    if((rear+1)%SIZE==front){
        cout<<"Queue Full";
        return;
    }

    if(front==-1)
        front=0;

    rear=(rear+1)%SIZE;
    cq[rear]=x;
}

void dequeue(){

    if(front==-1){
        cout<<"Empty";
        return;
    }

    cout<<"Removed "<<cq[front]<<endl;

    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%SIZE;
}

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);

    dequeue();
}
