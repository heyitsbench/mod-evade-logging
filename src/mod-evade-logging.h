#include "Chat.h"
#include "Config.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "TaskScheduler.h"

std::string GetUnitTypeText(TypeID typeID)
{
    switch (typeID)
    {
    case TYPEID_OBJECT:
        return "TYPEID_OBJECT";
    case TYPEID_ITEM:
        return "TYPEID_ITEM";
    case TYPEID_CONTAINER:
        return "TYPEID_CONTAINER";
    case TYPEID_UNIT:
        return "TYPEID_UNIT";
    case TYPEID_PLAYER:
        return "TYPEID_PLAYER";
    case TYPEID_GAMEOBJECT:
        return "TYPEID_GAMEOBJECT";
    case TYPEID_DYNAMICOBJECT:
        return "TYPEID_DYNAMICOBJECT";
    case TYPEID_CORPSE:
        return "TYPEID_CORPSE";
    default:
        return "TYPEID_UNKNOWN";
    }
}

std::string GetEvadeReasonText(uint8 evadeReason)
{
    switch (evadeReason)
    {
    case 0:
        return "EVADE_REASON_NO_HOSTILES";
    case 1:
        return "EVADE_REASON_BOUNDARY";
    case 2:
        return "EVADE_REASON_SEQUENCE_BREAK";
    case 3:
        return "EVADE_REASON_NO_PATH";
    case 4:
        return "EVADE_REASON_OTHER";
    default:
        return "EVADE_REASON_UNKNOWN";
    }
}

void Add_evade_logging();

void Addmod_evade_loggingScripts()
{
    Add_evade_logging();
}
