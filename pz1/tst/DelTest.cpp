#include "Set.h"

int DelTest(int argc, char *argv[])
{
    Set s(10, 20);
    s.add(11); s.add(12); s.add(15);

    s.del(12);

    if(!s.poisk(12)) {
        return false;
    } else {
        return true;
    }
}