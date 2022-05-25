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
    const auto fcb = new CTeam("FC Bayern München", field);
    const auto bvb = new CTeam("Borussia Dortmund", field);
    field->AddTeam(fcb);
    field->AddTeam(bvb);

    fcb->AddPlayer(new CPlayer("Lewandowski", fcb));
    fcb->AddPlayer(new CPlayer("Müller", fcb));
    fcb->AddPlayer(new CPlayer("Gnabry", fcb));
    fcb->AddPlayer(new CPlayer("Kimmich", fcb));
    fcb->AddPlayer(new CPlayer("Davies", fcb));
    fcb->AddPlayer(new CPlayer("Coman", fcb));
    fcb->AddPlayer(new CPlayer("Musiala", fcb));
    fcb->AddPlayer(new CPlayer("Goretzka", fcb));
    fcb->AddPlayer(new CPlayer("Tolisso", fcb));
    fcb->AddPlayer(new CPlayer("Sabitzer", fcb));
    fcb->SetGoalie(new CGoalie("Neuer", fcb));
    
    bvb->AddPlayer(new CPlayer("Haaland", bvb));
    bvb->AddPlayer(new CPlayer("Reus", bvb));
    bvb->AddPlayer(new CPlayer("Adeyemi", bvb));
    bvb->AddPlayer(new CPlayer("Bellingham", bvb));
    bvb->AddPlayer(new CPlayer("Reyna", bvb));
    bvb->AddPlayer(new CPlayer("Moukoko", bvb));
    bvb->AddPlayer(new CPlayer("Brandt", bvb));
    bvb->AddPlayer(new CPlayer("Malen", bvb));
    bvb->AddPlayer(new CPlayer("Hummels", bvb));
    bvb->AddPlayer(new CPlayer("Schmelzer", bvb));
    bvb->SetGoalie(new CGoalie("Kobel", bvb));

    /* Starte die Berechnungen für das Spiel */
    field->PlayGame();

    /* Cleanup */
    const auto& teams = field->GetTeams();
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