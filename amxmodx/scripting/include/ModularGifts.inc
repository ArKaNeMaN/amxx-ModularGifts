#if defined __ModularGifts_included
    #endinput
#endif
#define __ModularGifts_included

#define _MGIFTS_VERSION "3.0.0-wip"
stock const MGIFTS_VERSION[] = _MGIFTS_VERSION;
stock const MGIFTS_VERSION_CVAR[] = "MGifts_Version";
stock const MGIFTS_LIBRARY[] = "ModularGifts";

forward MGifts_OnInit();
forward MGifts_OnInited();

native MGifts_Init();
