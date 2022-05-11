//
//  names.cpp
//  bsy_tickets
//
//  Created by Marco Schöttelkotte on 07.05.22.
//

#include "names.hpp"
using namespace std;

string Names::generateName() {
    srand((unsigned int) time(NULL));
    int r1 = rand() % first_names.size();
    int r2 = rand() % sur_names.size();
    return first_names[r1] + " " + sur_names[r2];
}
