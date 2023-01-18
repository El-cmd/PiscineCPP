#ifndef HUMANB_HPP
    #define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
    HumanB(std::string input);
    void setWeapon(Weapon &input);
    void attack();
    ~HumanB();

    private:
    std::string name;
    Weapon *m_arme;
};

#endif