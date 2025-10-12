Node* reverseKGroup(Node* head, int k) {
    

    Node* curr = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

   
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (!temp) return head;  
        temp = temp->next;
    }

    
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }


    if (next) {
        head->next = reverseKGroup(next, k);
    }

   
    return prev;
}
