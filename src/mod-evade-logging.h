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
        break;
    case TYPEID_ITEM:
        return "TYPEID_ITEM";
        break;
    case TYPEID_CONTAINER:
        return "TYPEID_CONTAINER";
        break;
    case TYPEID_UNIT:
        return "TYPEID_UNIT";
        break;
    case TYPEID_PLAYER:
        return "TYPEID_PLAYER";
        break;
    case TYPEID_GAMEOBJECT:
        return "TYPEID_GAMEOBJECT";
        break;
    case TYPEID_DYNAMICOBJECT:
        return "TYPEID_DYNAMICOBJECT";
        break;
    case TYPEID_CORPSE:
        return "TYPEID_CORPSE";
        break;
    default:
        return "TYPEID_UNKNOWN";
        break;
    }
}

std::string GetEvadeReasonText(uint8 evadeReason)
{
    switch (evadeReason)
    {
    case 0:
        return "EVADE_REASON_NO_HOSTILES";
        break;
    case 1:
        return "EVADE_REASON_BOUNDARY";
        break;
    case 2:
        return "EVADE_REASON_SEQUENCE_BREAK";
        break;
    case 3:
        return "EVADE_REASON_NO_PATH";
        break;
    case 4:
        return "EVADE_REASON_OTHER";
        break;
    default:
        return "EVADE_REASON_UNKNOWN";
        break;
    }
}

void Add_evade_logging();

void Addmod_evade_loggingScripts()
{
    Add_evade_logging();
}
