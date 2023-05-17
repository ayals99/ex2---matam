#include "Player.h"
using std::cout;
using std::endl;


/* Const Defenitions*/
const char EMPTY_STRING = '\0';


/* Function Signatures*/
int my_strlen(const char* str);
char* my_strcpy(char* dest, const char* src);


/*
     * Prints the details of the player:
     *
     * @param name - The name of the player.
     * @param level - The player's level.
     * @param force - The player's force.
     * @param hp - The player's HP points.
     * @param coins - The player's amount of coins.
     *
     * @return void
     */
    void Player::printInfo() const {
    printPlayerInfo(m_name, m_level, m_force, m_hp, m_coins);
  ;
}

int my_strlen(const char* str)
{
    int i = 0;
    while (str[i] != EMPTY_STRING)
    {
        i++;
    }
    return i;
}

char* my_strcpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != EMPTY_STRING)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = EMPTY_STRING;
    return dest;
}

/*
 * C'tor of the player
 *
 * @param playerName - The name of the player.
 * @param maxHP - The initial maximum HP.
 * @param coins - The initial amount of coins.
 * @result - The player's name, HP and coins are set to the given values.
 *      An instance of Mtmchkin
*/
Player::Player(const char* name, int maxHP, int force):
m_level(1), m_force(force), m_hp(maxHP), m_maxHP(maxHP), m_coins(0)
{
    m_name = new char[my_strlen(name) + 1];
    my_strcpy(m_name, name);
}

/*
 * Copy constructor for a player:
 *
 * @param player - The player to copy.
 * @result - An instance of Player with the same values as the given player.
*/
Player::Player(const Player& player){
    m_name = new char[my_strlen(player.m_name) + 1];
    my_strcpy(m_name, player.m_name);
    m_level = player.m_level;
    m_force = player.m_force;
    m_hp = player.m_hp;
    m_maxHP = player.m_maxHP;
    m_coins = player.m_coins;
}

/*
 * Assignment operator for a player:
 *
 * @param player - The player to assign.
 * @result - The player is assigned.
 *
*/
Player& Player::operator=(const Player& player) {
    if (this == &player){
        return *this;
    }
    delete[] m_name;
    m_name = new char[my_strlen(player.m_name) + 1];
    my_strcpy(m_name, player.m_name);
    m_level = player.m_level;
    m_force = player.m_force;
    m_hp = player.m_hp;
    m_maxHP = player.m_maxHP;
    m_coins = player.m_coins;
    return *this;
}

/*
     * Destructor for a player:
     *
     * @param player - The player to destroy.
     * @result - The player is destroyed.
     *
    */
    Player::~Player(){
    delete[] m_name;
    }


/** Getters: **/

/**
 * @return true if the player is knocked out, false otherwise.
 */
bool Player::isKnockedOut() const{
    if (this->m_hp <= 0)
    {
        return true;
    }
    return false;
}

/**
 * @return the player's HP.
 */
int Player::getHp() const{
    return this->m_hp;
}

/**
 * @return the player's coins.
 */
int Player::getCoins() const{
    return this->m_coins;
}

/**
 * @return the player's level.
 */
int Player::getLevel() const{
    return this->m_level;
}

/**
 * @return the player's force.
 */
int Player::getForce() const{
    return this->m_force;
}

/**
 * @return the player's name.
 */
const char* Player::getName() const{
    return this->m_name;
}

/**
 * @return the player's attack strength.
 */
int Player::getAttackStrength() const{
    return this->m_force + this->m_level;
}

/** Setters: **/

// /**
//  * @param name - The name to set.
//  * @return void
//  */
// void setName(const char* name){

// }

// /**
//  * @param hp - The HP to set.
//  * @return void
//  */
// void setHp(int hp){

// }

// /**
//  * @param coins - The coins to set.
//  * @return void
//  */
// void setCoins(int coins){

// }

// /**
//  * @param level - The level to set.
//  * @return void
//  */
// void setLevel(int level){

// }

// /**
//  * @param force - The force to set.
//  * @return void
//  */
// void setForce(int force){

// }

/**
 * @param coinsToAdd - The amount of coins to add to the player.
 * @return void
 */
void Player::addCoins(int coinsToAdd){
    this->m_coins += coinsToAdd;
}

/**
 * @param hpToAdd - The amount of HP to add to the player.
 * @return void
 */
void Player::heal(int hpToAdd){
    this->m_hp += hpToAdd;
    if (this->m_hp > this->m_maxHP)
    {
        this->m_hp = this->m_maxHP;
    }
}

/**
 * Reduces the player's HP by the given amount. If the damage is 0 or less, does nothing.
 * Only reduces the player's HP to 0, not below.
 * @param hpToReduce - The amount of HP to reduce from the player.
 * @return void
 */
void Player::damage(int hpToReduce){
    if (hpToReduce > 0)
    {
        this->m_hp -= hpToReduce;
        if (this->m_hp < 0)
        {
            this->m_hp = 0;
        }
    }
}

/**
 * Increases the players level by 1. If the player's level is 10, does nothing.
 * @param none
 * @return void
 */
void Player::levelUp(){
    if (this->m_level < 10)
    {
        this->m_level++;
    }
}

/**
 * @param forceToAdd - The amount of force to add to the player.
 * @return void
 */
void Player::buff(int forceToAdd){
    this->m_force += forceToAdd;
}

/**
 * @param coinsToPay - The amount of coins to pay.
 * @return void
 */
bool Player::pay(int coinsToPay){
    if (this->m_coins >= coinsToPay)
    {
        this->m_coins -= coinsToPay;
        return true;
    }
    return false;
}