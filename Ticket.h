#ifndef TICKET_H
#define TICKET_H

#include <string>

class Ticket {
public:
  Ticket(int priority, std::string description);
  void Print();
  int Priority();
  int Id();
  std::string Description();
  bool operator<(const Ticket &compare);
  bool operator<=(const Ticket &compare);
  bool operator==(const Ticket& rhs);


private:
  // Prevents creation of Ticket objects without priority & description
  Ticket();

  // Data members;
  int priority;
  int id;
  std::string description;

  // Unique id
  static int nextId;
};

#endif