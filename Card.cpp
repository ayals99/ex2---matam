#include "Card.h"
using std::cout;
using std::endl;


/**Functions Signatures*/
bool handleBattleCard(Player& player, const CardStats& card);
void handleBuffCard(Player& player, const CardStats& card);
void handleHealCard(Player& player, const CardStats& card);
void handleTreasureCard(Player& player, const CardStats& card);

/**
 * C'tor of Card class
 *
 * @param type - The type of the card.
 * @param stats - The numeral stats of the card.
 * @return
 *      A new instance of Card.
*/
Card::Card(CardType type, const CardStats& stats){
     m_effect = type;
     m_stats = stats;
}

/**
 * Handling the player's applyEncounter with the card:
 *
 * @param player - The player.
 * @return
 *      void
*/
void Card::applyEncounter(Player& player) const{
     if (m_effect == CardType::Battle){
          printBattleResult(handleBattleCard(player, m_stats));
     }
     else if (m_effect == CardType::Buff){
          handleBuffCard(player, m_stats);
     }
     else if (m_effect == CardType::Heal){
         handleHealCard(player, m_stats);
     }
     else{
         handleTreasureCard(player, m_stats);
     }
}

/**
 * Handling the player's applyEncounter with the card.
 * @return true if the player won the encounter or false if lost.
*/
bool handleBattleCard(Player& player, const CardStats& card){
     int playerForce = player.getAttackStrength();
     int monsterForce = card.force;
     int monsterLoot = (card.loot > 0) ? card.loot : 0;
     int potentialHPloss = (card.hpLossOnDefeat > 0) ? card.hpLossOnDefeat : 0;
     if(playerForce >= monsterForce)
     {
         player.addCoins(monsterLoot);
         player.levelUp();
         return true;
     }
     else
     {
          player.damage(potentialHPloss);
          return false;
     }
}

/**
 * Handling the player's applyEncounter with the card.
*/
void handleBuffCard(Player& player, const CardStats& card){
    if (card.cost < 0 || player.pay(card.cost))
     {
         if(card.buff > 0){
             player.buff(card.buff);
         }
     }
}

/**
 * Handling the player's applyEncounter with the card.
*/
void handleHealCard(Player& player, const CardStats& card){
    if (card.cost < 0 || player.pay(card.cost))
     {
         if(card.heal > 0){
             player.heal(card.heal);
         }
     }
}

/**
 * Handling the player's applyEncounter with the card.
*/
void handleTreasureCard(Player& player, const CardStats& card){
    if(card.loot > 0) {
        player.addCoins(card.loot);
    }
}

/**
     * Prints the card info:
     *
     * @return
     *      void
*/
void Card::printInfo() const{
    if (m_effect == CardType::Battle){
        printBattleCardInfo(m_stats);
    }
    else if (m_effect == CardType::Buff){
        printBuffCardInfo(m_stats);
    }
    else if (m_effect == CardType::Heal){
        printHealCardInfo(m_stats);
    }
    else{
        printTreasureCardInfo(m_stats);
    }
}