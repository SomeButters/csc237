
// Doubly-linked list (and list iterator) node definition/implementation

#ifndef DBLLINK_H
#define DBLLINK_H
#include <iostream>

using namespace std;

// Need to prototype template classes if they are to be friends
template <class eltType> class DblLink;
template <class eltType> class DblLinkItr;
template <typename eltType> ostream& operator<<(ostream&, DblLink<eltType>);

template <class eltType> class Node
{	private:
		Node(eltType info, Node *pLink = 0, Node *rLink=0) 
				   : data(info), prev(pLink), next(rLink) {};
		eltType data;
		Node*	prev; 
		Node*	next;
	friend class DblLink<eltType>;
	friend class DblLinkItr<eltType>;
};

template <typename eltType> class DblLink {

    public:
        // Construct empty doubly linked list
        DblLink();
        
        // Creates deep copy of doubly linked list
        DblLink(DblLink&);

        // Destroys doubly linked list
        ~DblLink();

        // Assigns one doubly linked list to another via deep copy
        DblLink& operator=(const DblLink&);

        // To check if list is empty
        bool empty();

        // To find and return true/false if found certain element
        bool find(eltType);

        // Insert
        void insert(eltType);

        // Remove element
        void remove(eltType);

    private: 
        // Doubly linked list pointer
        Node<eltType>* head;

        // Get copy of node
        Node<eltType>* copy(Node<eltType>*);

        // Free nodes of a linked list
        void destroy(Node<eltType>*);

    //template <typename eltType> friend class ostream& operator<<(ostream&, DblLink<eltType>); // This was "friend class ostream& operator<< <>(ostream&, DblLink<eltType>); before."
    friend class DblLinkItr<eltType>;
};

// Iterator setup
template <typename eltType> class DblLinkItr {

    public:
        // Construct a list iterator
        DblLinkItr(const DblLink<eltType> &list);

        // Set up current to point at the first node of ListRef
        void start();

        // To check if list is empty
        bool isEmpty();

        // To check if last node
        bool isLastNode();

        // To check if first node
        bool isFirstNode();

        // Get the value out of current's node
        eltType operator*();

        // Increment to next available node 
        void operator++();

        // Decrement to previous node
        void operator--();

    private:
        const DblLink<eltType> &ListRef;
        Node<eltType> *current;
};


// Construct empty DblLink list/singular node
template <typename eltType> DblLink<eltType>::DblLink() : head(NULL) {}

// Copy constructor using copy()
template <typename eltType> DblLink<eltType>::DblLink(DblLink<eltType> &cl) {
    head = copy(cl.head);
}

//Free all nodes
template <typename eltType> DblLink<eltType>::~DblLink() {
    destroy(head);
}

/* 
    Function Name:      destroy
    Description:        This function destroys the current doubly linked list
    Parameters:         Node<eltType> *listPtr - pointer for the head of the list to be destroyed
    Return Value:       none
*/
// Remove all nodes in the doubly linked list, starting at the first instance
template <class eltType>
void DblLink<eltType>::destroy(Node<eltType> *listPtr) {
    while (listPtr != NULL) {
        Node<eltType> *doomed = listPtr;
        listPtr = listPtr->next;
        delete doomed;
    }
}

/* 
    Function Name:      operator =
    Description:        This function copies one doubly linked list to equal another, deep copy fashion
    Parameters:         DblLink<eltType> &cl - pointer for the head of the list to be destroyed
    Return Value:       *this - the assigned object
*/
template <typename eltType> DblLink<eltType> &DblLink<eltType>::operator =(const DblLink<eltType>& cl) {
    destroy(head);
    head = copy(cl.head);
    return *this;
}

/* 
    Function Name:      insert
    Description:        This function inserts an element in sorted order
    Parameters:         eltType x - the element to be inserted into the list
    Return Value:       none
*/
template <typename eltType> void DblLink<eltType>::insert(eltType x) {
    if (head == NULL) {
        head = new Node<eltType>(x,NULL,NULL);
    }
    else if (!(x < head->data)) {
        Node<eltType>* temp = head;
        head = new Node<eltType>(x,NULL,temp);
        temp->prev = head;
    }
    else {
        Node<eltType>* p = head->next;
        Node<eltType>* trailp = head;

        while ((p != NULL) && (x < p->data)) {
            trailp = p;
            p = p->next;
        }
        trailp->next = new Node<eltType>(x,trailp,p);
        if (p != NULL) {
           p->prev = trailp->next;
        }
    }
}

/* 
    Function Name:      copy
    Description:        This function copies the current doubly linked list
    Parameters:         Node<eltType> *listPtr - pointer for the head of the list to be destroyed
    Return Value:       none
*/
template <typename eltType> Node<eltType>* DblLink<eltType>::copy(Node<eltType> *listPtr) {
    if (listPtr != NULL) {
        Node<eltType>* ret = NULL;
        Node<eltType>* t = NULL;
        Node<eltType>* p = NULL;
        ret = p = t = new Node<eltType>(listPtr->data,NULL,NULL);
        for (t = listPtr->next; t != NULL; p = p->next, t = t->next) {
            p->next = new Node<eltType>(t->data, p, NULL);
        }
        return(ret);
    }
    return NULL;
}

/* 
    Function Name:      remove
    Description:        This function removes the specified element from the list
    Parameters:         eltType x - the element to be removed into the list
    Return Value:       none
*/
template <typename eltType> void DblLink<eltType>::remove(eltType x) {
    Node<eltType>* p = head;
    Node<eltType>* trailp = NULL;

    while ((p != NULL) && !(p->data == x)) {
        trailp = p;
        p = p->next;
    }
    if (p == head) {
        if(head->next == NULL) {
            head = NULL;
            return;
        }
        head = head->next;
        head->prev = NULL;
    }
    else {
        trailp->next = p->next;
        if(p->next != NULL) {
            p->next->prev = trailp;
        }
    }
    delete p;
}

// Constructor for Iterator
template <typename eltType> DblLinkItr<eltType>::DblLinkItr(const DblLink<eltType> &list): ListRef(list), current(NULL) {}

/* 
    Function Name:      start
    Description:        This function sets the iterator to the lists first value
    Parameters:         none
    Return Value:       none
*/
template <typename eltType> void DblLinkItr<eltType>::start(void) {
    current = ListRef.head;
}

/* 
    Function Name:      isEmpty
    Description:        This returns if the referenced list is empty or not
    Parameters:         none    
    Return Value:       bool - true if empty, false if not
*/
template <typename eltType> bool DblLinkItr<eltType>::isEmpty(void) {
    if (ListRef.head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

/* 
    Function Name:      isLastNode
    Description:        This returns if the referenced node is last in the list or not
    Parameters:         none    
    Return Value:       bool - true if last, false if not
*/
template <typename eltType> bool DblLinkItr<eltType>::isLastNode(void) {
    if ((current->next == NULL) || (current == NULL)) {
        return true;
    }
    else {
        return false;
    }
}

/* 
    Function Name:      isFirstNode
    Description:        This returns if the referenced node is first in the list or not
    Parameters:         none    
    Return Value:       bool - true if first, false if not
*/
template <typename eltType> bool DblLinkItr<eltType>::isFirstNode(void) {
    if (current->prev == NULL) {
        return true;
    }  
    else {
        return false;
    }
}

/* 
    Function Name:      operator*
    Description:        This function returns the value of the specified node
    Parameters:         none
    Return Value:       eltType
*/
template <typename eltType> eltType DblLinkItr<eltType>::operator*(void) {
    return current->data;
}

/* 
    Function Name:      operator++
    Description:        This function sets the iterator to increment by one
    Parameters:         none
    Return Value:       none
*/
template <typename eltType> void DblLinkItr<eltType>::operator++(void) {
    current = current->next;
}

/* 
    Function Name:      operator--
    Description:        This function sets the iterator to decrement by one
    Parameters:         none
    Return Value:       none
*/
template <typename eltType> void DblLinkItr<eltType>::operator--(void) {
    current = current->prev;
}
#endif
