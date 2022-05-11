//
//  names.hpp
//  bsy_tickets
//
//  Created by Marco Schöttelkotte on 07.05.22.
//

#ifndef names_hpp
#define names_hpp

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class Names {
public:
    string generateName();
    
private:
    vector<string> first_names = {
        "Marco", "Lukas", "Konstantin", "Amy", "Julia", "Anna", "Günther", "Heike", "Frieda", "Nancy", "Hugo", "Harry",
        "Pascal", "Anton", "Wilma", "Rene", "Robin", "Bella", "Jannik", "Jona", "Serkan", "Manuel", "Tilda", "Bettina", "Timo",
        "Thilo", "Kiki", "Lea", "Laura", "Lara", "Lisa", "Linda", "Edgar", "Moritz", "Zoe", "Roland", "Leo", "Lasse"
    };
    vector<string> sur_names = {
        "Meier", "Müller", "Fischer", "Weber", "Wagner", "Becker", "Peters", "Scholz", "Berger", "Winkler", "Böhm", "Franke",
        "Albrecht", "Vogt", "Jäger", "Stein", "Otto", "Gross", "Graf", "Heinrich"
    };
};
#endif /* names_hpp */
