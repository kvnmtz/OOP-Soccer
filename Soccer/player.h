#pragma once
#include <string>

class CField;
class CTeam;

/*-----------------------------------------------------------------------------
    Position
-----------------------------------------------------------------------------*/

struct SPosition
{
    int X, Y;
};

/*-----------------------------------------------------------------------------
    Spieler
-----------------------------------------------------------------------------*/

class CPlayer
{
    /* Name des Spielers */
    std::string Name;
    /* Position des Spielers */
    SPosition Position = { 0, 0 };
    /* Team des Spielers */
    CTeam* Team;

public:
    CPlayer(std::string name, CTeam* team);

    /**
     * \brief Passt den Ball zu einem Mitspieler im selben Team, Pass wird mit Wahrscheinlichkeit von 30% von einem zufälligem Gegner abgefangen
     * \param target Spieler, der den Ball erhalten soll
     */
    void TryPass(const CPlayer* target);

    std::string GetName();

    SPosition GetPosition() const;

    CTeam* GetTeam() const;

    /**
     * \return Das gegnerische Team dieses Spielers
     */
    CTeam* GetEnemyTeam() const;

    CField* GetField() const;

    /**
     * \return Den Spieler mit der geringsten Entfernung zu diesem Spieler
     */
    CPlayer* GetNearestAlly();

    /**
     * \return Die Entfernung zwischen diesem Spieler und dem angegebenen Spieler
     */
    float GetDistanceToPlayer(const CPlayer* player) const;

    /**
     * \brief Versucht einen Torschuss (20% Chance auf Treffer, dann aber 75% Chance dafür, dass der Torwart den Ball hält)
     */
    void TryShootGoal() const;

    /**
     * \brief Berechnet einen Spielzug
     */
    void Play();
};