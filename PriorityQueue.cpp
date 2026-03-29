/*
PriorityQueue.cpp implements a PriorityQueue class for Ticket objects.Tickets 
are stored in priority order, where lower numeric values represent higher
priority (0 is highest). Tickets with equal priority maintain FIFO ordering.
The queue uses a std::vector<> and inserts elements in their correct position to
maintain ordering.
Author: Deena Qannan
*/
#include "PriorityQueue.h"
#include <iostream>
using namespace std;

// Constructs a PriorityQueue and inserts all initial tickets
// in correct priority order.
PriorityQueue::PriorityQueue(const vector<Ticket>& initialTickets) {
	for (int i = 0; i < initialTickets.size(); i++) {
		Ticket temp = initialTickets.at(i);
		Insert(temp);
	}
}

// Returns the highest-priority ticket without removing it.
// Exits if the queue is empty.
Ticket PriorityQueue::Peek() {
    if (tickets.size() == 0) {
        cout << "Error: empty queue." << endl;
        exit(1);
    }
    return tickets[0];
}

// Removes and returns the highest-priority ticket.
// Exits if the queue is empty.
Ticket PriorityQueue::Pop_Front() {
    if (tickets.size() == 0) {
        cout << "Error: Queue is empty." << endl;
        exit(1);
    }

    Ticket front = tickets[0];
    tickets.erase(tickets.begin());
    return front;
}

// Inserts a ticket into the queue in the correct position.
// Maintains priority order and FIFO for equal priorities.
void PriorityQueue::Insert(Ticket& elem) {
	int i = 0;

	while (i < tickets.size() && tickets[i] <= elem) {
		i++;
	}

	tickets.insert(tickets.begin() + i, elem);
}

// Returns the number of tickets in the queue.
int PriorityQueue::Size() {
    return tickets.size();
}

// Returns the index of the ticket with the given id.
// Returns -1 if the ticket is not found.
int PriorityQueue::QueuePosition(int id) {
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i].Id() == id) {
            return i;
        }
    }
    return -1;
}

// Prints all tickets in priority order.
void PriorityQueue::PrintAll() {
    for (int i = 0; i < tickets.size(); i++) {
        tickets[i].Print();
        cout << endl;
    }
}

