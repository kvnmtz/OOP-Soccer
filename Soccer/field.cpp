#include "field.h"

#include <iostream>

#include "player.h"
#include "random.hpp"
#include "team.h"

CField::CField(const int width, const int height) : Width(width), Height(height)
{
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

CPlayer* CField::GetRandomPlayerOnField() const
{
    const int team = Random::GetRandomNumber(0, 1);
    const int player = Random::GetRandomNumber(0, 9);
    return Teams[team]->GetPlayers()[player];
}

void CField::PlayGame()
{
    SetPlayerWithBall(GetRandomPlayerOnField());

    /* Solange kein Team 10 Tore hat ... */
    while (Teams[0]->GetGoals() < 10 && Teams[1]->GetGoals() < 10)
    {
        GetPlayerWithBall()->Play();
    }

    const auto winner = Teams[0]->GetGoals() == 10 ? Teams[0] : Teams[1];
    std::cout << winner->GetName() << " hat das Spiel gewonnen!" << std::endl;
}
