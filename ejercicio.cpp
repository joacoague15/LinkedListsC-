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

struct nodeRepartidores {
  char nombreRepartidor[50];
  char domicilioPorEntregar[50];
  int zonaRepartidor;
  char comercioRepartido[50];
  char rubroDeReparto[50];
  float importeRepartido;
  nodeRepartidores* siguiente;
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

bool estaVacioDeRepartidores(nodeRepartidores* head) {
  if (head == NULL)
    return true;
  else
    return false;
};

void recibirPrimerPedido(nodePedido* &head, nodePedido* &tail, char domicilio[], int zona, char comercio[], char rubro[], float importe) {
  //Pongo los valores del primer pedido
  //Los que son strings uso strcpy
  //asigno el puntero de la cabeza de la lista que sea la misma que la cola

  nodePedido* temporal = new nodePedido;
  strcpy(temporal->domicilio, domicilio);
  temporal->zona = zona;
  strcpy(temporal->comercio, comercio);
  strcpy(temporal->rubro, rubro);
  temporal->importe = importe;
  temporal->next = NULL;
  head = temporal;
  tail = temporal;
}

void recibirPedido(nodePedido* &head, nodePedido* &tail, char domicilio[], int zona, char comercio[], char rubro[], float importe) {
  if (estaVacio(head)) {
    recibirPrimerPedido(head, tail, domicilio, zona, comercio, rubro, importe);
  }
  else {
    //Unir el nuevo nodo a la lista
    //Hay un nuevo "ultimo"
    nodePedido* temporal = new nodePedido;
    strcpy(temporal->domicilio, domicilio);
    temporal->zona = zona;
    strcpy(temporal->comercio, comercio);
    strcpy(temporal->rubro, rubro);
    temporal->importe = importe;
    temporal->next = NULL;
    tail->next = temporal;
    tail = temporal;
  }
}

void asignarPedidos(nodeRepartidores *&head, nodeRepartidores *&tail, nodePedido *&cabeza, nodePedido *&cola, char domicilio[], int zona, char comercio[], char rubro[], float importe) {
  char nombre[50];
  cout << "Nombre del repartidor: " << endl;
  cin >> nombre;

   if (head == tail) {
    //Asignar el primer reparto
    nodeRepartidores* temporalReparto = new nodeRepartidores;
    strcpy(temporalReparto->nombreRepartidor, nombre);
    strcpy(temporalReparto->domicilioPorEntregar, domicilio);
    temporalReparto->zonaRepartidor = zona;
    strcpy(temporalReparto->comercioRepartido, comercio);
    strcpy(temporalReparto->rubroDeReparto, rubro);
    temporalReparto->importeRepartido = importe;
    temporalReparto->siguiente = NULL;
    head = temporalReparto;
    tail = temporalReparto;

    //Borrar elementos de la lista de pedidos
    if (estaVacio(cabeza)) {
      cout << "La lista de pedidos ya esta vacia" <<endl;
    }
    else if (cabeza == cola) {
      delete cabeza;
      cabeza = NULL;
      cola = NULL;
    }
    else {
      nodePedido *temp = cabeza;
      cabeza = cabeza->next;
      delete temp;
    }

  }
  else {
    //Asignar un reparto
    nodeRepartidores* temporalReparto = new nodeRepartidores;
    strcpy(temporalReparto->nombreRepartidor, nombre);
    strcpy(temporalReparto->domicilioPorEntregar, domicilio);
    temporalReparto->zonaRepartidor = zona;
    strcpy(temporalReparto->comercioRepartido, comercio);
    strcpy(temporalReparto->rubroDeReparto, rubro);
    temporalReparto->importeRepartido = importe;
    temporalReparto->siguiente = NULL;
    tail->siguiente = temporalReparto;
    tail = temporalReparto;

    //Borrar elementos de la lista de pedidos
    if (estaVacio(cabeza)) {
      cout << "La lista de pedidos ya esta vacia" <<endl;
    }
    else if (cabeza == cola) {
      delete cabeza;
      cabeza = NULL;
      cola = NULL;
    }
    else {
      nodePedido *temp = cabeza;
      cabeza = cabeza->next;
      delete temp;
    }
  }
}

void mostrar(nodeRepartidores *current) {
  if (estaVacioDeRepartidores(current)) {
    cout << "No hay pedidos repartidos" << endl;
  }
  else {
    cout << "La lista tiene estos pedidos repartidos:" << endl;
    while (current != NULL) {
      //Ordenado por importe (falta por nombre)
      cout << current->comercioRepartido << endl;
      current = current->siguiente;
    }
  }
}


/*
salir();
*/

int main() {
  nodePedido *head = NULL;
  nodePedido *tail = NULL;

  nodeRepartidores *headReparto = NULL;
  nodeRepartidores *tailReparto = NULL;

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
      case '2':
        asignarPedidos(headReparto, tailReparto, head, tail, domicilio, zona, comercio, rubro, importe);
      case '3':
        mostrar(headReparto);
        break;
    }

  } while(opcion != 4);

  return 0;
}

//FALTA CHEQUEAR QUE LOS PEDIDOS QUE ENTREN APARECEN EN EL ARCHIVO (NOMBRE Y ZONA)
//FALTA QUE EL NOMBRE DEL REPARTIDOR APAREZCA EN EL ARCHIVO
//LOS REPARTOS ESTAN ORDENADOS POR IMPORTE, PERO NO POR NOMBRE
