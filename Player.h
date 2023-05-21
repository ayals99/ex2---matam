#ifndef EX2_MATAM_PLAYER_H
#define EX2_MATAM_PLAYER_H
#include "utilities.h"
#include <string>
#include <iostream>

const int DEFAULT_MAX_HP = 100;
const int DEFAULT_FORCE = 5;
const int MAX_LEVEL = 10;


class Player {
    char* m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_maxHP;
    int m_coins;

    public:
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
    void printInfo() const;

    /**
     * Constructor of the player:
     *
     * @param playerName - The name of the player. Can be assumed to be valid.
     * @param maxHP - The initial maximum HP.
     *                If not given, the default value is used.
     *                If the given value is negative or zero, the default value is used.
     * @param coins - The initial amount of coins.
     *                If not given, the default value is used.
     *                If the given value is negative, the default value is used.
     * @result - An instanceof Player. The player's name, HP and coins are set to the given or defaault values.
    */
     explicit Player(const char* name,  int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);

    /**
     * Copy constructor for a player :
     *
     * @param player - The player to copy.
     * @result - An instance of Player with the same values as the given player.
    */
    Player(const Player& player);

    /**
     * Destructor for a player:
     *
     * @param player - The player to destroy.
     * @result - The player is destroyed.
     *
    */
    ~Player();

    /**
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
     * @return the player's level.
     */
    int getLevel() const;

    /**
     * @return the player's attack strength.
     */
    int getAttackStrength() const;

    /** Setters: **/

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