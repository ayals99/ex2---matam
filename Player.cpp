#include "Player.h"
using std::cout;
using std::endl;


/** Const Defines*/
const char EMPTY_STRING = '\0';
const int MIN_HP = 0;
const int INITIAL_COINS = 0;
const int INITIAL_LEVEL = 1;

/** Function Signatures*/
int my_strlen(const char* str);
char* my_strcpy(char* dest, const char* src);
bool forceIsNegative(int force);
bool maxHPisPositive(int maxHP);

/**
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
}

int my_strlen(const char* str)
{
    int counter = 0;
    while (str[counter] != EMPTY_STRING)
    {
        counter++;
    }
    return counter;
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

bool forceIsNegative(int force){
    return (force < 0);
}

bool maxHPisPositive(int maxHP){
    return (maxHP > 0);
}

/**
 * C'tor of the player
 *
 * @param playerName - The name of the player. Can be assumed to be valid.
 * @param maxHP - The initial maximum HP.
 *                If not given, the default value is used.
 *                If the given value is negative or zero, the default value is used.
 * @param coins - The initial amount of coins.
 *                If not given, the default value is used.
 *                If the given value is negative, the default value is used.
 * @result - An instanceof Player. The player's name, HP and coins are set to the given values.
*/
Player::Player(const char* name, int maxHP, int force):
m_level(INITIAL_LEVEL), m_force(force), m_hp(maxHP), m_maxHP(maxHP), m_coins(INITIAL_COINS){
    if( !maxHPisPositive(maxHP) ){
        m_maxHP = DEFAULT_MAX_HP;
        m_hp = m_maxHP;
    }
    if(forceIsNegative(force)){
        m_force = DEFAULT_FORCE;
    }
    m_name = new char[my_strlen(name) + 1];
    my_strcpy(m_name, name);
}

/**
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

/**
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

/**
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
    if (this->m_hp <= MIN_HP)
    {
        return true;
    }
    return false;
}

/**
 * @return the player's level.
 */
int Player::getLevel() const{
    return this->m_level;
}

/**
 * @return the player's attack strength.
 */
int Player::getAttackStrength() const{
    return this->m_force + this->m_level;
}

/** Setters: **/

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
    if (hpToReduce > MIN_HP)
    {
        this->m_hp -= hpToReduce;
        if (this->m_hp < MIN_HP)
        {
            this->m_hp = MIN_HP;
        }
    }
}

/**
 * Increases the players level by 1. If the player's level is MAX_LEVEL (10), does nothing.
 * @param none
 * @return void
 */
void Player::levelUp(){
    if (this->m_level < MAX_LEVEL)
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