#include"epee.h"

epee::epee(double pointSolidite):
    equipement{pointSolidite} {}

void epee::attaqueEpee()
{
    d_pointSolidite--;
}
