/*!
    \file DblLink.h
    \brief "Implementation of a doubly linked list for use in project 3"
*/
// Doubly-linked list (and list iterator) node definition/implementation

#ifndef DBLLINK_H
#define DBLLINK_H
#include <iostream>

using namespace std;

// Need to prototype template classes if they are to be friends
/*!
    \class DblLink
    \brief "Implementation of a doubly linked list for use in project 3, used by DblLinkList.h/.cpp"
*/
template <class eltType> class DblLink;

/*!
    \class DblLinkItr
    \brief "Implementation of a doubly linked list iterator for ease of use in accessing the linked list's contents"
*/
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
        /*!
            \fn DblLink
            \brief "Basic constructor, initializes empty list"            
        */
        DblLink();
        
        // Creates deep copy of doubly linked list
        /*!
            \fn DblLink(DblLink&)
            \brief "Creates a deep copy construction of the list"
            \param "DblLink&" "The original list for copying"
        */
        DblLink(DblLink&);

        // Destroys doubly linked list
        /*!
            \fn ~DblLink()
            \brief "Basic destructor, destroys list"
        */
        ~DblLink();

        // Assigns one doubly linked list to another via deep copy
        /*!
            \brief "Assigns the contents of one doubly linked list to another"
            \param "const DblLink&" "The list to be assigned the information"
        */
        DblLink& operator=(const DblLink&);

        // To check if list is empty
        /*!
            \fn empty
            \brief "Whether or not the list is currently empty"
            \return bool "Answers true if the list is empty, false if it is not empty"
        */
        bool empty();

        // To find and return true/false if found certain element
        /*!
            \fn find
            \brief "Finds the value within the doubly linked list, and remains at that element"
            \param "eltType" "The element to be found"
            \return bool "Returns true if found, false if not found"
        */
        bool find(eltType);

        // Insert
        /*!
            \fn insert
            \brief "Inserts the given parameter to a created node before the current value"
            \param "eltType" "The element to be inputted"
        */
        void insert(eltType);

        // Remove element
        /*!
            \fn remove
            \brief "Searches for an element in the list, and removes it if it is found"
            \param "eltType" "The element to be removed if found"
        */
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
        /*!
            \fn DblLinkItr(const DblLink<eltType> &list)
            \brief "Default constructor, requires a doubly linked list as input"
            \param "const DblLink<eltType> &list" "The doubly linked list to construct the iterator upon"
        */
        DblLinkItr(const DblLink<eltType> &list);

        // Set up current to point at the first node of ListRef
        /*!
            \fn start
            \brief "Initializes the iterator at the first value, must be done before any arithmatic"
        */
        void start();

        // To check if list is empty
        /*!
            \fn isEmpty
            \brief "Checks to see if the iterator's doubly linked list is empty"
            \return bool "True if the list is empty, false if else-wise"
        */
        bool isEmpty();

        // To check if last node
        /*!
            \fn isLastNode
            \brief "Checks to see if the the iterator's current node is the last one"
            \return bool "True if it is the last value, false if else-wise"
        */
        bool isLastNode();

        // To check if first node
        /*!
            \fn isFirstNode
            \brief "Checks to see if the iterator's current node is the first one"
            \return bool "True if it is the first value, false if else-wise"
        */
        bool isFirstNode();

        // Get the value out of current's node
        /*!
            \brief "Returns the contents of the iterator's current node"
            \return eltType "The contents of the iterator's current node"
        */
        eltType operator*();

        // Increment to next available node 
        /*!
            \brief "Increments the iterator to the next node in the list"
        */
        void operator++();

        // Decrement to previous node
        /*!
            \brief "Decrements the iterator to the previous node in the list"
        */
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
