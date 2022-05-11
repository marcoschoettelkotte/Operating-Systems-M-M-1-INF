//
//  main.cpp
//  bsy_tickets
//
//  Created by Marco Schöttelkotte on 23.04.22.
//

#include <iostream>
#include <thread>
#include <ctime>
#include <mutex>
#include <future>
#include "queue/queue.hpp"
#include "ticket/ticket.hpp"
#include "names/names.hpp"


void enqueueSchedulerThreadFunc(Queue *queue) {queue->enqueueScheduler();}
void dequeueSchedulerThreadFunc(Queue *queue) {queue->dequeueScheduler();}
int main(int argc, const char * argv[]) {
    srand((unsigned int) time(NULL));
    Queue queue;
    thread enqueueSchedulerThread(enqueueSchedulerThreadFunc, &queue);
    thread dequeueSchedulerThread(dequeueSchedulerThreadFunc, &queue);
    enqueueSchedulerThread.join();
    dequeueSchedulerThread.join();
    return 0;
}
