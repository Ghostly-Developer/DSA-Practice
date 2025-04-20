//Singly linked list
//Insert value{at beginning(push), at position(push_pos), at end(push_back)}
//Return(complete list,fetch, fetch pos, last element(pop), delete position(delete))

#include<bits/stdc++.h>
using namespace std;
struct Nodes{
    int value;
    Nodes* address;
};
class Lists{
    private:
    Nodes* Head = NULL;
    public:
        void push(int value)
        {
            Nodes* node = new Nodes;
            node->value = value;
            node->address = Head;
            Head = node;
        }
        void push_pos(int value,int pos)
        {
            Nodes* node = new Nodes;
            Nodes* temp = Head;
            for(int i=0;i<pos-1;i++)
            {
                if(temp == NULL)
                {
                    cout << "Position out of bounds." << endl;
                    return;
                }
                temp = temp->address;
            }
            node->value = value;
            node->address = temp->address;
            temp->address = node;
        }
        void push_back(int value)
        {
            Nodes* node = new Nodes;
            node->value = value;
            node->address = NULL;
            if(Head==NULL)
            {
                Head = node;
                return;
            }
            Nodes* temp = Head;
            while(temp->address != NULL){
                temp = temp->address;
            };
            temp->address = node;
        }
        int pop()
        {
            int value = Head->value;
            Head = Head->address;
            return value;
        }
        int pop_last()
        {
            Nodes* temp = Head;
            while(temp->address->address != NULL)
            {
                temp = temp->address;
            };
            int value = temp->address->value;
            delete temp->address;
            temp->address = NULL;
            return value;
        }
        void print()
        {
            Nodes* temp = Head;
            while(temp!=NULL){
                cout<<temp->value<<" ";
                temp = temp->address;
            };
        }    
    };
int main(){
    Lists list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push_pos(7,0);
    list.print();
}