#include "wizard.h"

//        mago
//        attack=40						custo=25
//        escudo=-2/3 do dano				recupera=25
//        poçao=+1/4 da vida total		custo=25

Wizard::Wizard()
{
    setClasse("Wizard");
    setHpMax(50);
    setSpMax(150);
    setHp(50); //hp para tempo de batalha
    setSp(150); //sp para tempo de batalha
    setDanoAtaque(40); //quanto ele tira no ataque
    setBonusDefesa(25); //Ele recupera de sp quando defende
    setCustoAtaque(25); //quanto ele gasta de sp pra atacar
    setCustoCura(25); //quanto custa de sp custa para ele se curar
    setPorcentagemDefesa(50); //quantos % ele recebe a menos em um ataque se estiver defendendo
    setCura(25); //quanto ele recupera de hp quando usa a cura
}
