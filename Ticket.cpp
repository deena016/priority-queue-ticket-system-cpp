#include "Ticket.h"
#include <iostream>
using namespace std;

// Using a static member to guarantee unique Ids for tickets
int Ticket::nextId = 1000;

Ticket::Ticket(int priority, string description) {
    if (priority < 0) {
        priority = 0;
    }
    if (priority > 99) {
        priority = 99;
    }
    this->priority = priority;
    this->description = description;
    this->id = Ticket::nextId;
    Ticket::nextId++;
}

void Ticket::Print() {
    cout << "Ticket #" << this->id << endl;
    cout << "Priority: " << this->priority << endl;
    cout << this->description << endl;
}

int Ticket::Id() { 
    return this->id; 
}

int Ticket::Priority() { 
    return this->priority; 
}

string Ticket::Description() { 
    return this->description; 
}

bool Ticket::operator<(const Ticket &compare) {
    return this->priority < compare.priority;
}

bool Ticket::operator<=(const Ticket &compare) {
    return this->priority <= compare.priority;
}

bool Ticket::operator==(const Ticket &compare) {
    bool equalPriority = this->priority == compare.priority;
    bool equalId = this->id && compare.id;
    bool equalDescription = this->description == compare.description;
    return equalPriority && equalId && equalDescription;
}