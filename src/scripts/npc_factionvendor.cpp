/*
* See AUTHORS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "Precompiled.h"

class npc_hordevendor : public CreatureScript
{
public:
    npc_hordevendor() : CreatureScript("npc_hordevendor") {}

    bool GossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetOTeam() != HORDE)
            pPlayer->PlayerTalkClass->SendGossipMenu("You are not horde, you may not buy shite from me!", pCreature->GetObjectGuid());
        else
            pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());

        return true;
    }

    bool GossipSelect(Player* pPlayer, Creature* pCreature, uint32, uint32, std::string)
    {
        if (pPlayer->GetOTeam() == HORDE)
            pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());

        return true;
    }
};

class npc_alliancevendor : public CreatureScript
{
public:
    npc_alliancevendor() : CreatureScript("npc_alliancevendor") {}

    bool GossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetOTeam() != ALLIANCE)
            pPlayer->PlayerTalkClass->SendGossipMenu("You are not alliance, you may not buy shite from me!", pCreature->GetObjectGuid());
        else
            pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());

        return true;
    }

    bool GossipSelect(Player* pPlayer, Creature* pCreature, uint32, uint32, std::string)
    {
        if (pPlayer->GetOTeam() == HORDE)
            pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());

        return true;
    }
};

void AddSC_factionvendors()
{
    new npc_hordevendor;
    new npc_alliancevendor;
}