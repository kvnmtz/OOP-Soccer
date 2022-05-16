#pragma once

#include "player.h"

/*-----------------------------------------------------------------------------
    Torwart
-----------------------------------------------------------------------------*/

class CGoalie : public CPlayer
{
public:
    CGoalie(std::string name, CTeam* team);

    bool TryParry();
};