#if defined __Cwapi_utils_included
    #endinput
#endif
#define __Cwapi_utils_included

#include <amxmodx>
#include <reapi>
#include <json>

stock const __INT_TEMPLATE_STR[] = "%d";

#define CompositeMacros(%1) \
    do { %1 } while(is_linux_server() == 0xDEADBEEF)

#define IntToStr(%1) \
    fmt(__INT_TEMPLATE_STR, %1)

#define CallOnce() CompositeMacros( \
    static bool:__CallOnce_bCalled; \
    if (__CallOnce_bCalled) return; \
    __CallOnce_bCalled = true; \
)

// https://github.com/Nord1cWarr1or/Universal-AFK-Manager/blob/6272afbb8c27f8b7ad770e3036b5960042001e6b/scripting/UAFKManager.sma#L298-L321
stock GetAmxxVersionNum() {
    static iRes;
    if (iRes) {
        return iRes;
    }

    new sAmxxVer[16];
    get_amxx_verstring(sAmxxVer, charsmax(sAmxxVer));

    if (strfind(sAmxxVer, "1.10.0") != -1) {
        iRes = 1100;
    } else if (strfind(sAmxxVer, "1.9.0") != -1) {
        iRes = 190;
    } else if (strfind(sAmxxVer, "1.8.3") != -1) {
        iRes = 183;
    } else if (strfind(sAmxxVer, "1.8.2") != -1) {
        iRes = 182;
    } else {
        iRes = 1;
    }

    return iRes;
}

#define RegisterPluginByVars() CompositeMacros( \
    if (GetAmxxVersionNum() < 1100) { \
        register_plugin(PluginName, PluginVersion, PluginAuthor); \
    } \
)

stock CreateConstCvar(const sCvarName[], const sCvarValue[]) {
    set_pcvar_string(create_cvar(sCvarName, sCvarValue), sCvarValue);
}

stock bool:mult_member_f(const EntId, const any:iMember, const Float:fMult) {
    return bool:set_member(EntId, iMember, (Float:get_member(EntId, iMember)) * fMult);
}

stock bool:mult_member(const EntId, const any:iMember, const iMult) {
    return bool:set_member(EntId, iMember, get_member(EntId, iMember) * iMult);
}

stock bool:set_member_if_specified(const EntId, const any:iMember, const any:iValue, const any:iNotSpecVal) {
    if (iValue != iNotSpecVal) {
        set_member(EntId, iMember, iValue);
    }
}

stock bool:rg_set_iteminfo_if_specified(const ItemId, const ItemInfo:iItemInfo, const any:iValue, const any:iNotSpecVal) {
    if (iValue != iNotSpecVal) {
        rg_set_iteminfo(ItemId, iItemInfo, iValue);
    }
}

// Не использовать для вепонбоксов! (thx fl0werD)
stock RemoveEntity(const EntId) {
    set_entvar(EntId, var_flags, FL_KILLME);
    set_entvar(EntId, var_nextthink, -1.0);
}

#define ThrowError(%1) CompositeMacros( \
    log_error(0, %1); \
    log_amx(%1); \
)
