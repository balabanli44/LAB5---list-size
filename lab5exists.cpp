#include <iostream>
using namespace std;

// Düğüm (Node) sınıfı
class Node {
public:
    int value;      // Düğümün değeri
    Node* next;     // Sonraki düğüme işaretçi
    Node* prev;     // Önceki düğüme işaretçi

    Node(int val) : value(val), next(nullptr), prev(nullptr) {} // Yapıcı fonksiyon
};

// Çift bağlı liste (Doubly Linked List) sınıfı
class List {
private:
    Node* head;     // Listenin başı
    Node* tail;     // Listenin sonu

public:
    List() : head(nullptr), tail(nullptr) {} // Yapıcı fonksiyon

    // Listeye bir eleman ekleme
    void add(int val) {
        Node* newNode = new Node(val);
        if (!head) { // Liste boşsa
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // `exists` fonksiyonu: Belirtilen değerin listede olup olmadığını kontrol eder
    bool exists(int val) {
        Node* current = head; // Başlangıç noktası
        while (current) {     // Listenin sonuna kadar dolaş
            if (current->value == val) {
                return true;  // Eşleşme bulundu
            }
            current = current->next; // Sonraki düğüme geç
        }
        return false; // Eşleşme bulunamadı
    }
};

int main() {
    List myList;

    // Listeye eleman ekle
    myList.add(10);
    myList.add(20);
    myList.add(30);

    // `exists` fonksiyonunu test et
    cout << "20 mevcut mu? " << (myList.exists(20) ? "Evet" : "Hayır") << endl;
    cout << "40 mevcut mu? " << (myList.exists(40) ? "Evet" : "Hayır") << endl;

    return 0;
}
