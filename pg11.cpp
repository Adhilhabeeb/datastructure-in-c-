// Linear stack using arrays
#include<iostream>
using namespace std;
class Stack{
    int arr[100];
    int n=100;
    int tos=-1;
    public:
        void push(int val);
        void pop();
        void display();
};

void Stack::push(int val){
    if(tos>=n-1){
        cout<<"\nThe stack is overflow\n";
    }else{
        tos++;
        arr[tos]=val;
    }
}

void Stack::pop(){
    if(tos<=-1){
        cout<<"\n stack is underflow\n";
    }else{
        cout<<"\nThe popped element is "<<arr[tos]<<"\n";
        tos--;
    }
}

void Stack::display(){

    if(tos>=0){
        cout<<"\n The stack elements are\n";

        for(int i=tos;i>=0;i--){
            cout<<arr[i]<<"\n";
        }
    }else{
        cout<<"\n stack is empty\n";
    }
}

int main(){

    Stack obj;
    int val,ch;
    cout<<"\n___ENTER THE CHOICE___\n";
    cout<<"\n 1: for push \n";
    cout<<"\n 2: for pop \n";
    cout<<"\n 3: for display \n";
    cout<<"\n 4: for exit \n";
    
    do{

        cout<<"\n Enter the choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"\n You selected push operation \n";
            cout<<"\n Enter the value for push opp in the stack \n";
            cin>>val;
            obj.push(val);
            break;
        case 2:
            cout<<"\n You selected pop operation \n";
            obj.pop();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            cout<<"\n Exit \n";
            break;    
        default:
            cout<<"\n Enter a valid choice\n";
          
        }
    }while(ch!=4);
    return 0;
}