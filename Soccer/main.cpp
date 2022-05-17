#include <iostream>

#include "field.h"
#include "goalie.h"
#include "player.h"
#include "random.hpp"
#include "team.h"

int main()
{
    /* Macht es möglich, Umlaute korrekt in der Konsole auszugeben */
    std::locale::global(std::locale("German_germany.UTF-8"));
    
    Random::Initialize();

    /* Feld, Teams und Spieler initialisieren */
    const auto field = new CField(130, 100);
    field->AddTeam(new CTeam("FC Bayern München", field));
    field->AddTeam(new CTeam("Borussia Dortmund", field));

    const auto teams = field->GetTeams();

    teams[0]->AddPlayer(new CPlayer("Lewandowski", teams[0]));
    teams[0]->AddPlayer(new CPlayer("Müller", teams[0]));
    teams[0]->AddPlayer(new CPlayer("Gnabry", teams[0]));
    teams[0]->AddPlayer(new CPlayer("Kimmich", teams[0]));
    teams[0]->AddPlayer(new CPlayer("Davies", teams[0]));
    teams[0]->AddPlayer(new CPlayer("Coman", teams[0]));
    teams[0]->AddPlayer(new CPlayer("Musiala", teams[0]));
    teams[0]->AddPlayer(new CPlayer("Goretzka", teams[0]));
    teams[0]->AddPlayer(new CPlayer("Tolisso", teams[0]));
    teams[0]->AddPlayer(new CPlayer("Sabitzer", teams[0]));
    teams[0]->SetGoalie(new CGoalie("Neuer", teams[0]));
    
    teams[1]->AddPlayer(new CPlayer("Haaland", teams[1]));
    teams[1]->AddPlayer(new CPlayer("Reus", teams[1]));
    teams[1]->AddPlayer(new CPlayer("Adeyemi", teams[1]));
    teams[1]->AddPlayer(new CPlayer("Bellingham", teams[1]));
    teams[1]->AddPlayer(new CPlayer("Reyna", teams[1]));
    teams[1]->AddPlayer(new CPlayer("Moukoko", teams[1]));
    teams[1]->AddPlayer(new CPlayer("Brandt", teams[1]));
    teams[1]->AddPlayer(new CPlayer("Malen", teams[1]));
    teams[1]->AddPlayer(new CPlayer("Hummels", teams[1]));
    teams[1]->AddPlayer(new CPlayer("Schmelzer", teams[1]));
    teams[1]->SetGoalie(new CGoalie("Kobel", teams[1]));

    /* Starte die Berechnungen für das Spiel */
    field->PlayGame();

    /* Cleanup */
    for (const auto team : teams)
    {
        for (const auto player : team->GetPlayers())
        {
            delete player;
        }
        delete team;
    }
    delete field;
}