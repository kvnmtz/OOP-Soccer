#include "team.h"

#include <utility>

CTeam::CTeam(std::string name, CField* field) : Name(std::move(name)), Field(field)
{
}

std::string CTeam::GetName()
{
	return Name;
}

std::array<CPlayer*, 10> CTeam::GetPlayers() const
{
	return Players;
}

void CTeam::AddPlayer(CPlayer* player)
{
	Players.assign(player);
}

CPlayer* CTeam::GetGoalie() const
{
	return Goalie;
}

void CTeam::SetGoalie(CPlayer* player)
{
	Goalie = player;
}

CField* CTeam::GetField() const
{
	return Field;
}
