#pragma once

#include "player.h"

class CGoalie : public CPlayer
{
public:
    CGoalie(std::string name, CTeam* team);

    bool TryParry();
};