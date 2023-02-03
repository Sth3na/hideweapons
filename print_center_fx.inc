#define client_print client_print_center

public client_print_center(pPlayer, iMsgType, const szMessage[], any:...) 
{
    new pPlayers[MAX_PLAYERS], iPlCount, msg[191];

    if(pPlayer) 
    {
        iPlCount = 1;
        pPlayers[0] = pPlayer;
    }
    else
        get_players_ex(pPlayers, iPlCount, GetPlayers_ExcludeBots|GetPlayers_ExcludeHLTV);
    

    for(new i; i < iPlCount; i++) 
    {
        pPlayer = pPlayers[i];
        SetGlobalTransTarget(pPlayer);
        vformat(msg, charsmax(msg), szMessage, 4);

        message_begin(MSG_ONE_UNRELIABLE, get_user_msgid("TextMsg"), .player = pPlayer);
        write_byte(iMsgType);
        write_string(msg);
        message_end();
    }
} 
