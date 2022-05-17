#pragma once

#include <vector>

/*-----------------------------------------------------------------------------
    Forward-declarations (sh. player.h f�r Erkl�rung)
-----------------------------------------------------------------------------*/

class CTeam;
class CPlayer;

/*-----------------------------------------------------------------------------
    Spielfeld
-----------------------------------------------------------------------------*/

class CField
{
    /* L�nge und Breite des Felds */
    int Length, Width;
    /* Liste der Teams auf dem Feld */
    std::vector<CTeam*> Teams;
    /* Der Spieler, der aktuell Ballbesitz hat */
    CPlayer* PlayerWithBall = nullptr;

public:
    CField(int width, int height);

    int GetWidth() const;

    int GetHeight() const;

    std::vector<CTeam*>& GetTeams();

    /**
     * \brief F�gt das angegebene Team auf das Spielfeld hinzu
     */
    void AddTeam(CTeam* team);

    /**
     * \param team Das verb�ndete Team
     * \return Das Gegnerteam
     */
    CTeam* GetEnemyTeam(CTeam* team) const;

    /**
     * \return Den Spieler, der gerade Ballbesitz hat
     */
    CPlayer* GetPlayerWithBall() const;

    /**
     * \brief Gibt dem angegebenen Spieler Ballbesitz
     */
    void SetPlayerWithBall(CPlayer* player);

    /**
     * \return Einen zuf�lligen Spieler eines zuf�lligem Teams auf dem Feld (kein Torwart)
     */
    CPlayer* GetRandomPlayerOnField() const;

    /**
     * \brief Beginnt die Berechnung f�r das Spiel (Anpfiff)
     */
    void PlayGame();
};