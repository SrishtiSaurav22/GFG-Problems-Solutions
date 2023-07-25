Node *removeDuplicates(Node *head)
{
    if(head==nullptr)
        return nullptr;
        
    Node* temp=head;
    
    while(temp->next!=nullptr)
    {
        if(temp->data==temp->next->data)
        {
            // remove temp->next
            // dont move temp->next without checking if the new next node is a duplicate
            
            Node* ptr=temp->next;
            temp->next=temp->next->next;
            delete ptr;
        }
        
        else
            temp=temp->next;
    }
    
    return head;
}
