#ifndef PJC_11C_SUMMER22_ITN_CREATURE_H
#define PJC_11C_SUMMER22_ITN_CREATURE_H

#include "Game.h"

class Creature
{
public:

    Creature();
    Creature(std::string name, int level, int exp, int expNext,
             int health, int strength, int dexterity, int damage,
             int specialDamage, const std::string natureType,
             std::string special, int id);
    virtual ~Creature();
    std::vector<Creature> creaturesVec;

    //FUNCTIONS
    std::string getAsString() const;
    void addCreature(const Creature& creature);
    std::vector<Creature> setUp();
    static void printVec(std::vector<Creature> const& vec);
    void updateStats();
    void levelUp();


    //ACCESSORS
    inline const std::string& getName() const
    {
        return this -> name;
    }

    inline const int& getLevel() const
    {
      return this -> level;
    }

    inline const int& getExp() const
    {
        return this -> exp;
    }

    inline const int& getExpNext() const
    {
        return this -> expNext;
    }

    inline const int& getHealth() const
    {
        return this -> health;
    }

    inline const int& getStrength() const
    {
        return this -> strength;
    }

    inline const int& getDexterity() const
    {
        return this -> dexterity;
    }

    inline const int& getDamage() const
    {
        return this -> damage;
    }

    inline const int& getSpecialDamage() const
    {
        return this -> specialDamage;
    }

    inline const std::string& getNatureType() const
    {
        return this -> natureType;
    }

    inline const std::string& getSpecial() const
    {
        return this -> special;
    }

    inline const int& getID() const
    {
        return this -> id;
    }

    //MODIFIERS
    void takeDamage(int damage);
    void gainEXP(const int exp);
    bool isAlive() const;

private:

    std::string name;
    int level;
    int exp;
    int expNext;

    int health;
    int strength;
    int dexterity;
    int damage;
    int specialDamage;
    std::string natureType;
    std::string special;

    int id;
};
#endif //PJC_11C_SUMMER22_ITN_CREATURE_H