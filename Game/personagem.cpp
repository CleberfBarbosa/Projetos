#include "personagem.h"

int Personagem::getHpMax() const
{
    return hpMax;
}

void Personagem::setHpMax(int value)
{
    hpMax = value;
}

int Personagem::getSpMax() const
{
    return spMax;
}

void Personagem::setSpMax(int value)
{
    spMax = value;
}

int Personagem::getHp() const
{
    return hp;
}

void Personagem::setHp(int value)
{
    hp = value;
}

int Personagem::getSp() const
{
    return sp;
}

void Personagem::setSp(int value)
{
    sp = value;
}

int Personagem::getCustoAtaque() const
{
    return custoAtaque;
}

void Personagem::setCustoAtaque(int value)
{
    custoAtaque = value;
}

int Personagem::getDanoAtaque() const
{
    return DanoAtaque;
}

void Personagem::setDanoAtaque(int value)
{
    DanoAtaque = value;
}

int Personagem::getCustoCura() const
{
    return custoCura;
}

void Personagem::setCustoCura(int value)
{
    custoCura = value;
}

std::string Personagem::getClasse() const
{
    return classe;
}

void Personagem::setClasse(const std::string &value)
{
    classe = value;
}

float Personagem::getPorcentagemDefesa() const
{
    return porcentagemDefesa;
}

void Personagem::setPorcentagemDefesa(float value)
{
    porcentagemDefesa = value;
}

int Personagem::getBonusDefesa() const
{
    return bonusDefesa;
}

void Personagem::setBonusDefesa(int value)
{
    bonusDefesa = value;
}

int Personagem::getCura() const
{
    return cura;
}

void Personagem::setCura(int value)
{
    cura = value;
}

void Personagem::setWarrior(){
    //        guerreiro
    //        attack=10						custo=25
    //        escudo=-2/3 do dano				recupera=25
    //        poçao=+1/4 da vida total		custo=25

    setClasse("Warrior");
    setHpMax(200);
    setSpMax(50);
    setHp(200); //hp para tempo de batalha
    setSp(50); //sp para tempo de batalha
    setDanoAtaque(10); //quanto ele tira no ataque
    setBonusDefesa(25); //Ele recupera de sp quando defende
    setCustoAtaque(25); //quanto ele gasta de sp pra atacar
    setCustoCura(25); //quanto custa de sp custa para ele se curar
    setPorcentagemDefesa(0.25); //quantos % ele recebe a menos em um ataque se estiver defendendo
    setCura(20); //quanto ele recupera de hp quando usa a cura

}


void Personagem::setWizard(){

    //        mago
    //        attack=40						custo=25
    //        escudo=-2/3 do dano				recupera=25
    //        poçao=+1/4 da vida total		custo=25

    setClasse("Wizard");
    setHpMax(50);
    setSpMax(150);
    setHp(50); //hp para tempo de batalha
    setSp(150); //sp para tempo de batalha
    setDanoAtaque(40); //quanto ele tira no ataque
    setBonusDefesa(25); //Ele recupera de sp quando defende
    setCustoAtaque(40); //quanto ele gasta de sp pra atacar
    setCustoCura(25); //quanto custa de sp custa para ele se curar
    setPorcentagemDefesa(0.5); //quantos % ele recebe a menos em um ataque se estiver defendendo
    setCura(15); //quanto ele recupera de hp quando usa a cura
}


void Personagem::setAssassin(){
    //        Ladrao
    //        attack=20						custo=25
    //        escudo=-2/3 do dano				recupera=25
    //        poçao=+1/4 da vida total		custo=25

    setClasse("Assassin");
    setHpMax(100);
    setSpMax(100);
    setHp(100); //hp para tempo de batalha
    setSp(100); //sp para tempo de batalha
    setDanoAtaque(20); //quanto ele tira no ataque
    setBonusDefesa(25); //Ele recupera de sp quando defende
    setCustoAtaque(25); //quanto ele gasta de sp pra atacar
    setCustoCura(25); //quanto custa de sp custa para ele se curar
    setPorcentagemDefesa(0.3); //quantos % ele recebe a menos em um ataque se estiver defendendo
    setCura(25); //quanto ele recupera de hp quando usa a cura
}

Personagem::Personagem(std::string classe)
{
    if(classe=="Warrior"){
        setWarrior();
    }else if(classe=="Wizard"){
        setWizard();
    }else{
        setAssassin();
    }
}
