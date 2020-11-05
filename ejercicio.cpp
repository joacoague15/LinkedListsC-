#include <iostream>
#include <string.h>

using namespace std;

//Struct modelo de un pedido
struct nodePedido {
  char domicilio[50];
  int zona;
  char comercio[50];
  char rubro[50];
  float importe;
  nodePedido* next;
};

char menu() {
  char opcion;

  cout << "Menu" <<endl;
  cout << "1.Agregar un pedido." <<endl;
  cout << "2.Asignar pedidos a un repartidor." <<endl;
  cout << "3.Mostrar." <<endl;
  cout << "4.Salir." <<endl;

  cin >> opcion;

  return opcion;
}

//Para saber si el lista esta vacia
bool estaVacio(nodePedido* head) {
  if (head == NULL)
    return true;
  else
    return false;
};

void recibirPrimerPedido(nodePedido* &head, nodePedido* &tail, char domicilio[], int zona, char comercio[], char rubro[], float importe) {
  //Asigno memoria al puntero temporal
  nodePedido* temporal = new nodePedido;
  //Pongo los valores del primer pedido
  strcpy(temporal->domicilio, domicilio);
  //temporal->domicilio = domicilio;
  temporal->zona = zona;
  strcpy(temporal->comercio, comercio);
  //temporal->comercio = comercio;
  //temporal->rubro = rubro;
  strcpy(temporal->rubro, rubro);
  temporal->importe = importe;
  temporal->next = NULL;
  //asigno el puntero de la cabeza de la lista que sea la misma que la cola
  head = temporal;
  tail = temporal;
}

void recibirPedido(nodePedido* &head, nodePedido* &tail, char domicilio[], int zona, char comercio[], char rubro[], float importe) {
  if (estaVacio(head)) {
    recibirPrimerPedido(head, tail, domicilio, zona, comercio, rubro, importe);
  }
  else {
    nodePedido* temporal = new nodePedido;
    //temporal->domicilio = domicilio;
    strcpy(temporal->domicilio, domicilio);
    temporal->zona = zona;
    //temporal->comercio = comercio;
    strcpy(temporal->comercio, comercio);
    //temporal->rubro = rubro;
    strcpy(temporal->rubro, rubro);
    temporal->importe = importe;
    temporal->next = NULL;
    //Unir el nuevo nodo a la lista
    tail->next = temporal;
    //Hay un nuevo "ultimo"
    tail = temporal;
  }
}

void mostrar(nodePedido *current) {
  if (estaVacio(current)) {
    cout << "No hay pedidos disponibles" << endl;
  }
  else {
    cout << "La lista tiene estos pedidos:" << endl;
    while (current != NULL) {
      cout << current->comercio << endl;
      current = current->next;
    }
  }
}

/*
asignarPedido();
salir();
*/

int main() {
  nodePedido *head = NULL;
  nodePedido *tail = NULL;
  char opcion;

  //Para agregar despues los datos
  char domicilio[50];
  int zona;
  char comercio[50];
  char rubro[50];
  float importe;

  do {

    opcion = menu();

    switch (opcion) {
      case '1':
        cout << "Domicilio:" << endl;
        cin >> domicilio;
        cout << "Zona:" << endl;
        cin >> zona;
        cout << "Nombre del comercio:" << endl;
        cin >> comercio;
        cout << "Rubro:" << endl;
        cin >> rubro;
        cout << "Importe:" <<endl;
        cin >> importe;
        recibirPedido(head, tail, domicilio, zona, comercio, rubro, importe);
        break;
      case '3':
        mostrar(head);
        break;
    }

  } while(opcion != 4);

  return 0;
}
