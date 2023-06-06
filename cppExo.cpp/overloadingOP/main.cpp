#include "ex.h"

int main(int argc, char const *argv[])
{
    maze m = createMaze();
    setBlocks(&m);
    setMark(&m);
    displayMaze(&m);
    moveRat(&m);
    return 0;
}