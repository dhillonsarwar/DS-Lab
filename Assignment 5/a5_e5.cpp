LinkedList poly(LinkedList l1, LinkedList l2) {
    LinkedList l3;
    Node* temp1 = l1.head;
    Node* temp2 = l2.head;
    Node* temp3 = nullptr; // last node in result

    while (temp1 || temp2) {
        Node* newNode = new Node();
        newNode->next = nullptr;

        if (temp1 && (!temp2 || temp1->pow > temp2->pow)) {
            newNode->cof = temp1->cof;
            newNode->pow = temp1->pow;
            temp1 = temp1->next;
        } else if (temp2 && (!temp1 || temp2->pow > temp1->pow)) {
            newNode->cof = temp2->cof;
            newNode->pow = temp2->pow;
            temp2 = temp2->next;
        } else {
            // powers are equal
            newNode->cof = temp1->cof + temp2->cof;
            newNode->pow = temp1->pow;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        // Append newNode to l3
        if (l3.empty) {
            l3.head = newNode;
            temp3 = newNode;
        } else {
            temp3->next = newNode;
            temp3 = newNode;
        }
    }

    return l3;
}
