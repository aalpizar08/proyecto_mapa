#include "routesList.h"
void routesList::saveRoute(string name, Route list){
	nodeList* newNode = new nodeList(name,list);
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
	}
	else {
		nodeList* running = head;
		while (running->next != nullptr) {
			running = running->next;
		}
		running->next = newNode;
	}
}
void routesList::printNames(){
	if (head != nullptr) {
		nodeList* running = head;
		while (running != nullptr) {
			cout << "Nombre de la ruta -> " << running->name << endl;
			running = running->next;
		}
	}
	else {
		cout << "Lista vacia." << endl;
	}
}
void routesList::deleteRoute(string name){
	if (head != head) {
		nodeList* prev = nullptr;
		nodeList* deleteNode = head;
		
		while ((deleteNode != nullptr) && (deleteNode->name != name)) {
			prev = deleteNode;
			deleteNode = deleteNode->next;
		}
		if (deleteNode == nullptr) {
			cout << "Lista no existe" << endl;
		}
		else if (prev == nullptr) {
			head = head->next;
			delete deleteNode;
		}
		else {
			prev->next = deleteNode->next;
			delete deleteNode;
		}
	}
}
void routesList::selectRoute(RenderWindow& window, Text& text, string name){
	if (head != nullptr) {
		nodeList* running = head;
		while ((running->next != nullptr) && (running->name != name)) {
			running = running->next;
		}
		running->route.printRoute(window);
		running->route.curve(window);
		running->route.printName(window, text);
	}
	else {
		cout << "la Lista se encuentra vacia, agregue una ruta para mostrar la lista" << endl;
	}
}


