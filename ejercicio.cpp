#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <cstring>

using namespace std;

struct pedido {
  char domicilioPedido[50];
  int zonaPedido;
  char comercioPedido[50];
  char rubroPedido[50];
  int importePedido;
  pedido *next;
}p1,p2,p3,p4,p5,p6;

struct repartido {
  char nombreRepartidor[50];
  int cantidadPedidos;
  char domicilioRepartido[50];
  int zonaRepartida;
  char comercioRepartido[50];
  char rubroRepartido[50];
  int importeRepartido;
  repartido *siguiente;
};

//Para mostrar a los repartidores y sus entregas

//DECLARACION DE FUNCIONES
bool hayPedidos(pedido* head);

//Para agregar nodos de pedido
void primerPedido(char domicilioPedido[50], int zonaPedido, char comercioPedido[50], char rubroPedido[50], int importePedido, pedido* head, pedido* tail);
void nuevoPedido(char domicilioPedido[50], int zonaPedido, char comercioPedido[50], char rubroPedido[50], int importePedido, pedido* head, pedido* tail);

//Para agregar nodos de repartidos
void primerReparto(pedido* head, repartido* primero, repartido* ultimo);
void nuevoReparto(pedido* head, repartido* primero, repartido* ultimo);

//Borrar pedido una vez asigando
void borrarPedido(pedido* head, pedido* tail);

//Mostrar repartidores ordenados por nombre
void ordernarImportes(int importesRepartidor[][20], int n);
void mostrarRepartidores(repartido* primero);
void intercambiar(int *xp, int *yp);

int main() {
  FILE *f;
  int respuesta;

  pedido *head1 = NULL;
  pedido *head2 = NULL;
  pedido *head3 = NULL;
  pedido *head4 = NULL;
  pedido *head5 = NULL;
  pedido *head6 = NULL;

  pedido *tail1 = NULL;
  pedido *tail2 = NULL;
  pedido *tail3 = NULL;
  pedido *tail4 = NULL;
  pedido *tail5 = NULL;
  pedido *tail6 = NULL;

  repartido *primero = NULL;
  repartido *ultimo = NULL;

  char domicilio[50];
  int zona;
  char comercio[50];
  char rubro[50];
  int importe;

  cout << "Elegir Opcion: (1 al 4): " << endl;
  cin >> respuesta;

  while (respuesta != 4) {
    switch (respuesta) {
      case 1:

        //Para ver si se puede tomar el pedido
        char nombreChequeo[50];
        char comercioChequeo[50];
        int zonaChequeo;

        //Datos del nuevo pedido
        cout << "Domicilio: " << endl;
        cin >> domicilio;
        cout << "Zona: " << endl;
        cin >> zona;
        cout << "Comercio: " << endl;
        cin >> comercio;
        cout << "Rubro: " << endl;
        cin >> rubro;
        cout << "Importe: " << endl;
        cin >> importe;

        //Comparo el archivo con el pedido del usuario
        f = fopen("registro.txt", "r");
        while (!feof(f)) {
          fscanf(f, "%s\n %s\n %d", nombreChequeo, comercioChequeo, &zonaChequeo);

          if (strcmp(comercioChequeo,comercio) == 0 && zonaChequeo == zona) {
            //Hacer el nuevo nodo de pedido

            if (zona == 1) {
              if (hayPedidos(head1) == false) {
                primerPedido(domicilio, zona, comercio, rubro, importe, head1, tail1);
              }
              else {
                nuevoPedido(domicilio, zona, comercio, rubro, importe, head1, tail1);
              }
            }
            else if (zona == 2) {
              if (hayPedidos(head2) == false) {
                primerPedido(domicilio, zona, comercio, rubro, importe, head2, tail2);
              }
              else {
                nuevoPedido(domicilio, zona, comercio, rubro, importe, head2, tail2);
              }
            }
            else if (zona == 3) {
              if (hayPedidos(head3) == false) {
                primerPedido(domicilio, zona, comercio, rubro, importe, head3, tail3);
              }
              else {
                nuevoPedido(domicilio, zona, comercio, rubro, importe, head2, tail2);
              }
            }
            else if (zona == 4) {
              if (hayPedidos(head4) == false) {
                primerPedido(domicilio, zona, comercio, rubro, importe, head4, tail4);
              }
              else {
                nuevoPedido(domicilio, zona, comercio, rubro, importe, head4, tail4);
              }
            }
            else if (zona == 5) {
              if (hayPedidos(head5) == false) {
                primerPedido(domicilio, zona, comercio, rubro, importe, head5, tail5);
              }
              else {
                nuevoPedido(domicilio, zona, comercio, rubro, importe, head5, tail5);
              }
            }
            else if (zona == 6) {
              if (hayPedidos(head6) == false) {
                primerPedido(domicilio, zona, comercio, rubro, importe, head6, tail6);
              }
              else {
                nuevoPedido(domicilio, zona, comercio, rubro, importe, head6, tail6);
              }
            }
          }
        }

        fclose(f);
        break;
      case 2:
        char nombre[50];
        int cantRepartos;
        int zonaReparto;

        cout << "Nombre del repartidor: " << endl;
        cin >> nombre;
        cout << "Cantidad de repartos que hace: " << endl;
        cin >> cantRepartos;
        cout << "Zona de reparto: " << endl;
        cin >> zonaReparto;

        f = fopen("registro.txt", "r");
        while (!feof(f)) {
          fscanf(f, "%s\n %s\n %d", nombreChequeo, comercioChequeo, &zonaChequeo);

          if (strcmp(nombreChequeo,nombre) == 0 && zonaChequeo == zonaReparto) {
            //Hacer el nuevo nodo de pedido

            if (zonaReparto == 1) {
              if (hayPedidos(head1) == false) {
                //Primer nodo de reparto
                primerReparto(head1, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head1, tail1);
              }
              else {
                  //Nuevo nodo de Reparto
                  nuevoReparto(head1, primero, ultimo);
                  //Eliminar el reparto
                  borrarPedido(head1, tail1);
                  break;
              }
            }
            else if (zonaReparto == 2) {
              if (hayPedidos(head2) == false) {
                //Primer nodo de reparto
                primerReparto(head2, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head2, tail2);
              }
              else {
                //Nuevo nodo de Reparto
                nuevoReparto(head2, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head2, tail2);
              }
            }
            else if (zonaReparto == 3) {
              if (hayPedidos(head3) == false) {
                //Primer nodo de reparto
                primerReparto(head3, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head3, tail3);
              }
              else {
                //Nuevo nodo de Reparto
                nuevoReparto(head3, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head3, tail3);
              }
            }
            else if (zonaReparto == 4) {
              if (hayPedidos(head4) == false) {
                //Primer nodo de reparto
                primerReparto(head4, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head4, tail4);
              }
              else {
                //Nuevo nodo de Reparto
                nuevoReparto(head4, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head4, tail4);
              }
            }
            else if (zonaReparto == 5) {
              if (hayPedidos(head5) == false) {
                //Primer nodo de reparto
                primerReparto(head5, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head5, tail5);
              }
              else {
                //Nuevo nodo de Reparto
                nuevoReparto(head5, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head5, tail5);
              }
            }
            else if (zonaReparto == 6) {
              if (hayPedidos(head6) == false) {
                //Primer nodo de reparto
                primerReparto(head6, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head6, tail6);
              }
              else {
                //Nuevo nodo de Reparto
                nuevoReparto(head6, primero, ultimo);
                //Eliminar el reparto
                borrarPedido(head6, tail6);
              }
            }
          }
          break;
        case 3:
          mostrarRepartidores(primero);
        }
      }
    }

        fclose(f);


    return 0;
    }



bool hayPedidos(pedido* head) {
  if (head == NULL)
    return false;
  else
    return true;
};


void primerPedido(char domicilioPedido[50], int zonaPedido, char comercioPedido[50], char rubroPedido[50], int importePedido, pedido* head, pedido* tail) {
    //Pongo los valores del primer pedido
    //Los que son strings uso strcpy
    //asigno el puntero de la cabeza de la lista que sea la misma que la cola
    pedido* temporal = new pedido;
    strcpy(temporal->domicilioPedido, domicilioPedido);
    temporal->zonaPedido = zonaPedido;
    strcpy(temporal->comercioPedido, comercioPedido);
    strcpy(temporal->rubroPedido, rubroPedido);
    temporal->importePedido = importePedido;
    temporal->next = NULL;
    head = temporal;
    tail = temporal;
    free(temporal);
}

void nuevoPedido(char domicilioPedido[50], int zonaPedido, char comercioPedido[50], char rubroPedido[50], int importePedido, pedido* head, pedido* tail) {
    //Unir el nuevo nodo a la lista
    //Hay un nuevo "ultimo"
    pedido* temporal = new pedido;
    strcpy(temporal->domicilioPedido, domicilioPedido);
    temporal->zonaPedido = zonaPedido;
    strcpy(temporal->comercioPedido, comercioPedido);
    strcpy(temporal->rubroPedido, rubroPedido);
    temporal->importePedido = importePedido;
    temporal->next = NULL;
    tail->next = temporal;
    tail = temporal;
    free(temporal);
  }

//Para agregar nodos de reparto
void primerReparto(pedido* head, repartido* primero, repartido* ultimo) {
  repartido* temporal = new repartido;
  strcpy(temporal->domicilioRepartido, head->domicilioPedido);
  temporal->zonaRepartida = head->zonaPedido;
  strcpy(temporal->comercioRepartido, head->comercioPedido);
  strcpy(temporal->rubroRepartido, head->rubroPedido);
  temporal->importeRepartido = head->importePedido;
  temporal->siguiente = NULL;
  primero = temporal;
  ultimo = temporal;
  free(temporal);
}

void nuevoReparto(pedido* head, repartido* primero, repartido* ultimo) {
  repartido* temporal = new repartido;
  strcpy(temporal->domicilioRepartido, head->domicilioPedido);
  temporal->zonaRepartida = head->zonaPedido;
  strcpy(temporal->comercioRepartido, head->comercioPedido);
  strcpy(temporal->rubroRepartido, head->rubroPedido);
  temporal->importeRepartido = head->importePedido;
  temporal->siguiente = NULL;
  ultimo->siguiente = temporal;
  ultimo = temporal;
  free(temporal);
}

void borrarPedido(pedido* head, pedido* tail) {
  if (hayPedidos(head) == false) {
     cout << "La lista de pedidos ya esta vacia" << endl;
   }
   else if (head == tail) {
     //Elimina el nodo de pedidos que quedaba
     delete head;
     head = NULL;
     tail = NULL;
   }
   else {
     pedido *temp = head;
     head = head->next;
     delete temp;
   }
}

void mostrarRepartidores(repartido* primero) {
  string nombreRepartidor[20];
  int importesRepartidor[20][20], i=0, j;

    cout << "La lista tiene estos repartidores:" << endl;
    while (primero != NULL) {
      j = 0;
      nombreRepartidor[i] = primero->nombreRepartidor;
      while (nombreRepartidor[i] == primero->nombreRepartidor) {

        importesRepartidor[i][j] = primero->importeRepartido;
        j++;
        primero = primero->siguiente;
      }
      //Ordenar los importes de cada repartidor
      ordernarImportes(importesRepartidor, 20);
      i++;

    }

    //Mostrar repartos ya ordenados
    for (int h = 0; h < 20; h++) {
      for (int x = 0; x < 20; x++) {
        cout << importesRepartidor[h][x] << endl;
      }
    }



}

//Ordenar importes
void ordernarImportes(int importesRepartidor[][20], int n) {
  int i, j, x;

    for (int x = 0; x < 20; x++) {
      for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
          if (importesRepartidor[x][j] < importesRepartidor[x][j+1])
          intercambiar(&importesRepartidor[x][j], &importesRepartidor[x][j+1]);
        }
      }
    }

 }

void intercambiar(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
 }
