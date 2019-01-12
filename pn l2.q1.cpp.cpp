/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// linked list actions adding number to list at certain position and delete element at certain
//counting the number of elements in the linked list
//display the linked list 
//position in the linked list.

// linked list actions adding number to list at certain position and delete element at certain
#include <iostream>
using namespace std;//for using cout
//to create class node
class Node
{
    public:
    int data;//stores the data
    Node* next;//node pointer points to next node
    Node()//default constructor start with zero
    {
        data=0;//data inilialized to 0
        next=NULL;//pointer initialized to null
    }
};

//to create class LinkedList
class LinkedList
{
    public:
    Node* head;//head is a node type pointer
    //default constructor
    LinkedList()
    {
        head=NULL;//initializes start to null
    }
    void insert(int value)
    {
    	Node* ptr = new Node;//new node created of Node type
        ptr->data = value;//data stores the value to be stored in the node
        if(head == NULL)//if the list is empty
        head = ptr;//the first element is added
        else
        {
            Node* temp = head;//new pointer to traverse the list
            while(temp->next != NULL)//while the end of the list is reached            
        temp = temp->next;//temp traverses the list
        temp->next = ptr;//the pointer of the current node points to the new node to be inserted
        }
        cout<<value<<" has been inserted in the Linked List.\n";
    }//end of function to insert a value into the linked list
    void insertAt(int pos,int value)//insertion function
    {
        Node* ptr = new Node;//new node created of Node type
        ptr->data = value;//data stores the value to be stored in the node
        if(head==NULL||pos==1)//if the list is empty
        head = ptr;//the first element is added
        else
        {
            Node* temp = head;//new pointer to traverse the list
            int i = 1;//variable to denote the position of the pointer temp
            while(temp->next != NULL&&i<pos-1)//while the end of the list is reached or the required position is reached
            {
        temp = temp->next;//temp traverses the list
        i++;
        }
            ptr->next = temp->next;//the pointer of the node ptr points to the next node in the list
            temp->next = ptr;//the pointer of the current node points to the new node to be inserted
        }
        cout<<value<<" has been inserted in the Linked List.\n";
    }
    //delete the value at last
    int delet()
    {
    Node* temp = head;//pointer temp to traverse the list
        int del = 0;//variable to store the dleted value
        if(temp == NULL)//if the first node is to be deleted
        return -9999;
    else if(temp->next == NULL)//if there is one element in the list
    {
        del = temp->data;//its value is stored
        delete temp;//it is deleted
    }
        else
        {
            while(temp->next->next != NULL)//while the end of the list is reached
            temp = temp->next;//the pointer temp traverses through the list
            Node* temp1 = temp->next;//new pointer to point to the last node in the list
            temp->next = NULL;//pointer of second last node becomes null, that is end of the list
            del = temp1->data;//the data removed is stored
            delete temp1;//the last node is deleted
        }
        return del;//the value deleted is returned
    }
    //deletion function
    int deleteAt(int post)
    {
        Node* temp = head;//pointer temp to go through the list
        int del = 0;//variable to store the dleted value
        if(post == 1)//if the first node is to be deleted
        {
            head =  temp->next;//start points to the second element in the list
            temp->next = NULL;//the first element is disconnected from the list
            del = temp->data;//its data is stored
            delete temp;//the node is deleted
        }
        else
        {
            int i = 1;//variable to denote the position of the pointer temp
            while(temp->next != NULL && i<post-1)//while the end of the list is reached or the required position is reached
            {
        temp = temp->next;//the pointer temp traverses through the list
        i++;
        }
            Node* temp1 = temp->next;//new pointer to point to the next node in the list
            temp->next = temp->next->next;//pointer of current node points to the second following node in the list
            temp1->next = NULL;//the next node is disconnected from the list
            del = temp1->data;//the data removed is stored
            delete temp1;//the node is deleted
        }
        return del;//the value deleted is returned
    }
    //function to count the number of elements in the list
    int countItems()
    {
	    int count = 0;//variable to store the number of elements in the Linkedlist
	    Node* temp = head;//pointer to go from the List
	    while(temp != NULL)//till the tail of the list is reached
	    {
	        temp = temp->next;//pointer moves forward
	        count++;//incrementing number of nodes
	    }
	    return count;//number of elements returned
    }
    //display function
    void display()
    {
        Node* temp = head;//pointer to go through the list
        while(temp != NULL)//while the end of the list is reached
        {
            cout << temp->data <<" -> ";//printing data
            temp = temp->next;//the pointer is moved forward
        }
        cout<<endl;
    }
    
};//end of class Linked List
int main()//main function
{
    cout<<"--------------------Linked List Object.----------------------"<<endl;
    
    
    LinkedList list1; //objects of LinkedList
    int choice;
    int value = 0;
    int pos = 0;
    cout<<"Enter 1 to add an element to the end of the linked list"<<endl;
    cout<<"Enter 2 to add an element at a specified position in the linked list"<<endl;
    cout<<"Enter 3 to delete an element from the end of the linked list"<<endl;
    cout<<"Enter 4 to delete an element from a specified position in the linked list"<<endl;
    cout<<"Enter 5 to count the number of elements in th linked list"<<endl;
    cout<<"Enter 6 to display the elements of the linked list"<<endl;
    cout<<"Enter 0 to exit."<<endl;
    cout<<"--------------------"<<endl;
    
    do
	{
		cout<<"Enter your choice"<<endl;
        cin>>choice;
        
		switch(choice)
		{
		    case 1 :cout<<"Enter the value to be added to the end of the linked list"<<endl;
		        	cin>>value;
		        	list1.insert(value);
					break;
			
			case 2 :cout<<"Enter the value to be added to the linked list"<<endl;
			        cin>>value;
			        cout<<"Enter the position where the value has to be inserted"<<endl;
			        cin>>pos;
			        list1.insertAt(pos,value);
					break;
			
			case 3 :value = list1.delet();
			        cout<< value <<" has been deleted from the linked list."<<endl;
					break;
					
			case 4 :cout<<"Enter the position to be deleted from the linked list"<<endl;
			        cin>>pos;
			        value = list1.deleteAt(pos);
			        cout<< value <<" has been deleted from the linked list."<<endl;
			        break;
			        
			case 5 :value = list1.countItems();
			        cout<<"The number of elements in the list is "<<value<<endl;
					break;
					
			case 6 :list1.display();
					break;
	    	case 0 :break;
            default:cout<<"Enter a valid integer."<<endl;
				
		}
    	    
	}while(choice!=0);
    
       return 0; 
}