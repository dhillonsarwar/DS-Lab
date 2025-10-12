Node* getintersection(LinkedList l1, LinkedList l2) {
    Node* temp = l1.head;

    while (temp) {
        Node* temp1 = l2.head;  

        while (temp1) {
            if (temp1 == temp) {
                return temp;  
            }
            temp1 = temp1->next;
        }

        temp = temp->next; 
    }

    return nullptr; 
}
