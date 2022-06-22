#include "Creature.h"

/*
 * @brief Default constructor
 *
 * @details The default constructor initiates the creature's stats
 *          with a null value (0 for ints and "NONE" for strings),
 *          except for level, which is initialized with 1.
 */
Creature::Creature()
{
    name = "NONE";
    level = 1;
    exp = 0;
    expNext = 0;

    health = 0;
    strength = 0;
    dexterity = 0;
    damage = 0;
    specialDamage = 0;
    natureType = "NONE";
    special = "NONE";

    id = 999;
}

/*
 * @brief Creature constructor taking parameters as arguments
 *
 * @param std::string name, int level, int exp, int expNext, int health
 *        int strength, int dexterity, int damage, int specialDamage,
 *        int std::string& natureType, std::string special, int id
 *
 * @details Constructor which allocates attributes to "this" creature
 *          where "this" attribute points to attribute.
 */
Creature::Creature(std::string name, int level, int exp, int expNext,
                   int health, int strength, int dexterity, int damage,
                   int specialDamage, const std::string natureType,
                   std::string special, int id)
{
    this -> name = std::move(name); // Passed by value and only copied once,
                                    // using std::move() to avoid unnecessary
                                    // copies
    this -> level = level;
    this -> exp = exp;
    this -> expNext = expNext;
    this -> health = health;
    this -> strength = strength;
    this -> dexterity = dexterity;
    this -> damage = damage;
    this -> specialDamage = specialDamage;
    this -> natureType = natureType;
    this -> special = std::move(special);   // Passed by value and only copied
                                            // once using std::move() to
                                            // avoid unnecessary copies
    this -> id = id;
}

/*
 * @brief Default destructor.
 *
 */
Creature::~Creature()
{}


/*
 * @brief A function which returns attributes of creature as one
 *        continuous string
 *
 * @return Returns object of type "std::string"
 */
std::string Creature::getAsString() const
{
    return name + " Lvl:" + std::to_string(level) +
           " Exp:" + std::to_string(exp) + " ExpNext:" +
           std::to_string(expNext) + " Hp:" +
           std::to_string(health) + " Strength:" +
           std::to_string(strength) + " Dexterity:" +
           std::to_string(dexterity) + " Dmg:" +
           std::to_string(damage) + " SpecialDmg:" +
           std::to_string(specialDamage) + "\n  Nature Type: '" +
           natureType + "' SpecialAtk: '" + special + "'\n";
}

/*
 * @brief A function which adds object of type Creature at the end of
 *        the vector, increasing container size by 1.
 *
 * @param taking const reference of object Creature, variable name creature.
 *
 * @return returns void
 */
void Creature::addCreature(const Creature& creature)
{
    this -> creaturesVec.emplace_back(creature);
}

/*
 * @brief A function which declares creatures with attributes and then
 *        inserts them into container
 *
 * @return Returns a container of type std::vector containing objects of type
 *         Creature, creaturesVec
 */
std::vector<Creature> Creature::setUp()
{
    Creature c01 = {"Cerberus", 1, 10, 30, 60,
                   4, 5, 8, 21,
                    "Ice", "Hailstorm",1};

    Creature c02 = {"Empousai", 1, 10, 30, 60,
                    3, 4, 7, 20,
                    "Ice", "Avalanche",2};

    Creature c03 = {"The Fury I", 1, 10, 30, 60,
                    5, 3, 10, 21,
                     "Fire", "Molten Lava Shower",3};

    Creature c04 = {"The Fury II", 1, 10, 30, 60,
                    6, 2, 11, 22,
                    "Fire", "Smoldering Heat",4};

    Creature c05 = {"The Fury III", 1, 10, 30, 60,
                    8, 2, 12, 23,
                    "Fire", "Jupiter's Core",5};

    Creature c06 = {"Chimera", 1, 10, 30, 60,
                    9, 1, 13, 24,
                    "Earth", "The King's Evolution",6};

    Creature c07 = {"Typhon", 1, 10, 30, 60,
                    6, 3, 8, 19,
                    "Water", "Tsunami",7};

    Creature c08 = {"Manticore", 1, 10, 30, 60,
                    9, 1, 13, 25,
                    "Steel", "Solid spikes",8};

    Creature c09 = {"Argus", 1, 10, 30, 60,
                    4,4, 7, 19,
                    "Ice", "Absolute Zero",9};

    Creature c10 = {"Erinyes", 1, 10, 30, 60,
                    6, 3, 9, 20,
                    "Air", "CAT-7",10};

    Creature c11 = {"Harpies", 1, 10, 30, 60,
                    7, 2, 10, 22,
                    "Water", "Monsoon",11};

    Creature c12 = {"Satyr", 1, 10, 30, 60,
                    3, 4, 7, 18,
                    "Air", "Tornado",12};

    Creature c13 = {"Circe", 1, 10, 30, 60,
                    7, 1, 11, 21,
                    "Steel", "Piercing Bullets",13};

    Creature c14 = {"The Scylla", 1, 10, 30, 60,
                    7, 1, 12, 20,
                    "Water", "Gaia's Curse",14};

    Creature c15 = {"Medusa", 1, 10, 30, 60,
                    8, 1, 13, 24,
                    "Earth", "Planetary devastation",15};

    addCreature(c01), addCreature(c02), addCreature(c03);
    addCreature(c04), addCreature(c05), addCreature(c06);
    addCreature(c07), addCreature(c08), addCreature(c09);
    addCreature(c10), addCreature(c11), addCreature(c12);
    addCreature(c13), addCreature(c14);

    return creaturesVec;
}

/*
 * @brief A function which prints elements of type creature present in
 *        a container
 *
 * @param Takes a const reference of a container of type std::vector
 *        containing objects of type <Creature>
 *
 * @return returns void
 */
void Creature::printVec(std::vector<Creature> const &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << i + 1 << "." << vec.at(i).getAsString() << endl;
    }
    cout << "\n" << endl;
}

/*
 * @brief A function which modified current health of creature by decrementing
 *        health by a value of type int called damage dealt
 *
 * @details Modifies health of current creature, also sets value of health
 *          to 0 if health - damageDealt = a result < 0
 *
 * @param variable of type int damage dealt
 *
 * @return Returns void
 *
 */
void Creature::takeDamage(int damageDealt)
{
    this -> health -= damageDealt;

    if (this -> health <= 0)
    {
        this -> health = 0;
    }
}

/*
 * @brief A function which increments the level of the creature by one
 *
 * @details Increments level of current creature by 1 if the exp value
 *          of creature is equal to the value of expNext. This function
 *          also increases expNext of next level by 30.
 *
 * @return Returns void
 */
void Creature::levelUp()
{
    if (this -> exp >= this -> expNext)
    {
        this -> exp -= this -> expNext;
        this -> level++;

        this -> expNext = this -> exp + 30;

        this -> updateStats();

        cout << this -> getName() << " is now level: " << this -> level
             << " !\n" << endl;
    }
    else
    {
        cout << "Not enough exp!" << endl;
    }
}

/*
 * @brief A function that increases stats of current creature
 *        (Implemented after leveling up is achieved for current creature)
 *
 * @return Returns void
 */
void Creature::updateStats()
{
    this -> expNext = this -> exp + 30;
    this -> health += 30;
    this -> dexterity += 1;
    this -> damage = this -> strength + 2;
    this -> specialDamage = this -> specialDamage + 4;
}

/*
 * @brief A function which increases exp for current creature by value
 *        equal to experience
 *
 * @param const variable of type int, experience
 *
 * @return Returns void
 */
void Creature::gainEXP(const int experience)
{
    this -> exp += experience;
}

/*
 * @brief A function which checks if value of health of current creature
 *        is greater than 0
 *
 * @return boolean expression (true or false)
 */
bool Creature::isAlive() const
{
    return this -> health > 0;
}