
#pragma once

class CPlayer
{
    bool Shoot();

    CPlayer& Pass(CPlayer& _rTarget);   // Referenz

    CTeam* m_pTeam;                     // part-of
    int    m_Number;
};