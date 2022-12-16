#include <amxmodx>
#include "MGifts/Natives"

public plugin_natives() {
    Natives_Init("MGifts");

    Natives_Reg("Init");
}

@_Init() {
    PluginInit();
}
