#ifndef EVALUATOR_EVALUATE_H_
#define EVALUATOR_EVALUATE_H_

#include <string>
#include <vector>

namespace evaluator
{
    class Evaluate
    {
    public:
        enum Evaluation 
        {   
            InvalidInput,
            UnreachableState,
            Xwins,
            Owins,
            NoWinner
        };

        Evaluate();
        Evaluate(std::string board);

        Evaluation evaluateBoard();

        void setBoard(std::string board);
        std::string getBoard();

        std::string boardToUpper();

        int * countOccurences(std::string board);

        bool checkForWinner(std::string board, char character);
        bool oneMoreX(std::string board);
        bool equalXO(std::string board);
        bool noOnoX(std::string board);
        bool oWins(std::string board);
        bool xWins(std::string board);
        bool noWinner(std::string board);
        bool unreachableState(std::string board);
        bool moreOthanX(std::string board);
        bool tooManyX(std::string board);
        bool notEnoughX(std::string board);
        bool notEnoughO(std::string board);

    private:
        std::string board_;
        const unsigned long BOARD_SIZE = 9;
       
    };
}

#endif