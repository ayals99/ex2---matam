#include "Mtmchkin.h"

const int FIRST_CARD = 0;

/**
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
*/
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
m_player(playerName),  m_numOfCards(numOfCards), m_currentCard(FIRST_CARD), m_gameStatus(GameStatus::MidGame)
{
     m_cardArray = new Card[numOfCards];
     for(int i = 0; i < numOfCards; i++)
     {
          m_cardArray[i] = cardsArray[i];
     }
}

/**
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
*/
void Mtmchkin::playNextCard()
{    
     this->m_cardArray[m_currentCard].applyEncounter(m_player);
     m_currentCard++;
     if (m_currentCard == m_numOfCards)
     {
          m_currentCard = FIRST_CARD;
     }
     if (m_player.isKnockedOut())
     {
          m_gameStatus = GameStatus::Loss;
     }
     else if (m_player.getLevel() == 10)
     {
          m_gameStatus = GameStatus::Win;
     }     
}

/**
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
bool Mtmchkin::isOver() const
{
  if (this->getGameStatus() != GameStatus::MidGame)
  {
       return true;
  }
  else
  {
       return false;
  }
}


/**
 *  Get the status of the game:
 *
 *  @return
 *          GameStatus - the current status of the running game
 */
GameStatus Mtmchkin::getGameStatus() const
{
     return m_gameStatus;
}

