#include <iostream> 
using namespace std;


struct Node{ 
    int data; 
    Node* next;  

    // konstruktor untuk 'Node' 
    Node(int val) : data(val), next(nullptr){} 
};

//fungsi untuk membalikkan LinkedList 
Node* reverseLinkedList(Node* head){ 
    Node *prev = nullptr, *current = head, *next = nullptr; 
    while (current != nullptr){ 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    }
    return prev; 
}

//fungsi untuk mencetak linked list
void displayLinkedList(Node* head){
    Node* temp = head; 
    while (temp != nullptr){ 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
    cout << endl; 
}

int main(){ 
    int jml; 
    cout << "\nMasukkan jumlah data : "; 
    cin >> jml; 
    
    Node* head = nullptr; 
    Node* tail = nullptr; 
    
    
    for (int i = 0; i < jml; i++){ 
        cout << "\nMasukkan nilai data ke-" << i+1 << " : ";
        int val; 
        cin >> val; 
        Node* newNode = new Node (val); 
                    

        if (head == nullptr){ 
            head = newNode; 
            tail = newNode; 

        } else { // jika linked list tidak kosong, maka 
            tail->next = newNode; 
            tail = newNode; 
        }
    }

    // menampilkan LinkedList sebelum dibalik
    cout << "\n============================================================"; 
    cout << "\nLinkedList sebelum dibalik : "; 
    displayLinkedList(head); 

    
    head = reverseLinkedList(head);

    // menampilkan LinkedList setelah dibalik
    cout << "\nLinkedList setelah dibalik : "; 
    displayLinkedList(head); 
    cout << "============================================================" << endl; 

    cout << "\nNama  : Haliza Adzikia Sukarno" << endl;
    cout << "NPM   : 2310631170087" << endl;
    cout << "kelas : 2C-Informatika" << endl;
    cout << endl; 

    return 0; 
}