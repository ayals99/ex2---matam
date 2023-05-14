#include "Player.h"
#include <iostream>
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
void printInfo() const{
    std::cout << "Player Details:";
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Level: " << m_level << std::endl;
    std::cout << "Force: " << m_force << std::endl;
    std::cout << "HP: " << m_hp << std::endl;
    std::cout << "Coins: " << m_coins << std::endl;
}

/*
 * Three constructors for a player:
 *
 * @param playerName - The name of the player.
 * @param maxHP - The initial maximum HP.
 * @param coins - The initial amount of coins.
 * @result - The player's name, HP and coins are set to the given values.
 *      An instance of Mtmchkin
*/

/* First Constructor */
Player(const char* name, int maxHP, int coins){
}

/* Second Constructor */
Player(const char* name, int maxHP){
}

/*Third Constructor */
Player(const char* name){
}

/*
 * Copy constructor for a player:
 *
 * @param player - The player to copy.
 * @result - An instance of Player with the same values as the given player.
*/
Player(const Player& player){

}

/*
 * Destructor for a player:
 *
 * @param player - The player to destroy.
 * @result - The player is destroyed.
 *
*/
~Player(){

}

/*
 * Assignment operator for a player:
 *
 * @param player - The player to assign.
 * @result - The player is assigned.
 *
*/
Player& operator=(const Player& player){

}


/** Getters: **/

/**
 * @return true if the player is knocked out, false otherwise.
 */
bool isKnockedOut() const{

}

/**
 * @return the player's HP.
 */
int getHp() const{

}

/**
 * @return the player's coins.
 */
int getCoins() const{

}

/**
 * @return the player's level.
 */
int getLevel() const{

}

/**
 * @return the player's force.
 */
int getForce() const{

}

/**
 * @return the player's name.
 */
const char* getName() const{

}

/**
 * @return the player's attack strength.
 */
int getAttackStrength() const{

}

/** Setters: **/

/**
 * @param name - The name to set.
 * @return void
 */
void setName(const char* name){

}

/**
 * @param hp - The HP to set.
 * @return void
 */
void setHp(int hp){

}

/**
 * @param coins - The coins to set.
 * @return void
 */
void setCoins(int coins){

}

/**
 * @param level - The level to set.
 * @return void
 */
void setLevel(int level){

}

/**
 * @param force - The force to set.
 * @return void
 */
void setForce(int force){

}

/**
 * @param coinsToAdd - The amount of coins to add to the player.
 * @return void
 */
void addCoins(int coinsToAdd){

}

/**
 * @param hpToAdd - The amount of HP to add to the player.
 * @return void
 */
void heal(int hpToAdd){

}

/**
 * @param hpToReduce - The amount of HP to reduce from the player.
 * @return void
 */
void damage(int hpToReduce){

}

/**
 * @param levelToAdd - The amount of levels to add to the player.
 * @return void
 */
void levelUp(int levelToAdd){

}

/**
 * @param forceToAdd - The amount of force to add to the player.
 * @return void
 */
void buff(int forceToAdd){

}

/**
 * @param coinsToPay - The amount of coins to pay.
 * @return void
 */
void pay(int coinsToPay){

}