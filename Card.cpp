#include "Card.h"
#include <iostream>
using std::cout;
using std::endl;


/*Functions Signatures*/
bool handleBattleCard(Player& player, const CardStats& card);
void handleBuffCard(Player& player, const CardStats& card);
void handleHealCardplayer(Player& player, const CardStats& card);
void handleTreasureCardplayer(Player& player, const CardStats& card);


/*Const Defines*/

const char* LINE_DIVIDER  = "------------------------";





/*
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

/*
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
          handleHealCardplayer(player, m_stats);
     }
     else{
          handleTreasureCardplayer(player, m_stats);
     }
     player.printInfo();
}

bool handleBattleCard(Player& player, const CardStats& card){
     int playerForce = player.getAttackStrength();
     int monsterForce = card.force;
     int monsterLoot = card.loot;
     int potentialHPloss = card.hpLossOnDefeat;

     printBattleCardInfo(card);

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


void handleBuffCard(Player& player, const CardStats& card){
     printBuffCardInfo(card);
     if (player.pay(card.cost))
     {
          player.buff(card.buff);
     }
}


void handleHealCardplayer(Player& player, const CardStats& card){
     printHealCardInfo(card);
     if (player.pay(card.cost))
     {
          player.heal(card.heal);
     }
}

void handleTreasureCardplayer(Player& player, const CardStats& card){
     printTreasureCardInfo(card);
     player.addCoins(card.loot);
}





/*
     * Prints the card info:
     *
     * @return
     *      void
*/
void Card::printInfo() const{
     cout << "Card drawn: " << endl;
     cout << "Type: " << std::to_string((int)m_effect) << endl;
     cout << "Force: " << this->m_stats.force << endl;
     cout << "Profit (on win): " << this->m_stats.loot << endl;
     cout << "Dameg taken (on loss): " << this->m_stats.hpLossOnDefeat << endl;
     cout << LINE_DIVIDER << endl;
}
