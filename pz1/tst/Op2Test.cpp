#include "Set.h"

int Op2Test(int argc, char *argv[])
{
    Set s1(10, 20);
    Set s2(10, 20);
    s1.add(11); s1.add(15); s1.add(18);
    s2.add(11); s2.add(12);
    Set s3 = s1 * s2;
    if(s3.poisk(11) && !s3.poisk(12) && !s3.poisk(15) && !s3.poisk(18)){
        return false;
    } else {
        return true;
    }
}