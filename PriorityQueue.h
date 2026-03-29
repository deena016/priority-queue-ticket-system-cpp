
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "Ticket.h"
#include <vector>
#include <list>

class PriorityQueue {
public:
  PriorityQueue(const std::vector<Ticket>& initialTickets);
  Ticket Peek();
  Ticket Pop_Front();
  void Insert(Ticket& elem);
  int Size();
  int QueuePosition(int id);
  void PrintAll();
private:
    std::vector<Ticket> tickets;
};

#endif