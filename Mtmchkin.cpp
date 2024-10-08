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
     * D'tor of the game:
     *
     * @result
     *    Frees all the fields of a game.
*/

Mtmchkin::~Mtmchkin(){
    delete [] m_cardArray;
}


/**
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
*/
void Mtmchkin::playNextCard()
{
    Card currentCard = this->m_cardArray[m_currentCard];
    currentCard.printInfo();
    currentCard.applyEncounter(m_player);
     m_currentCard++;
     if (m_currentCard == m_numOfCards)
     {
          m_currentCard = FIRST_CARD;
     }
     if (m_player.isKnockedOut())
     {
          m_gameStatus = GameStatus::Loss;
     }
     else if (m_player.getLevel() == MAX_LEVEL) // MAX_LEVEL = 10 declared in Player.h
     {
          m_gameStatus = GameStatus::Win;
     }
     m_player.printInfo();
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

