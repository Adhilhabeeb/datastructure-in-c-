// Linear Queue using arrays
#include<iostream>
using namespace std;

class Queue{
    int queue[50];
    int n=50;
    int fro=-1;
    int rea=-1;

    public:
        void enqueue();
        void dequeue();
        void display();
};

void Queue::enqueue(){
    int num;

    if(rea>=n-1){
        cout<<"\n Queue is over flow\n";
    }else{
        if(fro==-1)
        fro=0;
        cout<<"\n Enter the number into queue\n";
        cin>>num;
        rea++;
        queue[rea]=num;
    }
}

void Queue::dequeue(){
    
    if(fro==-1||fro>rea){
        cout<<"\n Under flow\n";
    }else{
        int val=queue[fro];
        cout<<"\n The deleted element is = "<<queue[fro]<<"\n";
        fro++;
    }
}

void Queue::display(){
    
    if(fro==-1){
        cout<<"\n Queue is empty\n";
    }else{
        for(int i=fro;i<=rea;i++){
            cout<<queue[i]<<"\t";
        }
    }
}



int main(){
    Queue obj;
    int ch;
    cout<<"_____ THIS IS USING CLASS _____\n";
    cout<<"\n Enter 1) Insertion\n";
    cout<<"\n Enter 2) for deletion\n";
    cout<<"\n Enter 3) display\n";
    cout<<"\n Enter 4) for exit\n";

    do{
      cout<<"\n Enter your choice\n";
      cin>>ch;

      switch (ch)
      {
        case 1:obj.enqueue();
        break;
        case 2:obj.dequeue();
        break;
        case 3:obj.display();
        break;
        case 4:cout<<"\n Exit \n";
        break;
      
        default:
        cout<<"\n Enter valid entry ";
      }  
    }while (ch!=4);
    return 0;
}
