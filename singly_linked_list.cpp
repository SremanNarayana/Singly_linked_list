#include<iostream>
using namespace std;

class node{
    public:
            int data;
            int key;
            node* next;

        node(){
            data =0;
            key = 0;
            next = NULL;
        }

        node(int k, int d){
            key = k;
            data = d;
        }
};

class singlyLinkedList{
    public:
            node* head;

            singlyLinkedList(){
                head = NULL;
            }

//  1. Member function to check wheather a node exists or not in a linked list.

            node* nodeExists(int k){

                node* temp= NULL;
                node* ptr = head;

                while(ptr!=NULL){
                    if(ptr->key == k){
                        temp = ptr;
                    }
                    ptr = ptr->next;
                }
                return temp;

            }
        
// 2. Member function to create a node at the end of the linked list.

            void appendNode(node* n){
                if(nodeExists(n->key) != NULL){
                    std::cout<<"Node with the key :"<<n->key << " already exists in linked list"<<endl;
                }
                else if(head == NULL){
                    head = n;
                }
                else{
                    node* ptr = head;
                    while(ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    std::cout<<"Node appended"<<endl;
                } 
            }

// 3. Member function to create a node at the start of the linked list.

            void prependNode(node* n){
                if(nodeExists(n->key) !=NULL){
                    std::cout<<"The node already exists in linked list "<<endl;
                }
                else{
                    n->next = head;
                    head =n;
                    std::cout<<"The node has been linked to start of the linked list. "<<endl;
                }
            }

// 4. Insert a node after a node with the help of given value in a linked list.

            void insertNode(int k, node* n){
                
                node* ptr = nodeExists(k);
                if(ptr == NULL){
                    std::cout<<"There is no node exists with key :"<<ptr->key<<" in the linked list"<<endl;
                }
                else{
                    if(nodeExists(n->key)!= NULL){
                        std::cout<<"The given node already exists in the linked list"<<endl;
                    }
                    else{
                        n->next = ptr->next;
                        ptr->next = n;
                        std::cout<<"Node inserted"<<endl;
                    }
                }
                
            }

// 5. Delete a node in a linked list.

            void deleteNode(int k){

                if(head==NULL){
                   std::cout<<"Already the linked list is empty"<<endl;
                }
                else if(head!=NULL){
                    if(head->key==k){
                        head = head->next;
                        std::cout<<"The head has changed and node is unlinked "<<endl;
                    }
                    else{
                        node* temp = NULL;
                        node* prevPtr = head;
                        node* currentPtr = head->next;

                        while(currentPtr!=NULL){
                            if(currentPtr->key == k){

                                temp = currentPtr;
                                currentPtr = NULL;
                            }
                            else{
                                    prevPtr = prevPtr->next;
                                    currentPtr = currentPtr->next;
                            }
                            
                        }

                        if(temp!= NULL){
                            prevPtr->next = temp ->next;
                            std::cout<<"The node has been removed "<<endl;
                        }
                        else{
                            std::cout<<"Node doesn't exists in linked list "<<endl;
                        }
                    }
                }

            }

// 6. update the data in a node.
            void updateNode(int k, int d){
                node* ptr = nodeExists(k);
                if(ptr != NULL){
                    ptr->data = d;
                    std::cout<<"The data has been changed in the node of the linked list. "<<endl; 
                }
                else{
                    std::cout<<"The node doesn't exists in the linked list. "<<endl;
                }
            }

// 7. Print the linked list.
            void printNode(){
                if(head == NULL){
                    std::cout<<"There is no nodes present in the linked list. "<<endl;
                }
                else{
                    node* temp = head;
                    while(temp!=NULL){
                        std::cout<<"("<<temp->key<<" , "<<temp->data<<","<<temp->next<<")--->";
                        temp = temp->next;
                    }
                }
            }
            
        

};

//Driver code.

int main(){
    singlyLinkedList s;
    int option;
    int key1,data1,k1;
    do{
        cout<<"-------------------------------------------------------------------------------------"<<endl;
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    node* n1 = new node();
    switch (option)
    {
    case 1:
        cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
        cin>>key1;
        cin>>data1;
        n1->key= key1;
        n1->data=data1;
        s.appendNode(n1);
        break;
    
    case 2: 
        cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
        cin>>key1;
        cin>>data1;
        n1->data=data1;
        n1->key=key1;
        s.prependNode(n1);
        break;

    case 3:
         cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
         cin>>k1;
         cout << "Enter key & data of the New Node first: " << endl;
         cin>>key1;
         cin>>data1;
         n1->data=data1;
         n1->key=key1;
         s.insertNode(k1,n1);

    case 4:
        cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
        cin >> k1;
        s.deleteNode(k1);
        break;
    
    case 5:
        cout<<"Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
        cin>>key1;
        cin>>data1;
        s.updateNode(key1,data1);
        break;
    
    case 6:
        s.printNode();
        break;
    
    case 7:
        system("cls");
    default:
    cout<<"enter proper option. "<<endl;
        break;
    }
    
    
}while(option != 0);
}