#ifndef EX2_MATAM_PLAYER_H
#define EX2_MATAM_PLAYER_H
#include "utilities.h"
#include <string>
#include <iostream>

const int DEFAULT_MAX_HP = 100;
const int DEFAULT_FORCE = 5;


class Player {
    char* m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_maxHP;
    int m_coins;

    public:
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
    void printInfo() const;

    /* 
     * Three constructors for a player:
     *
     * @param playerName - The name of the player.
     * @param maxHP - The initial maximum HP.
     * @param coins - The initial amount of coins.
     * @result - The player's name, HP and coins are set to the given values.
     *      An instance of Mtmchkin
    */
     Player(const char* name,  int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /*
     * Copy constructor for a player :
     *
     * @param player - The player to copy.
     * @result - An instance of Player with the same values as the given player.
    */
    Player(const Player& player);

    /*
     * Destructor for a player:
     *
     * @param player - The player to destroy.
     * @result - The player is destroyed.
     *
    */
    ~Player();

    /*
     * Assignment operator for a player:
     *
     * @param player - The player to assign.
     * @result - The player is assigned.
     *
    */
    Player& operator=(const Player& player);


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

    /** Setters: **/

    // /**
    //  * @param name - The name to set.
    //  * @return void
    //  */
    // void setName(const char* name);

    // /**
    //  * @param hp - The HP to set.
    //  * @return void
    //  */
    // void setHp(int hp);

    // /**
    //  * @param coins - The coins to set.
    //  * @return void
    //  */
    // void setCoins(int coins);

    // /**
    //  * @param level - The level to set.
    //  * @return void
    //  */
    // void setLevel(int level);

    // /**
    //  * @param force - The force to set.
    //  * @return void
    //  */
    // void setForce(int force);

    /**
     * @param coinscoinsToAdd - The amount of coins to add to the player.
     * @return void
     */
    void addCoins(int coinsToAdd);

    /**
     * @param hpToAdd - The amount of HP to add to the player.
     * @return void
     */
    void heal(int hpToAdd);

    /**
     * Reduces the player's HP by the given amount. If the damage is 0 or less, does nothing.
     * Only reduces the player's HP to 0, not below.
     * @param hpToReduce - The amount of HP to reduce from the player.
     * @return void
     */
    void damage(int hpToReduce);

    /**
     * @param forceToAdd - The amount of force to add to the player.
     * @return void
     */
    void buff(int forceToAdd);

    /**
     * @param coinsToPay - The amount of coins to pay.
     * @return true if the player has enough coins to pay. false otherwise.
     */
    bool pay(int coinsToPay);

    /**
     * Increases the players level by 1. If the player's level is 10, does nothing.
     * @param none
     * @return void
     */
    void levelUp();
};

#endif //EX2_MATAM_PLAYER_H