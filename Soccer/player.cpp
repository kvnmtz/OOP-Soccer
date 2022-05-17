#include "player.h"

#include <iostream>

#include "field.h"
#include "goalie.h"
#include "random.hpp"
#include "team.h"

CPlayer::CPlayer(std::string name, CTeam* team) : Name(std::move(name)), Team(team)
{
    /* Generiere eine zufällige Position auf dem Feld */
    Position = { Random::GetRandomNumber(0, GetField()->GetWidth()), Random::GetRandomNumber(0, GetField()->GetHeight()) };
}

void CPlayer::TryPass(const CPlayer* target)
{
    std::cout << Name << " passt zu " << target->Name << "..." << std::endl;
    if (Random::Success(70))
    {
        /* Pass erfolgreich */
        GetField()->SetPlayerWithBall(GetNearestAlly());
    }
    else
    {
        /* Gegnerspieler hat den Ball abgefangen */
        const auto randomEnemy = target->GetEnemyTeam()->GetRandomPlayerOnField();
        GetField()->SetPlayerWithBall(randomEnemy);
        std::cout << randomEnemy->Name << " hat den Ball abgefangen!" << std::endl;
    }
}

std::string CPlayer::GetName()
{
    return Name;
}

SPosition CPlayer::GetPosition() const
{
    return Position;
}

CTeam* CPlayer::GetTeam() const
{
    return Team;
}

CTeam* CPlayer::GetEnemyTeam() const
{
    return GetField()->GetEnemyTeam(Team);
}

CField* CPlayer::GetField() const
{
    return Team->GetField();
}

CPlayer* CPlayer::GetNearestAlly()
{
    CPlayer* currentNearest = nullptr;
    float currentNearestDistance = FLT_MAX;

    for (const auto player : Team->GetPlayers())
    {
        /* Den eigenen Spieler skippen */
        if (player == this)
            continue;

        const float distance = GetDistanceToPlayer(player);
        if (distance < currentNearestDistance)
        {
            currentNearest = player;
            currentNearestDistance = distance;
        }
    }

    return currentNearest;
}

float CPlayer::GetDistanceToPlayer(const CPlayer* player) const
{
    const auto diffX = Position.X - player->Position.X;
    const auto diffY = Position.Y - player->Position.Y;
    return sqrtf(static_cast<float>(diffX * diffX + diffY * diffY));
}

void CPlayer::TryShootGoal() const
{
    if (Random::Success(20))
    {
        /* Torschuss ging nicht ins Aus */
        if (GetEnemyTeam()->GetGoalie()->TryParry())
        {
            /* Torschuss abgewehrt */
            std::cout << GetEnemyTeam()->GetGoalie()->GetName() << " hat den Torschuss von " << Name << " abgewehrt!" << std::endl;
        }
        else
        {
            /* Torschuss erfolgreich */
            std::cout << "Der Torschuss von " << Name << " war erfolgreich! Tooooor!" << std::endl;
            Team->AddGoal();
        }
    }
    else
    {
        /* Torschuss ging ins Aus */
        std::cout << "Der Torschuss von " << Name << " ging ins Aus!" << std::endl;
    }

    /* In jedem Fall erhält ein zufälliger Gegner den Ball */
    GetField()->SetPlayerWithBall(GetEnemyTeam()->GetRandomPlayerOnField());
}

void CPlayer::Play()
{
    if (Random::Success(90))
    {
        TryPass(GetNearestAlly());
    }
    else
    {
        TryShootGoal();
    }
}
