#include "objPosArrayList.h"


objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP]; // Provides 200 elements on the heap
    listSize = 0;                      // No valid elements in the list upon startup
    arrayCapacity = ARRAY_MAX_CAP;     // Array capacity should be max
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList; 
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        return;
    }

    for (int i = listSize; i > 0; i--) // Start at empty space after last element, copy last element to new inset position
    {
        aList[i].setObjPos(aList[i - 1]); // This shuffles all the elements towards the tail (right)
    }
    
    aList[0].setObjPos(thisPos); // Insert the new element at the head (or the first position)
    
    listSize++; // Increment listSize as you add a new head element
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize == arrayCapacity)
    {
        return;
    }
    
    
    aList[listSize].setObjPos(thisPos); // Insert the element at the tail (or the last position)

    listSize++; // Increment listSize as you add a new tail element
}

void objPosArrayList::removeHead()
{
    if (listSize == 0) // Error check: If list is empty, remove nothing.
    {
        return;
    }

    for (int i = 0; i < listSize - 1; i++) // Opposite of insertHead()!
    {
        aList[i].setObjPos(aList[i + 1]); // This shuffles all the elements to the right, overwriting the head
    }

    listSize--; // Decrement listSize as you remove a head element
}

void objPosArrayList::removeTail()
{
    if (listSize == 0) // Error check: If list is empty, remove nothing.
    {
        return;
    }

    listSize--; // Decrement listSize as you remove a tail element
}

// The x-y coordinate and the symbol of relevent element in the next 3 are written into returnPos

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]); // Index at [0] gives first element
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize - 1]); // Index at [listSize - 1] gives last element
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]); // Index at [int index] gives nth element
}