#include "Set.h"

int AddTest(int argc, char *argv[])
{
    Set s(10, 20);
    s.add(11);

    if(s.poisk(11)) {
        return false;
    } else {
        return true;
    }
}