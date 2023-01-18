#ifndef HUMANA_HPP
    #define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
    HumanA(std::string input, Weapon &Arme);
    void attack();
    ~HumanA();

    private:
    const std::string name;
    Weapon &m_arme;
};

#endif