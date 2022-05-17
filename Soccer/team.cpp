#include "team.h"

#include <iostream>
#include <utility>

#include "field.h"
#include "random.hpp"

class CGoalie;

CTeam::CTeam(std::string name, CField* field) : Name(std::move(name)), Field(field)
{
}

std::string CTeam::GetName()
{
    return Name;
}

std::vector<CPlayer*> CTeam::GetPlayers() const
{
    return Players;
}

void CTeam::AddPlayer(CPlayer* player)
{
    /* Maximal 10 Spieler in einem Team */
    if (Players.size() == 10)
        return;

    Players.emplace_back(player);
}

CGoalie* CTeam::GetGoalie() const
{
    return Goalie;
}

void CTeam::SetGoalie(CGoalie* player)
{
    Goalie = player;
}

CField* CTeam::GetField() const
{
    return Field;
}

int CTeam::GetGoals() const
{
    return Goals;
}

void CTeam::AddGoal()
{
    Goals++;
    std::cout << "Punktestand: " << Field->GetTeams()[0]->GetName() << " " << Field->GetTeams()[0]->GetGoals() << ":" << Field->GetTeams()[1]->GetGoals() << " " << Field->GetTeams()[1]->GetName() << std::endl;
}

CPlayer* CTeam::GetRandomPlayerOnField() const
{
    const int player = Random::GetRandomNumber(0, 9);
    return Players[player];
}
