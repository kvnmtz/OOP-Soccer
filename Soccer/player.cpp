#include "player.h"

#include "field.h"
#include "random.hpp"
#include "team.h"

CPlayer::CPlayer(std::string name, CTeam* team) : Name(std::move(name)), Team(team)
{
    Position = { Random::GetRandomNumber(0, GetField()->GetWidth()), Random::GetRandomNumber(0, GetField()->GetHeight()) };
}

void CPlayer::Pass(const CPlayer& target)
{
    if (Random::Success(30))
    {
        /* Gegnerspieler hat den Ball abgefangen */
        const auto randomEnemy = target.GetEnemyTeam()->GetPlayers()[Random::GetRandomNumber(0, 9)];
        GetField()->SetPlayerWithBall(randomEnemy);
    }
    else
    {
        /* Pass erfolgreich */
        GetField()->SetPlayerWithBall(GetNearestAlly());
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