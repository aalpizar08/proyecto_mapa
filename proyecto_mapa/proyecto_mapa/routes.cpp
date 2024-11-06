#include "routes.h"
void routes::addRoute(routesList list){
    routesList* newNode = new routesList(list);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        routesList* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = newNode;
    }
    cout << "Elemento agregado" << endl;
}
