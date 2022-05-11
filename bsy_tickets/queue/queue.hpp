//
//  queue.hpp
//  bsy_tickets
//
//  Created by Marco Schöttelkotte on 06.05.22.
//

#ifndef queue_hpp
#define queue_hpp

#include <iostream>
#include <mutex>
#include <ctype.h>
#include <thread>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
#include <ctime>
#include <map> // the map in c++ has the structure of a red-black-tree
#include "../ticket/ticket.hpp"
#include "../names/names.hpp"


using namespace std;

class Queue {
public:
    map<int, typeof(Ticket)> queue, readyQueue;
    Queue();
    Ticket *enqueue(Ticket *value);
    Ticket *dequeue();
    bool isFull();
    bool isEmpty();
    void enqueueScheduler();
    void dequeueScheduler();
private:
    void statisticLog(Ticket *ticket, bool wasRemoved);
    double peoplePerMinute(double avWaitingTime);
    double averageWaitingTime(map<int, typeof(Ticket)> readyQueue);
    double averageEnduranceLevel(double currentEndurance, double maxEndurance);
    double averageLength(double currentEndurance, double maxEndurance);
    
    int first, last;
    int minWaitingTime = 4;
    int maxWaitingTime = 7;
    double timeInSeconds = 60.0;
    time_t programStartTime = time(0);
    Names names;
};

#endif /* queue_hpp */
