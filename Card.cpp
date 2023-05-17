#include "Card.h"
using std::cout;
using std::endl;


/*Functions Signatures*/
bool handleBattleCard(Player& player, const CardStats& card);
void handleBuffCard(Player& player, const CardStats& card);
void handleHealCard(Player& player, const CardStats& card);
void handleTreasureCard(Player& player, const CardStats& card);
std::string effectToString(CardType m_effect);



/**Const Defines*/


const char* DIVIDER  = "------------------------";




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

bool handleBattleCard(Player& player, const CardStats& card){
     int playerForce = player.getAttackStrength();
     int monsterForce = card.force;
     int monsterLoot = card.loot;
     int potentialHPloss = card.hpLossOnDefeat;

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
     if (player.pay(card.cost))
     {
          player.buff(card.buff);
     }
}


void handleHealCard(Player& player, const CardStats& card){
     if (player.pay(card.cost))
     {
          player.heal(card.heal);
     }
}

void handleTreasureCard(Player& player, const CardStats& card){
     player.addCoins(card.loot);
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


std::string effectToString(CardType m_effect)
    {
        if (m_effect == CardType::Battle)
        {
            return "Battle";
        }
        else if (m_effect == CardType::Treasure)
        {
            return "Treasure";
        }
        else if (m_effect == CardType::Buff)
        {
            return "Buff";
        }
        else
        {
            return "Heal";
        }
    }