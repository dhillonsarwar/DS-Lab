void removloop(LinkedList &l){
    Node* slow=l.head;
    Node* fast=l.head;
    while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){break;}
        
    }
    if(slow==fast){
       slow = l.head;
 
    if (slow == fast) {
        while (fast->next != slow) {
            fast = fast->next;
        }
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }


    fast->next = nullptr;
}
    }
    else return;
    return;
}
