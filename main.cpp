#include "PriorityQueue.h"
#include "Ticket.h"
#include <iostream>
#include <cassert>

using namespace std;

// Test data
Ticket t1(20, "50 Car Pile-Up Results In New City Sculpture");
Ticket t2(40, "All Raccoons Cheat At Poker, Animal Researchers Say");
Ticket t3(5, "After 36 Years Of Marriage, Man Discovers Wife Is Actually A "
          "Rare Yucca Plant");
Ticket t4(50, "Broccoli Found To Cause Grumpiness In Children");
Ticket t5(20, "Building Turned Into Aviary After Birds Stick To New Paint");
Ticket t6(30, "Bus Misses Turn, Dozens Late For Work");
Ticket t7(20, "Cats Demand Longer Breaks, Cleaner Litter, Slower Mice");
Ticket t8(55,
          "Cauliflower-Lovers Won't Let Broccoli-Eaters March In Their Neighborhood");
Ticket t9(70,
          "Phonebooks Print All Wrong Numbers; Results In 15 New Marriages");
Ticket t10(0, "Pigeon Alert! Extreme Pigeon Danger!");

int main() {
    
	cout << "Generate a queue with 5 tickets in it" << endl;
	PriorityQueue q({t1, t2, t3, t4, t5});

	cout << "Size of queue: " << q.Size() << endl;
	assert(q.Size() == 5);

	Ticket first = q.Peek();
	assert(first == t3);
	assert(q.QueuePosition(t3.Id() == 0));
	cout << endl << "First element in queue: " << endl;
	first.Print();

	cout << endl << "Pop first element in queue: " << endl;
	first = q.Pop_Front();
	assert(first == t3);
	first.Print();
	cout << "Size of queue: " << q.Size() << endl;
	assert(q.Size() == 4);

	cout << endl << "Check remaining elements in queue" << endl;
	assert(q.QueuePosition(t1.Id()) == 0 || q.QueuePosition(t5.Id()) == 0);
	assert(q.QueuePosition(t1.Id()) == 1 || q.QueuePosition(t5.Id()) == 1);
	assert(q.QueuePosition(t2.Id()) == 2);
	assert(q.QueuePosition(t4.Id()) == 3);

	cout << endl << "Insert elements at end of queue " << endl;
	q.Insert(t8);
	assert(q.QueuePosition(t8.Id()) == 4);
	assert(q.Size() == 5);
	q.Insert(t9);
	assert(q.QueuePosition(t9.Id()) == 5);
	assert(q.Size() == 6);

	cout << endl << "Insert element in middle of queue, unique priority" << endl;
	q.Insert(t6);
	assert(q.QueuePosition(t6.Id()) == 2);
	assert(q.Size() == 7);

	cout << endl << "Insert element in middle of queue, duplicate priority" << endl;
	q.Insert(t7);
	assert(q.QueuePosition(t7.Id()) == 2);
	assert(q.Size() == 8);

	cout << endl << "Insert element at front of queue" << endl;
	q.Insert(t10);
	assert(q.QueuePosition(t10.Id()) == 0);
	assert(q.Size() == 9);

	vector<Ticket> expectedOrder = {t10, t1, t5, t7, t6, t2, t4, t8, t9};
	cout << endl << "Check all tickets" << endl;
	for (int i = 0; i < expectedOrder.size(); i++) {
		assert(q.QueuePosition(expectedOrder.at(i).Id()) == i);
	}

	cout << endl << "Pop all tickets " << endl;
	for (int i = 0; i < expectedOrder.size(); i++) {
		first = q.Peek();
		assert(first == expectedOrder.at(i));
		first = q.Pop_Front();
		assert(first == expectedOrder.at(i));
		first.Print();
	}
	assert(q.Size() == 0);
	

}