#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node *next;
};

Node *front = nullptr; // Pointer ke node depan
Node *back = nullptr;  // Pointer ke node belakang

bool isFull()
{ // Dalam implementasi linked list, antrian tidak pernah penuh
    return false;
}

bool isEmpty()
{ // Memeriksa apakah antrian kosong
    return front == nullptr;
}

void enqueueAntrian(string data)
{ // Fungsi untuk menambahkan elemen ke antrian
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    if (isEmpty())
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueAntrian()
{ // Fungsi untuk mengurangi elemen dari antrian
    if (isEmpty())
    {
        cout << "Antrian kosong" << endl;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            back = nullptr; // Jika antrian sekarang kosong, perbarui pointer back
        }
        delete temp;
    }
}

int countQueue()
{ // Fungsi untuk menghitung jumlah elemen dalam antrian
    int count = 0;
    Node *temp = front;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearQueue()
{ // Fungsi untuk menghapus semua elemen dari antrian
    while (!isEmpty())
    {
        dequeueAntrian();
    }
}

void viewQueue()
{ // Fungsi untuk melihat elemen dalam antrian
    cout << "Data antrian teller:" << endl;
    Node *temp = front;
    int index = 1;
    while (temp != nullptr)
    {
        cout << index << ". " << temp->data << endl;
        temp = temp->next;
        index++;
    }
    if (index == 1)
    {
        cout << "Antrian kosong" << endl;
    }
}

int main()
{
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
