#include <iostream>
using namespace std;


class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        next = nullptr;
    }
};


class Stack{
    public:
       Node* head = nullptr;//always points to the first item

       void push_top(int v){
        Node* newNode = new Node(v);

        if(head == nullptr){
            head = newNode;
        }

        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }


       }

        bool isEmpty(){
            return head == nullptr? true : false;
       }

       int size(){
            int count = 0;
            Node* temp = head;

            while(temp != nullptr){
                temp = temp->next;
                count++;
            }
            return count;
       }

       void pop_back(){
            if(!isEmpty()){
                if(size() == 1){
                    delete head;
                    head = nullptr;
                }
                else{
                    Node* temp = head;

                    while(temp->next->next != nullptr){
                        temp = temp->next;
                    }

                    delete temp->next;
                    temp->next = nullptr;

                }

            }
       }

       int top(){
        if(!isEmpty()){
            Node* temp = head;

            while(temp->next != nullptr){
                temp = temp->next;
            }
            return temp->value;
        }

        return -1; //meaning our stack is empty
       }

};


int main(){

    Stack s;

    s.push_back(17);
    s.push_back(7);
    s.push_back(1);
    s.push_back(30);
    s.push_back(15);

    s.pop_back();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;

}

