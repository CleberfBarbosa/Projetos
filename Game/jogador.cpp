#include "jogador.h"

Jogador::Jogador(std::string person)
{
    if(person == "Warrior"){
        Warrior();
    }else if(person == "Wizard"){
        Wizard();
    }else if(person == "Assassin"){
        Assassin();
    }
}
