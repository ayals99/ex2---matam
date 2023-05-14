//
// Created by ayals on 5/14/2023.
//

#include "Player.h"

void printInfo() const;
Player(const char* name, int maxHP, int coins);
Player(const Player& player);
~Player();
Player& operator=(const Player& player);


void addCoins(int coins);
void heal(int hpToAdd);
void damage(int hpToReduce);
void levelUp(int levelToAdd);
void buff(int forceToAdd);


void pay(int coinsToPay);

void setName(const char* name);
void setHp(int hp);
void setCoins(int coins);
void setLevel(int level);
void setForce(int force);

/** Getters: **/

/**
 * @return true if the player is knocked out, false otherwise.
 */
bool isKnockedOut() const;

/**
 * @return the player's HP.
 */
int getHp() const;

/**
 * @return the player's coins.
 */
int getCoins() const;

/**
 * @return the player's level.
 */
int getLevel() const;

/**
 * @return the player's force.
 */
int getForce() const;

/**
 * @return the player's name.
 */
const char* getName() const;
/**
 * @return the player's attack strength.
 */
int getAttackStrength() const;