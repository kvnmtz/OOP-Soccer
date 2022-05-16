#pragma once

#include <vector>

/*-----------------------------------------------------------------------------
    Spielfeld
-----------------------------------------------------------------------------*/

class CTeam;
class CPlayer;

class CField
{
    int Width, Height;
    std::vector<CTeam*> Teams;
    CPlayer* PlayerWithBall = nullptr;

public:
    CField(int width, int height);

    int GetWidth() const;

    int GetHeight() const;

    std::vector<CTeam*>& GetTeams();

    void AddTeam(CTeam* team);

    /**
     * \param team Das verbŁndete Team
     * \return Das Gegnerteam
     */
    CTeam* GetEnemyTeam(CTeam* team) const;

    CPlayer* GetPlayerWithBall() const;

    void SetPlayerWithBall(CPlayer* player);

    CPlayer* GetRandomPlayerOnField() const;

    void PlayGame();
};