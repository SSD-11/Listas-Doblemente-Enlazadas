#include <iostream>

using namespace std;

class Nodo {
private:
    int data;
    Nodo *link;
public:
    Nodo(int data);

    Nodo(int data, Nodo *link);

    int getData() const;

    Nodo *getLink() const;

    void setData(int dato);

    void setLink(Nodo *link);
};//fin de la class Nodo

//Defininimos los métodos de la clase Nodo
Nodo::Nodo(int data) {
    this->data = data;
    this->link = 0;
}

Nodo::Nodo(int data, Nodo *link) {
    this->data = data;
    this->link = link;
}

int Nodo::getData() const {
    return this->data;
}

Nodo *Nodo::getLink() const {
    return this->link;
}

void Nodo::setData(int dato) {
    data = dato;
}


void Nodo::setLink(Nodo *link) {
    this->link = link;
}

class Lista {
private:
    Nodo *head;

public:
    Lista();

    void crearLista();

    void visualizarLista();

    void insertarAlaCabeza();

    void insertarALaCola();
};

//Definimos métodos de la clase Lista
Lista::Lista() { head = nullptr; }

void Lista::crearLista() {
    int dato;
    cout << "Ingrese enteros o -1 para terminar" << endl;
    do {
        cin >> dato;
        if (dato != -1) {
            this->head = new Nodo(dato, head);
        }
    } while (dato != -1);
}

void Lista::visualizarLista() {
    int n = 1; // contador de nodos, comienza en 1
    Nodo *temp = head;
    if (temp == nullptr) {
        cout << "La lista está vacía " << endl;
    } else {
        while (temp != nullptr) {
            cout << "[" << temp->getData() << "|" << temp->getLink() << "]" << " ";
            if (n % 3 == 0) {
                cout << endl; // salto de línea cada tercer nodo
            }
            temp = temp->getLink();
            n++;
        }
    }
}

void Lista::insertarAlaCabeza() {
    int dato;
    cout << "Ingrese el dato a insertar en la cabeza: ";
    cin >> dato;
    Nodo *nuevo = new Nodo(dato);
    if (head == nullptr) {
        nuevo->setLink(nullptr);
    } else {
        nuevo->setLink(head);
    }
    head = nuevo;
}

void Lista::insertarALaCola() {
    int dato;
    cout << "Ingrese el dato a insertar en la cola: ";
    cin >> dato;
    Nodo *nuevo = new Nodo(dato);
    if (head == nullptr) {
        head = nuevo;
    } else {
        Nodo *temp = head;
        while (temp->getLink() != nullptr) {
            temp = temp->getLink();
        }
        temp->setLink(nuevo);
    }
    nuevo->setLink(nullptr);
}


int main() {
    Lista lista;
    lista.crearLista();
    lista.insertarAlaCabeza();
    lista.insertarALaCola();
    lista.visualizarLista();
    return 0;
}