#include "Evaluate.h"
#include <string>
#include <iostream>
#include <vector>
#include <locale>

namespace evaluator
{

    //custom constructor to set the board
    Evaluate::Evaluate(std::string board)
	{
        board_ = board;
    }

    //this allows to change the board
    void Evaluate::setBoard(std::string board)
	{
        board_ = board;
    }

    //returns that board string
    std::string Evaluate::getBoard()
	{
        return board_;
    }

    /*
    returns invalid input if the size of the board is not valid
    returns noWinner if none of the previous conditionals get trigered
    */
    Evaluate::Evaluation Evaluate::evaluateBoard()
	{
        
        std::string board = boardToUpper();

        if(board.length() != BOARD_SIZE)
        {
            return InvalidInput;
        }
        else if(unreachableState(board))
        {
            return UnreachableState;
        }
        else if(xWins(board))
        {
            return Xwins;
        }
        else if(oWins(board))
        {
            return Owins;
        }
        else
            return NoWinner;
    }

    /*
    makes the board string uppercase and returns it
    */
    std::string Evaluate::boardToUpper()
	{

        std::string board = getBoard();
        std::locale loc;

        for (std::string::size_type i=0; i<board.length(); ++i)
        {
            board[i] = std::toupper(board[i],loc);
        }
        return board;
    }

    /*
    pass in the board and character that you want to evaluate,
    returns if the character has any winning positions on the board
    doesn't mean that it won indefinitely 
    */
    bool Evaluate::checkForWinner(std::string board, char character)
	{
        if (board[0] == character && board[1] == character && board[2] == character) { return true; }
        if (board[3] == character && board[4] == character && board[5] == character) { return true; }
        if (board[6] == character && board[7] == character && board[8] == character) { return true; }
        if (board[0] == character && board[4] == character && board[8] == character) { return true; }
        if (board[2] == character && board[4] == character && board[6] == character) { return true; }
        if (board[0] == character && board[3] == character && board[6] == character) { return true; }
        if (board[1] == character && board[4] == character && board[7] == character) { return true; }
        if (board[2] == character && board[5] == character && board[8] == character) { return true; }
        else { return false; }
    }
    /*
    counts occurences of X & O on the board, stores X at array[0] and O at array[1]
    returns a pointer to the beginning of the array because C++ sucks and can't return arrays
    */
    int * Evaluate::countOccurences(std::string board)
	{

        static int occurences[2];
		//std::pair
		//std::vector
		//class of occurences
		//difference of the two occurences 
        int xOccurences = 0;
        int oOccurences = 0;

        for(unsigned long letter = 0; letter < board.length(); letter++)
		{

            if(board[letter] == 'X')
			{
                xOccurences++;
            }
            else if(board[letter] == 'O')
			{
                oOccurences++;
            }

        }

        occurences[0] = xOccurences;
        occurences[1] = oOccurences;
        
        return occurences;
    }
    /*
    checks if there is one more X than is allowed
    */
    bool Evaluate::oneMoreX(std::string board)
	{

        int *occurences;
        occurences = countOccurences(board);

        if((*(occurences)-1) == *(occurences+1))
		{
            return true;
        }
        return false;
    }
    /*
    returns true if there is 2 or more X entries on the board than is allowed
    */
    bool Evaluate::tooManyX(std::string board)
	{

        int* occurences;
        occurences = countOccurences(board);

        if((*(occurences) - 1) > *(occurences + 1))
		{
            return true;
        }
        return false;
    }
    /*
    checks if there are more O entries than X entries,
    this should always return false
    */
    bool Evaluate::moreOthanX(std::string board)
	{

        int *occurences;
        occurences = countOccurences(board);

        if(*(occurences + 1) > *(occurences))
		{
            return true;
        }
        return false;
    }
    /*
    checks if there is an equal amount of X & O entries, 
    this must be true if O wins, false if X wins
    */
    bool Evaluate::equalXO(std::string board)
	{

        int *occurences;
        occurences = countOccurences(board);

        if((*(occurences)) == *(occurences+1))
		{
            return true;
        }
        return false;
    }
    /*
    checks if there are no O & no X entries
    */
    bool Evaluate::noOnoX(std::string board)
	{

        int *occurences;
        occurences = countOccurences(board);

        if(((*(occurences)) == 0) && (*(occurences+1) == 0))
		{
            return true;
        }
        return false;
    }
    /*
    checks if there are less X entries than required to win
    */
    bool Evaluate::notEnoughX(std::string board)
	{
        
        int *occurences;
        occurences = countOccurences(board);

        if((*(occurences)) < 3)
        {
            return true;
        }
        return false;
    }
    /*
    checks if there are less O entries than is required to win
    */
    bool Evaluate::notEnoughO(std::string board)
	{

        int *occurences;
        occurences = countOccurences(board);

        if((*(occurences + 1)) < 3)
        {
            return true;
        }
        return false;
    }
    /*
    final check to see if O won
    */
    bool Evaluate::oWins(std::string board)
	{

        int *occurences;
        occurences = countOccurences(board);

        if(checkForWinner(board, 'O') && !checkForWinner(board, 'X') &&
        !(board.length() > BOARD_SIZE) && !noWinner(board) && 
        equalXO(board) && !moreOthanX(board) &&
        !tooManyX(board) && !noOnoX(board)) 
        {
            return true;
        }
        return false;
    }
    /*
    final check to see if X won
    */
    bool Evaluate::xWins(std::string board)
	{

        int *occurences;
        occurences = countOccurences(board);

        if(checkForWinner(board,'X') && !checkForWinner(board, 'O') && 
        !(board.length() > BOARD_SIZE) && 
        !equalXO(board) && !moreOthanX(board) &&
        !tooManyX(board) && !noOnoX(board))
        {
            return true;
        }
        return false;
    }
    /*
    checks if there are no winners
    */
    bool Evaluate::noWinner(std::string board)
	{

        int *occurences;
        occurences = countOccurences(board);

        if((!checkForWinner(board, 'X') && !checkForWinner(board, 'O')) || 
        notEnoughO(board) || notEnoughX(board)|| noOnoX(board))
        {
            return true;
        }
        return false;
    }
    /*
    checks if there is an unreachable state:
    more O than X, O wins and there isn't an equal amount of X & O entries
    too many X, X wins and there is an equal amount of X & O entries
    */
    bool Evaluate::unreachableState(std::string board)
	{

        int *occurences;
        occurences = countOccurences(board);

        if(tooManyX(board) ||
        (checkForWinner(board, 'O') && !equalXO(board)) ||
        (checkForWinner(board, 'X') && equalXO(board)) || 
        moreOthanX(board) || tooManyX(board))
        {
            return true;
        } 
        return false;
    }
}

    

