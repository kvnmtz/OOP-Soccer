#include <iostream>

#include "field.h"
#include "player.h"
#include "random.hpp"
#include "team.h"

int main()
{
    Random::Initialize();

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
    teams[0]->SetGoalie(new CPlayer("Neuer", teams[0]));

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
    teams[1]->SetGoalie(new CPlayer("Kobel", teams[1]));

    const auto test = teams[0]->GetPlayers()[5];
    std::cout << test->GetName() << std::endl;
    std::cout << test->GetPosition().X << ", " << test->GetPosition().Y << std::endl;
    std::cout << test->GetNearestAlly()->GetName() << std::endl;
    std::cout << test->GetNearestAlly()->GetPosition().X << ", " << test->GetNearestAlly()->GetPosition().Y << std::endl;

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