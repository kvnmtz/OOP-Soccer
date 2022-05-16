#pragma once

#include <string>
#include <vector>

class CGoalie;
class CField;
class CPlayer;

/*-----------------------------------------------------------------------------
    Tean
-----------------------------------------------------------------------------*/

class CTeam
{
    std::string Name;
    std::vector<CPlayer*> Players;
    CGoalie* Goalie = nullptr;
    CField* Field;
    int Goals = 0;

public:
    CTeam(std::string name, CField* field);

    std::string GetName();

    std::vector<CPlayer*> GetPlayers() const;

    void AddPlayer(CPlayer* player);

    CGoalie* GetGoalie() const;

    void SetGoalie(CGoalie* player);

    CField* GetField() const;

    int GetGoals() const;
    
    void AddGoal();

    CPlayer* GetRandomPlayerOnField() const;
};