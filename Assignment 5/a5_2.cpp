#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};
class LinkedList
{
public:
    int size;
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = tail = nullptr;
        size = 0;
    }
    void push(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {

            head = tail = temp;
            size++;
            return;
        }
        tail->next = temp;
        tail = temp;
        tail->next = nullptr;
        size++;
    }
    void pop()
    {
        if (size == 0)
            return;
        if (size == 1)
        {
            head = tail = nullptr;
            size = 0;
            return;
        }
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
        size--;
    }
    void delDuplicate(int val)
    {
        if (size == 0)
        {    return;
        }
        Node*dummy=new Node(0);
        Node*gen=dummy;
        dummy->next=head;
        while(gen!=nullptr && gen->next!=nullptr){
            if(gen->next->val==val){
                gen->next=gen->next->next;
            }
            else gen=gen->next;
        }
    }
    void display(){
        if(size==0) return;
        Node*temp=head;
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    LinkedList ll;
    ll.push(10);
    ll.push(30);
    ll.push(70);
    ll.push(50);
    ll.push(70);
    ll.push(90);
    ll.push(70);
    ll.push(70);
    ll.display();
    ll.delDuplicate(70);
    ll.display();

    return 0;
}