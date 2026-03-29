# priority-queue-ticket-system-cpp
C++ priority queue implementation that manages tickets based on priority while maintaining FIFO order for equal priorities.


This project implements a custom priority queue in C++ to manage tickets based on priority levels. Lower numeric values represent higher priority (0 is highest), and tickets with equal priority are processed in FIFO (first-in, first-out) order.

## Features
- Insert tickets while maintaining sorted priority order
- Peek at the highest-priority ticket
- Remove tickets from the front of the queue
- Track ticket positions in the queue
- Automatically assigns unique IDs to each ticket
- Maintains FIFO ordering for equal-priority tickets

## How It Works
The priority queue is implemented using a `std::vector<Ticket>`.  
When inserting a new ticket, the program finds the correct position in the vector to maintain ordering.

### Ordering Rules:
- Lower priority value -> higher importance  
- Equal priority -> maintain insertion order (FIFO)
  
## Example Behavior
- A ticket with priority `0` will always be placed at the front  
- A ticket with priority `50` will come after all tickets with lower values  
- If two tickets both have priority `20`, the one inserted first stays ahead  

## Project Structure
- `main.cpp` – Test driver that verifies all queue operations
- `PriorityQueue.cpp / .h` - Priority queue implementation
- `Ticket.cpp / .h` – Ticket class with priority, ID, and description

## Concepts Demonstrated
- Custom data structure implementation
- Sorting and ordered insertion
- Operator overloading (`<`, `<=`, `==`)
- Dynamic data management using `std::vector`
- Class design and encapsulation
- FIFO behavior within priority levels

## How to Run
Compile:
```bash
g++ main.cpp PriorityQueue.cpp Ticket.cpp -o queue
