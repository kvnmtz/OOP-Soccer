#pragma once

#include <string>
#include <vector>

class CField;
class CPlayer;

class CTeam
{
	std::string Name;
	std::vector<CPlayer*> Players;
	CPlayer* Goalie;
	CField* Field;

public:
	CTeam(std::string name, CField* field);

	std::string GetName();

	std::vector<CPlayer*> GetPlayers() const;

	void AddPlayer(CPlayer* player);

	CPlayer* GetGoalie() const;

	void SetGoalie(CPlayer* player);

	CField* GetField() const;
};