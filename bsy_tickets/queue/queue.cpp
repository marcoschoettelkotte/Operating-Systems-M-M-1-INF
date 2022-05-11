//
//  queue.cpp
//  bsy_tickets
//
//  Created by Marco Schöttelkotte on 06.05.22.
//

#include "queue.hpp"
using namespace std;

Queue::Queue(){
    first = -1;
    last = -1;
}

Ticket *Queue::enqueue(Ticket *value){
    if(isFull()) return nullptr; // queue is full
    if(first == -1)
        first = 0;
    ++last;
    queue[last] = *value;
    statisticLog(value, false);
    return value;
}

Ticket *Queue::dequeue(){
    if(isEmpty()) return nullptr; // queue is empty
    Ticket *value = &queue[first];
    if(first >= last){
        first = -1;
        last = -1;
    }else {
        first++;
    }
    // delete value from queue
    readyQueue[(int) readyQueue.size()] = *value;
    if(queue.size() != 0)
        queue.erase(queue.begin());
    statisticLog(value, true);
    return value;
}

bool Queue::isFull(){
    if(first == 0) return true;
    return false;
}

bool Queue::isEmpty(){
    if(first == -1) return true;
    return false;
}

void Queue::enqueueScheduler(){
    while(true){
        Ticket userTicket = {
            .name = names.generateName(),
            .start_time = time(0),
        };
        enqueue(&userTicket);
        // time until the next person
        int randomSeconds = rand() % (maxWaitingTime / 2) + (minWaitingTime / 2);
        sleep(randomSeconds); // in seconds
    }
}

void Queue::dequeueScheduler(){
    while(true){
        // time until the first person is ready
        int randomSeconds = rand() % maxWaitingTime + minWaitingTime;
        sleep(randomSeconds); // in seconds
        if(!isEmpty())
            queue.begin()->second.end_time = time(0);
        dequeue();
    }
}

void Queue::statisticLog(Ticket *ticket, bool wasRemoved) {
    string action = wasRemoved ? "remove " : "add ";
    double lambda = averageWaitingTime(readyQueue);
    int singleWaitingTime = wasRemoved ? (int) ticket->end_time - (int) ticket->start_time : 0;
    double mu = peoplePerMinute(lambda);
    int programTime = (int)(time(0) - programStartTime);
    
    for(int i = 0; i < 3; ++i) cout << "" << endl;
    cout << "Programm-Zeit: " << programTime << " sekunden" << endl;
    cout << "Wartend: " << queue.size() << endl;
    cout << "Fertig: " << readyQueue.size() << endl;
    cout << "" << endl;
    cout << "Lambda: "  << lambda << endl;
    cout << "Mu: " << mu << endl;
    cout << "" << endl;
    cout << "Kunden pro Minute: " << mu << endl;
    cout << "Durchschnittlicher Auslastungsgrad: " << averageEnduranceLevel(lambda, mu) << "%" << endl;
    cout << "Durchschnittliche Länge der Warteschlange: " << averageLength(lambda, mu) << endl;
    cout << "Durchschnittliche Wartezeit: " << lambda << " sekunden" << endl;
    cout << "*******************************************" << endl;
    if(wasRemoved) cout << "Wartezeit: " << singleWaitingTime << " sekunden" << endl;
    cout << "Letzte Aktivität: " << action << ticket->name << endl;
}

double Queue::peoplePerMinute(double lambda){
    return 1.0 / (lambda * (1.0 / timeInSeconds)); // 1 / average_time * (1* 60 seconds)
}

double Queue::averageWaitingTime(map<int, typeof(Ticket)> readyQueue){
    int allTime = 0, i = 0;
    for(auto queuePick : readyQueue){
        allTime += (queuePick.second.end_time - queuePick.second.start_time);
        ++i;
    }
    return (double) allTime / i;
}

double Queue::averageEnduranceLevel(double lambda, double mu){
    return (lambda / mu)*100.0; // return in percent value
}

double Queue::averageLength(double lambda, double mu){
    return (lambda * lambda) / (mu * (mu - lambda));
}
