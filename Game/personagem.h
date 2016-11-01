#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <queue>
#include <iostream>

class Personagem
{
private:
    std::string classe;

    int hpMax, spMax, hp, sp, custoAtaque, DanoAtaque, custoCura, bonusDefesa, cura;
    float  porcentagemDefesa;
public:

    Personagem(std::string classe);

    //Fiz ela publica por preguiça de implementar os set e get dela(Deixa o eugênio ver isso kkkkkkkkkkkkkkkkkk)
    std::queue<std::string> movimentos;

    //Definição das caracteristicas do personagem, tentei usar herança mais deu merda, ai fiz assim
    void setWarrior();
    void setWizard();
    void setAssassin();

    //Setters e getters padrões
    int getHpMax() const;
    void setHpMax(int value);
    int getSpMax() const;
    void setSpMax(int value);
    int getHp() const;
    void setHp(int value);
    int getSp() const;
    void setSp(int value);
    int getCustoAtaque() const;
    void setCustoAtaque(int value);
    int getDanoAtaque() const;
    void setDanoAtaque(int value);
    int getCustoCura() const;
    void setCustoCura(int value);
    std::string getClasse() const;
    void setClasse(const std::string &value);
    float getPorcentagemDefesa() const;
    void setPorcentagemDefesa(float value);
    int getBonusDefesa() const;
    void setBonusDefesa(int value);
    int getCura() const;
    void setCura(int value);

};

#endif // PERSONAGEM_H
