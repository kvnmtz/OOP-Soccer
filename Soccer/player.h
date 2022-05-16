#pragma once
#include <string>

/*-----------------------------------------------------------------------------
    Spieler
-----------------------------------------------------------------------------*/

class CField;
class CTeam;

struct SPosition
{
    int X, Y;
};

class CPlayer
{
    std::string Name;
    SPosition Position{};
    CTeam* Team;

public:
    CPlayer(std::string name, CTeam* team);

    /**
     * \brief Passt den Ball zu einem Mitspieler im selben Team, Pass wird mit Wahrscheinlichkeit von 30% von einem zufälligem Gegner abgefangen
     * \param target Spieler, der den Ball erhalten soll
     */
    void Pass(const CPlayer& target);

    std::string GetName();

    SPosition GetPosition() const;

    CTeam* GetTeam() const;

    CTeam* GetEnemyTeam() const;

    CField* GetField() const;

    CPlayer* GetNearestAlly();

    float GetDistanceToPlayer(const CPlayer* player) const;
    
    bool TryShootGoal();
};