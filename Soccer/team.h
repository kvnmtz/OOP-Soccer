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
    /* Name des Teams */
    std::string Name;
    /* Liste der Spieler */
    std::vector<CPlayer*> Players;
    /* Torwart */
    CGoalie* Goalie = nullptr;
    /* Spielfeld */
    CField* Field;
    /* Erzielte Tore des Teams */
    int Goals = 0;

public:
    CTeam(std::string name, CField* field);

    std::string GetName();

    std::vector<CPlayer*> GetPlayers() const;

    /**
     * \brief Fügt dem Team den angegebenen Spieler hinzu
     */
    void AddPlayer(CPlayer* player);

    CGoalie* GetGoalie() const;

    /**
     * \brief Legt den angegebenen Spieler als Torwart für dieses Team fest
     */
    void SetGoalie(CGoalie* player);

    CField* GetField() const;

    /**
     * \return Die aktuelle anzahl an erzielten Toren
     */
    int GetGoals() const;

    /**
     * \brief Fügt ein Tor zum Punktestand des Teams hinzu
     */
    void AddGoal();

    /**
     * \return Einen zufälligen Spieler dieses Teams auf dem Feld (kein Torwart)
     */
    CPlayer* GetRandomPlayerOnField() const;
};