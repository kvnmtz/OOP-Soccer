#include "goalie.h"

#include "random.hpp"
#include "team.h"

CGoalie::CGoalie(std::string name, CTeam* team) : CPlayer(std::move(name), team)
{
}

bool CGoalie::TryParry()
{
    return Random::Success(75);
}