#include "pointList.h"
void pointList::insertPoint(Point newPoint){
    nodePoint* newNode = new nodePoint(newPoint);
    if (head == nullptr) { 
        head = tail = newNode;
    }
    else {
        tail->next = newNode; 
        newNode->prev = tail; 
        tail = newNode;       
    }
}
void pointList::print() const{
    nodePoint* current = head;
    while (current != nullptr) {
        cout << "Point: (" << current->point.getX() << ", " << current->point.getY() << ")" << endl;
        current = current->next;
    }
}
