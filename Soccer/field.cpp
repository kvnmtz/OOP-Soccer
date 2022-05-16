#include "field.h"

#include <iostream>

#include "team.h"

CField::CField(const int width, const int height) : Width(width), Height(height)
{
    // TODO: Choose random player
    PlayerWithBall = nullptr;
}

int CField::GetWidth() const
{
    return Width;
}

int CField::GetHeight() const
{
    return Height;
}

std::vector<CTeam*>& CField::GetTeams()
{
    return Teams;
}

void CField::AddTeam(CTeam* team)
{
    Teams.emplace_back(team);
}

CTeam* CField::GetEnemyTeam(CTeam* team) const
{
    if (Teams[0] == team)
    {
        return Teams[1];
    }

    return Teams[0];
}

CPlayer* CField::GetPlayerWithBall() const
{
    return PlayerWithBall;
}

void CField::SetPlayerWithBall(CPlayer* player)
{
    PlayerWithBall = player;
}