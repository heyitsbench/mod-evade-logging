#include "mod-evade-logging.h"

class evadeLogs : public UnitScript {

public:
    evadeLogs() : UnitScript("evadeLogs") {}

    void OnUnitEnterEvadeMode(Unit* unit, uint8 evadeReason) override
    {
        if (!unit)
        {
            LOG_ERROR("module", "mod-evade-logging, hit OnUnitEnterEvadeMode with no unit!");
            return;
        }

        uint32 map = unit->GetMap()->GetId();
        std::string evadeReasonText = GetEvadeReasonText(evadeReason);
        float unitX = unit->GetPositionX();
        float unitY = unit->GetPositionY();
        float unitZ = unit->GetPositionZ();
        float unitOrientation = unit->GetOrientation();
        std::string unitType = GetUnitTypeText(unit->GetTypeId());
        ObjectGuid::LowType unitGUID;
        if (unit->IsCreature())
            unitGUID = unit->ToCreature()->GetSpawnId();
        else
            unitGUID = 0;

        std::string unitInfo = std::to_string(unitGUID) + " " + std::to_string(unit->GetGUID().GetCounter()) + " " + unit->GetName();
        CharacterDatabase.EscapeString(unitInfo);

        Unit* attacker = unit->GetVictim();
        if (!attacker)
        {
            CharacterDatabase.Execute("INSERT INTO evade_logs (Map, VictimX, VictimY, VictimZ, VictimO, VictimType, VictimInfo, AttackerX, AttackerY, AttackerZ, AttackerO, AttackerType, AttackerInfo, EvadeReason) VALUES ({}, {}, {}, {}, {}, '{}', '{}', NULL, NULL, NULL, NULL, NULL, NULL, '{}')", map, unitX, unitY, unitZ, unitOrientation, unitType, unitInfo, evadeReason);
            return;
        }

        float attackerX = attacker->GetPositionX();
        float attackerY = attacker->GetPositionY();
        float attackerZ = attacker->GetPositionZ();
        float attackerOrientation = attacker->GetOrientation();
        std::string attackerType = GetUnitTypeText(attacker->GetTypeId());
        ObjectGuid::LowType attackerGUID;
        if (unit->IsCreature())
            attackerGUID = attacker->ToCreature()->GetSpawnId();
        else
            attackerGUID = 0;

        std::string attackerInfo = std::to_string(attackerGUID) + " " + std::to_string(attacker->GetGUID().GetCounter()) + " " + attacker->GetName();
        CharacterDatabase.EscapeString(attackerInfo);

        CharacterDatabase.Execute("INSERT INTO evade_logs (Map, VictimX, VictimY, VictimZ, VictimO, VictimType, VictimInfo, AttackerX, AttackerY, AttackerZ, AttackerO, AttackerType, AttackerInfo, EvadeReason) VALUES ({}, {}, {}, {}, {}, '{}', '{}', {}, {}, {}, {}, '{}', '{}', '{}')", map, unitX, unitY, unitZ, unitOrientation, unitType, unitInfo, attackerX, attackerY, attackerZ, attackerOrientation, attackerType, attackerInfo, evadeReason);
        return;
    }
};

void Add_evade_logging()
{
    new evadeLogs();
}
