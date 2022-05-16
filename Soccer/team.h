#pragma once

#include <array>
#include <string>

class CField;
class CPlayer;

class CTeam
{
	std::string Name;
	std::array<CPlayer*, 10> Players;
	CPlayer* Goalie;
	CField* Field;

public:
	CTeam(std::string name, CField* field);

	std::string GetName();

	std::array<CPlayer*, 10> GetPlayers() const;

	void AddPlayer(CPlayer* player);

	CPlayer* GetGoalie() const;

	void SetGoalie(CPlayer* player);

	CField* GetField() const;
};