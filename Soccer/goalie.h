#pragma once

#include "player.h"

/*-----------------------------------------------------------------------------
    Torwart
-----------------------------------------------------------------------------*/

class CGoalie : public CPlayer // CGoalie stammt von CPlayer ab und erbt alle Eigenschaften
{
public:
    CGoalie(std::string name, CTeam* team);

    /**
     * \brief Versucht einen Torschuss abzuwehren (75%ige Chance)
     * \return True, wenn der Versuch erfolgreich war, sonst false
     */
    bool TryParry();
};