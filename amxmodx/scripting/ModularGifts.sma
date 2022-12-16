#include <amxmodx>
#include <ModularGifts>
#include "MGifts/Utils"
#include "MGifts/Forwards"
#include "MGifts/DebugMode"

#pragma semicolon 1
#pragma compress 1

public stock const PluginName[] = "Modular Gifts";
public stock const PluginVersion[] = _MGIFTS_VERSION;
public stock const PluginAuthor[] = "ArKaNeMaN";
public stock const PluginURL[] = "t.me/arkanaplugins";

public plugin_precache() {
    PluginInit();
}

PluginInit() {
    CallOnce();

    RegisterPluginByVars();
    register_library(MGIFTS_LIBRARY);
    CreateConstCvar(MGIFTS_VERSION_CVAR, PluginVersion);
    Forwards_Init("MGifts");

    Dbg_PrintServer("%s run in debug mode.", PluginName);

    Forwards_RegAndCall("Init", ET_IGNORE);



    Forwards_RegAndCall("Inited", ET_IGNORE);
}

#include "MGifts/Core/Natives"
