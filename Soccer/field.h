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
	CPlayer* PlayerWithBall;

public:
	CField(int width, int height);

	int GetWidth() const;

	int GetHeight() const;

	std::vector<CTeam*>& GetTeams();

	void AddTeam(CTeam* team);

	/**
	 * \param team Das verbündete Team
	 * \return Das Gegnerteam
	 */
	CTeam* GetEnemyTeam(CTeam* team) const;

	CPlayer* GetPlayerWithBall() const;

	void SetPlayerWithBall(CPlayer* player);
};