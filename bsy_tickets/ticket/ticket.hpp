//
//  ticket.hpp
//  bsy_tickets
//
//  Created by Marco Schöttelkotte on 25.04.22.
//

#ifndef ticket_hpp
#define ticket_hpp

#include <iostream>
#include <ctime>

using namespace std;
class Ticket {
public:
    string name;
    time_t start_time;
    time_t end_time;
};

#endif /* ticket_hpp */
