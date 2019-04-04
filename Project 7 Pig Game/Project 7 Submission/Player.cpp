//
//  Player.cpp
//  Pig
//
//

#include "Player.h"

#include <iostream>

namespace cs31
{
    
    Player::Player() : mDie( 6 ), mScore( 0 ), mTotal( 0 )
    {
        
    }
    
    // TODO: roll the die and adjust the score for the current round
    // accordingly
    // when the amount is zero, the Die should be rolled for random play
    // when the amount is not zero, we are trying to cheat for testing
    // purposes.  in that case, this method should force a specific roll
    // amount.
    int Player::roll( int amount )
    {
        int rolledVal = 0;
        // stubbed out for now...
        if(amount==0){
            mDie.roll();
            rolledVal = mDie.getValue();
        }else{
            rolledVal = amount;
        }
        if(rolledVal==1)
            mScore = 0;
        else
            mScore += rolledVal;
        return( rolledVal );
    }
    
    // TODO: add the current score into the running total since the turn ended
    //       reset the current score to 0 for the next round of play
    void Player::endTurn()
    {
        // stubbed out for now...
        mTotal+= mScore;
        mScore = 0;
    }
    
    // TODO: return the current total
    int Player::getTotal( ) const
    {
        // stubbed out for now...
        return( mTotal );
    }
    
    // TODO: return the current total
    int  Player::getScore( ) const
    {
        // stubbed out for now...
        return( mScore );
    }
    

}
