#ifndef JOGADOR_H
#define JOGADOR_H
#include <warrior.h>
#include <wizard.h>
#include <assassin.h>

class Jogador : public Warrior, public Wizard, public Assassin
{
public:
    Jogador(std::string person);
};

#endif // JOGADOR_H
