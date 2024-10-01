#include "GameMechs.h"
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"



GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    srand(time(NULL));

    //defualt board size
    boardSizeX = 30; 
    boardSizeY = 15;

    foodPos.setObjPos(-1,-1,'o'); // Initialized out side of game board (not to be displayed)

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    srand(time(NULL));

    boardSizeX = boardX; 
    boardSizeY = boardY;
    foodPos.setObjPos(-1,-1,'o'); // Initialized out side of game board (not to be displayed)
    
}

// do you need a destructor?

GameMechs::~GameMechs()
{
    //did not allocate any new memory
}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar()) 
    {
        input = MacUILib_getChar();
    } 

    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;

}

void GameMechs::setLoseTrue()
{
    loseFlag = true;
}


void GameMechs::setInput(char this_input)
{
    input = this_input;
}


void GameMechs::clearInput()
{
    input = 0;
}



void GameMechs::incrementScore()
{
    score += 1;
}


void GameMechs::generateFood(objPosArrayList *blockOff)
{
 
    objPos random;
    objPos posCheck;

    //setting up empty arrays as lookup tables
    int xCoords[30] = {0};
    int yCoords[15] = {0};
    
    
    do{ // Generate random coordinates within range
    
    for(int k = 0; k < blockOff -> getSize(); k++)
    {
    
        //refer to element k and get the coord of player character at that index
        blockOff -> getElement(posCheck, k);

        //use lookup table method to check if generated food overlaps a player character 
        xCoords[posCheck.x] = 1;
        yCoords[posCheck.y] = 1;

        random.x = rand() % (boardSizeX - 2) + 1;
        random.y = rand() % (boardSizeY - 2) + 1;

        if(xCoords[random.x] == 1 && yCoords[random.y] == 1)
        {
            random.x = rand() % (boardSizeX - 2) + 1;
            random.y = rand() % (boardSizeY - 2) + 1;
        }
        else
        {
            foodPos.x = random.x;
            foodPos.y = random.y;
        }
  
    }

    } while(foodPos.x < 1 || foodPos.y < 1 ||  foodPos.x >= (boardSizeX - 1) || foodPos.y >= (boardSizeY - 1));
}


void GameMechs::getFoodPos(objPos &returnPos)
{
    // Return food position
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}