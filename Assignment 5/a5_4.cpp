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
        this->next = NULL;
    }
};
class LinkedList
{
    int size;
    Node *head;
    Node *tail;

public:
    
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void insert(int val)
    {
        if (size == 0)
        {
            Node *temp = new Node(val);
            head = tail = temp;
            size++;
            return;
        }
        Node *temp = new Node(val);
        tail->next = temp;
        tail = temp;
        size++;
        return;
    }
    int peek()
    {
        if (size == 0)
        {
            cout << "List empty" << endl;
            return -1;
        }
        return tail->val;
    }
    void display()
    {
        if (size == 0)
        {
            cout << "List empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void rev(){
        Node*prev=nullptr;
        Node*curr=head;
        Node*next=nullptr;

        tail=head;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }

};



int main()
{
    LinkedList*ll=new LinkedList();
    ll->insert(10);
    ll->insert(20);
    ll->insert(30);
    ll->insert(40);
    ll->insert(50);
    ll->insert(60);
    ll->insert(70);
    ll->insert(80);
    ll->insert(90);
    ll->insert(100);
    ll->display();
    ll->rev();
    ll->display();
    

    return 0;
}