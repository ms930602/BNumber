mystartloadfile = "lua库已经存在"

-- myIsWindowShow("PKWarning");	--是否被PK
-------------------------------------------------------------

myHuoyuehaoli_OKbtn = 1
function __Huoyuehaoli_OK()

    if myHuoyuehaoli_OKbtn == 1 then
        myluaregstertogame()
    end
end

if Huoyuehaoli_OK_ == nil then

    Huoyuehaoli_OK_ = Huoyuehaoli_OK
    function Huoyuehaoli_OK(event)
        Huoyuehaoli_OK_(event);
        __Huoyuehaoli_OK(event);
    end
end

function UNhookHuoyuehaoli_OK()

    myHuoyuehaoli_OKbtn = 0
    -- PushDebugMessage("UNhookHuoyuehaoli_OK")
end

--------------------------------

mystarthook = 1
--------------------------------

myg_Current_ParaGraph = 1
myg_1_SongBing_num = 0
myg_1_FuDuTong_num = 0
myg_1_FeiLei_num = 0
myg_1_DuTong_num = 0
myg_1_YuDu_num = 0
myg_2_HongXiong_num = 0
myg_2_HongXiong_Boss_num = 0
myg_3_GeRong_num = 0
mysancai_str = "宋兵:0,副都统:0,匪类:0,都统:0,余毒:0,红熊:0,红熊王:0,葛荣:0,阶段:1"
function __Sancai_OnEvent(event)
    setmetatable(_G, { __index = Sancai_Env });

    if (event == "UI_COMMAND" and tonumber(arg0) == 2015040711) then
        myg_Current_ParaGraph = tonumber(Get_XParam_INT(1))
        -- PushDebugMessage("刷新" .. tostring(myg_Current_ParaGraph))
        local myListNum = tonumber(Get_XParam_INT(2))
        -- PushDebugMessage("list:" .. tostring(myListNum))
        local myKilledNum = tonumber(Get_XParam_INT(3))
        -- PushDebugMessage("kill:" .. tostring(myKilledNum))
        if myg_Current_ParaGraph == 1 then
            -- 阶段一
            if myListNum == 1 then
                myg_1_SongBing_num = myKilledNum
            elseif myListNum == 2 then
                myg_1_SongBing_num = 30
                myg_1_FuDuTong_num = myKilledNum
            elseif myListNum == 3 then
                myg_1_FuDuTong_num = 1
                myg_1_SongBing_num = 30
                myg_1_FeiLei_num = myKilledNum
            elseif myListNum == 4 then
                myg_1_FeiLei_num = 6
                myg_1_FuDuTong_num = 1
                myg_1_SongBing_num = 30
                myg_1_DuTong_num = myKilledNum
            elseif myListNum == 5 then
                myg_1_FeiLei_num = 6
                myg_1_DuTong_num = 1
                myg_1_FuDuTong_num = 1
                myg_1_SongBing_num = 30
                myg_1_YuDu_num = myKilledNum
                myg_Current_ParaGraph = 2
            end
        elseif myg_Current_ParaGraph == 2 then
            -- 阶段二
            myg_1_FeiLei_num = 6
            myg_1_DuTong_num = 1
            myg_1_FuDuTong_num = 1
            myg_1_SongBing_num = 30
            myg_1_YuDu_num = 1
            if myListNum == 1 then
                myg_2_HongXiong_num = myKilledNum
            elseif myListNum == 2 then
                myg_2_HongXiong_num = 30
                myg_2_HongXiong_Boss_num = myKilledNum
                myg_Current_ParaGraph = 3
            end
        elseif myg_Current_ParaGraph == 3 then
            -- 阶段三
            myg_3_GeRong_num = myKilledNum
            myg_Current_ParaGraph = 1
            myg_1_SongBing_num = 0
            myg_1_FuDuTong_num = 0
            myg_1_FeiLei_num = 0
            myg_1_DuTong_num = 0
            myg_1_YuDu_num = 0
            myg_2_HongXiong_num = 0
            myg_2_HongXiong_Boss_num = 0
            myg_3_GeRong_num = 0
        end

        mysancai_str = string.format("宋兵:%d,副都统:%d,匪类:%d,都统:%d,余毒:%d,红熊:%d,红熊王:%d,葛荣:%d,阶段:%d", myg_1_SongBing_num, myg_1_FuDuTong_num, myg_1_FeiLei_num, myg_1_DuTong_num, myg_1_YuDu_num, myg_2_HongXiong_num, myg_2_HongXiong_Boss_num, myg_3_GeRong_num, myg_Current_ParaGraph);
        -- PushDebugMessage(mysancai_str);
    end
end

function myhookSanCai()

    if Sancai_OnEvent_ == nil then
        Sancai_OnEvent_ = Sancai_OnEvent
        function Sancai_OnEvent(event)
            Sancai_OnEvent_(event);
            __Sancai_OnEvent(event);
        end
    end

end
-- 分割字符串
function Split(szFullString, szSeparator)
    local nFindStartIndex = 1
    local nSplitIndex = 1
    local nSplitArray = { }
    while true do
        local nFindLastIndex = string.find(szFullString, szSeparator, nFindStartIndex)
        if not nFindLastIndex then
            nSplitArray[nSplitIndex] = string.sub(szFullString, nFindStartIndex, string.len(szFullString))
            -- PushDebugMessage(nSplitArray[nSplitIndex].."  "..nSplitIndex)
            break
        end
        nSplitArray[nSplitIndex] = string.sub(szFullString, nFindStartIndex, nFindLastIndex - 1)
        -- PushDebugMessage(nSplitArray[nSplitIndex])
        nFindStartIndex = nFindLastIndex + string.len(szSeparator)
        nSplitIndex = nSplitIndex + 1
    end
    return nSplitArray
end

-- 惩恶令框信息
function mydtms()

    setmetatable(_G, { __index = Quest_Env });
    if this:IsVisible() then
    else
        return "-1|-1|-1";
    end

    local strType, strState, strScriptId, strExtra, strTemp = DataPool:GetNPCEventList_Item(0);
    local str = strTemp;

    str = string.gsub(str, "", "");
    str = string.gsub(str, "", "");
    str = string.gsub(str, "", "");
    str = string.gsub(str, "", "");
    str = string.gsub(str, "}", "");
    str = string.gsub(str, "", "");
    str = string.gsub(str, "", "");
    str = string.gsub(str, "", "");

    local f2 = Split(str, "*");
    local tlen = table.getn(f2);
    -- PushDebugMessage(table.getn(f2))

    ret.x = tonumber(f2[tlen - 2]);
    ret.y = tonumber(f2[tlen - 1]);
    ret.map = f2[tlen];

    return(tostring(ret.x) .. "|" .. tostring(ret.y) .. "|" .. tostring(ret.map));
end


function MissionOutlinetext(Mission)
    -- 任务是否可接，可接返回任务名字
    local j;
    local i;
    CollectMissionOutline()
    for i = 1, 200 do
        -- 现任务类型一共200种
        local DeployNum = GetMissionOutlineNum(i)
        if DeployNum > 0 then
            for j = 1, DeployNum do
                local MissionLevel, MinLevel, MaxLevel, strNpcName, strNpcPos, strScene, strMissionName = GetMissionOutlineInfo(i, j);
                if Mission == strMissionName then
                    -- PushDebugMessage(strMissionName)
                    return 1;
                end
            end
        end
    end
    return 0;
end

-- 取任务信息
function mymis(TD)
    local j;
    local i;
    local s;
    local l;
    local Mission_Variable = 0;
    for j = 1, 200 do
        for i = 1, 20 do
            if (DataPool:GetPlayerMission_InUse(i - 1) == 1) then
                local MissionKind = DataPool:GetPlayerMission_Kind(i - 1);
                if (MissionKind == j) then
                    local strBT = DataPool:GetMissionInfo_Kind(j);
                    local strInfo, strDesc = DataPool:GetPlayerMission_Memo(i - 1);
                    local nMissionLevel = DataPool:GetPlayerMission_Level(i - 1);
                    local Mission_VariableX = DataPool:GetPlayerMission_Variable(i - 1, 0);
                    local nScriptId = DataPool:GetPlayerMission_Display(i - 1, 7);
                    local nRound = DataPool:GetPlayerMission_Display(i - 1, 3);

                    if (nRound >= 0) then
                        Mission_Variable = DataPool:GetPlayerMission_DataRound(nRound);
                    end
                    --  特殊处理

                    if (nScriptId == 610013 or nScriptId == 610014) then
                        strDesc = QuestLog_GuildInteractiveMission(i - 1);
                    end

                    if (DataPool:GetPlayerMission_Display(i - 1, 7) == 500510) then
                        strDesc = QuestLog_GetSCMTarget(i - 1);
                    end

                    -- 生育系统成长任务特写
                    if (DataPool:GetPlayerMission_Display(i - 1, 7) == 890500) then
                        strDesc = QuestLog_GetInfantTarget(i - 1);
                    end

                    if (DataPool:GetPlayerMission_Display(i - 1, 7) == 889265) then
                        strDesc = QuestLog_GetHLXQJTarget(i - 1);
                    end
                    -- Q3打卡活动
                    if (DataPool:GetPlayerMission_Display(i - 1, 7) == 890612) then
                        strDesc = QuestLog_GetDAKATarget(i - 1);
                    end
                    -- 诗歌荟萃之对歌
                    if (DataPool:GetPlayerMission_Display(i - 1, 7) == 051024) then
                        strDesc = QuestLog_GetSGHCDGTarget(i - 1);
                    end
                    -- 诗歌荟萃之对诗
                    if (DataPool:GetPlayerMission_Display(i - 1, 7) == 051025) then
                        strDesc = QuestLog_GetSGHCDSTarget(i - 1);
                    end
                    -- 子女系统属性培养——作画任务
                    if (DataPool:GetPlayerMission_Display(i - 1, 7) == 890512) then
                        strDesc = QuestLog_GetDrawTarget(i - 1);
                    end
                    -- 子女系统属性培养——礼仪任务
                    if (DataPool:GetPlayerMission_Display(i - 1, 7) == 890513) then
                        strDesc = QuestLog_GetMannerNPC(i - 1);
                    end

                    local ss = string.find(strInfo, "{");
                    local ls = string.find(strInfo, "}");
                    if ss ~= nil and ls ~= nil then
                        local strs = string.sub(strInfo, ss + 1, ls - 1);
                        strInfo = GetDictionaryString(strs);
                    end;
                    local nks = 0
                    if strInfo == TD then
                        strDesc2 = strDesc

                        local nks = 0;
                        repeat
                            s = string.find(strDesc, "{");
                            l = string.find(strDesc, "}");
                            if s ~= nil and l ~= nil then
                                str = string.sub(strDesc, s + 1, l - 1);
                                getstr = GetDictionaryString(str);
                                TsT = string.find(str, "INFOAIM");
                                -- PushDebugMessage(tostring(TT));--判断是不是人物取人物坐标
                                if TsT ~= nil then
                                    getstr = getstr .. "<" .. str .. ">"
                                end
                                strDesc = string.sub(strDesc, 0, s - 2) .. getstr .. string.sub(strDesc, l + 1, l + 500);
                            end
                            nks = nks + 1
                            if nks > 10 then
                                s = nil
                            end
                        until (s == nil)
                        if strDesc == "" then
                            return(tostring(strInfo) .. "|" .. tostring(strDesc2) .. "|" .. tostring(Mission_VariableX) .. "|" .. tostring(i - 1) .. "|" .. tostring(nScriptId) .. "|" .. tostring(strBT) .. "|" .. tostring(Mission_Variable));
                        else
                            return(tostring(strInfo) .. "|" .. tostring(strDesc) .. "|" .. tostring(Mission_VariableX) .. "|" .. tostring(i - 1) .. "|" .. tostring(nScriptId) .. "|" .. tostring(strBT) .. "|" .. tostring(Mission_Variable));
                        end
                    end
                end
            end
        end
    end
    return("-1|-1|-1|-1|-1|-1|-1");
end

-- 点击任务对话
function myclickmis(nam)
    -- PushDebugMessage(nam)
    setmetatable(_G, { __index = Quest_Env });
    if this:IsVisible() then
    else
        return 0;
    end
    if string.len(nam) == 1 then
        nam = tonumber(nam);
        local strType, strState, strScriptId, strExtra, strTemp = DataPool:GetNPCEventList_Item(nam - 1);
        QuestFrameOptionClicked(tonumber(-1), tonumber(strScriptId), tonumber(strExtra));
        return 1;
    end

    local nEventListNum = DataPool:GetNPCEventList_Num();
    local nVal = 0;
    for i = 1, nEventListNum do

        local strType, strState, strScriptId, strExtra, strTemp = DataPool:GetNPCEventList_Item(i - 1);

        if strType ~= "text" then

            local pos1 = string.find(strTemp, "#{");
            if pos1 == 1 then
                strTemp = string.sub(strTemp, 3, -2);
                strTemp = GetDictionaryString(strTemp);
            end

            strTemp = string.gsub(strTemp, "%s", "");
            strTemp = string.gsub(strTemp, "%-", "");
            strTemp = string.gsub(strTemp, "%(", "");
            strTemp = string.gsub(strTemp, "%)", "");
            strTemp = string.gsub(strTemp, "#r", "");
            strTemp = string.gsub(strTemp, "#G", "");

            if nam == "炼金任务" then
                if strTemp == nam then
                    QuestFrameOptionClicked(tonumber(-1), tonumber(strScriptId), tonumber(strExtra));
                    return 1;
                end
            else
                if string.find(strTemp, nam) ~= nil then
                    QuestFrameOptionClicked(tonumber(-1), tonumber(strScriptId), tonumber(strExtra));
                    return 1;
                end
            end

        end
    end

    return 0;
end


-- NPC对话文本
function mynpclist(nam)

    nam = tonumber(nam)
    setmetatable(_G, { __index = Quest_Env });
    if this:IsVisible() then
    else
        return "";
    end

    local strType, strState, strScriptId, strExtra, strTemp = DataPool:GetNPCEventList_Item(nam - 1);
    if strType == "text" then

        while string.find(strTemp, " ") == 1 do
            strTemp = string.sub(strTemp, 3, -2);
        end

        local pos1 = string.find(strTemp, "#{");
        if pos1 == 1 then
            strTemp = string.sub(strTemp, 3, -2);
            strTemp = GetDictionaryString(strTemp);
        end

        strTemp = string.gsub(strTemp, "%s", "");
        strTemp = string.gsub(strTemp, "%-", "");
        strTemp = string.gsub(strTemp, "%(", "");
        strTemp = string.gsub(strTemp, "%)", "");
        strTemp = string.gsub(strTemp, "#r", "");
        strTemp = string.gsub(strTemp, "#G", "");
        strTemp = string.gsub(strTemp, "#B", "");

        return strTemp;

    end

    return "";
end


-- NPC对话文本
function mynpclisttest(nam)

    nam = tonumber(nam)
    setmetatable(_G, { __index = Quest_Env });
    if this:IsVisible() then
    else
        return "";
    end

    local strType, strState, strScriptId, strExtra, strTemp = DataPool:GetNPCEventList_Item(nam - 1);
    if strType == "text" then

        return strTemp;
    end

    return "";
end


-- 放弃任务
function mydeltmis(TD)
    -- mymsg("放弃任务："..TD);
    if TD == "惩凶打图" then
        TD = "#{CXDT_090304_01}"
    end
    local i = 0;
    for i = 1, 20 do
        local strInfo, strDesc = DataPool:GetPlayerMission_Memo(i - 1);
        --  dprintf(strInfo);
        if strInfo == TD then
            DataPool:Mission_Abnegate_Popup(i - 1, TD);
        end
    end
end


-- 确定按钮自动点击
function __MessageBox_Self_OnEvent(event)
    if (mystarthook == 0) then
        return;
    end
    setmetatable(_G, { __index = MessageBox_Self_Env });
    local commandIndex = tonumber(arg0)
    if (event == "AFFIRM_SHOW") then
        MessageBox_Self_OK_Clicked();
    end
    if (event == "AUTOMOVE_CONFIRM_UPPKVALUE") then
        MessageBox_Self_OK_Clicked();
    end
    if (event == "AUTOMOVE_CONFIRM_NOPKVALUE") then
        MessageBox_Self_OK_Clicked();
    end
    if (event == "MESSAGE_BOX") then
        MessageBox_Self_OK_Clicked();
    end
    if (event == "AUTOMOVE_CONFIRM_FENGMING") then
        MessageBox_Self_OK_Clicked();
    end
    if (event == "UI_COMMAND" and commandIndex == 24) then
        MessageBox_Self_OK_Clicked();
    end
    if (event == "NET_CLOSE") then
        MessageBox_Self_OK_Clicked();
    end
    if (event == "OPEN_STALL_RENT_FRAME") then
        MessageBox_Self_OK_Clicked();
    end
    if (event == "OPEN_REMOVE_STALL") then
        MessageBox_Self_OK_Clicked();
    end
    if (event == "OPEN_SAVE_STALL_INFO") then
        MessageBox_Self_OK_Clicked();
    end

end

if MessageBox_Self_OnEvent_ == nil then
    MessageBox_Self_OnEvent_ = MessageBox_Self_OnEvent
    function MessageBox_Self_OnEvent(event)
        MessageBox_Self_OnEvent_(event);
        __MessageBox_Self_OnEvent(event);
    end
end

  
function myIsWindowShow(str)

    if (IsWindowShow(str)) then
        -- 地面包裹
        return 1
    end;
    return 0
end

-- 查询门派
function chaxunmymenpai(Family)
    local strName = "无门派";
    if (0 == Family) then
        strName = "少林";
    elseif (1 == Family) then
        strName = "明教";
    elseif (2 == Family) then
        strName = "丐帮";
    elseif (3 == Family) then
        strName = "武当";
    elseif (4 == Family) then
        strName = "峨嵋";
    elseif (5 == Family) then
        strName = "星宿";
    elseif (6 == Family) then
        strName = "天龙";
    elseif (7 == Family) then
        strName = "天山";
    elseif (8 == Family) then
        strName = "逍遥";
    elseif (9 == Family) then
        strName = "无门派";
    elseif (10 == Family) then
        strName = "慕容";
    elseif (11 == Family) then
        strName = "唐门";
    end
    return strName;
end

function myteam(myg_sq_Leve1, myg_sq_Leve2, myg_sq_NAME_guolv, myg_sq_MENPAI_duolv, myg_sq_FZ_group, myg_sq_type)
    local g_iTeamMemberCount_Team = DataPool:GetTeamMemberCount();
    if g_iTeamMemberCount_Team ~= 6 then
        --  PushDebugMessage("myg_sq_type   " .. myg_sq_type)
        myyaoqing(myg_sq_Leve1, myg_sq_Leve2, myg_sq_NAME_guolv, myg_sq_MENPAI_duolv, myg_sq_FZ_group, myg_sq_type);
        myshenqing(myg_sq_Leve1, myg_sq_Leve2, myg_sq_NAME_guolv, myg_sq_MENPAI_duolv, myg_sq_FZ_group, myg_sq_type);
    end
end

-- 同意申请人进队
function myshenqing(myg_sq_Leve1, myg_sq_Leve2, myg_sq_NAME_guolv, myg_sq_MENPAI_duolv, myg_sq_FZ_group, myg_sq_type)
    -- 同意申请人员进队
    -- setmetatable(_G, {__index = TeamFrame_Env});
    local iMemberCount_Apply = DataPool:GetApplyMemberCount();
    if iMemberCount_Apply == 0 then
        return;
    end
    g_iTeamMemberCount_Team = DataPool:GetTeamMemberCount();
    if (g_iTeamMemberCount_Team < 6) then
        if myg_sq_type == 1 then
            -- PushDebugMessage("myshenqing 申请 myg_sq_type   " .. myg_sq_type)
            if AgreeJoinTeam1(myg_sq_Leve1, myg_sq_Leve2, myg_sq_NAME_guolv, myg_sq_MENPAI_duolv) == true then
                return;
            end
        end
        if myg_sq_type == 2 then
            if AgreeJoinTeam2(myg_sq_FZ_group) == true then
                return;
            end
        end
        if myg_sq_type == 3 then
            if AgreeJoinTeam3() == true then
                return;
            end
        end
        Player:SendRejectJoinTeam_Apply(0);
        DataPool:EraseApply(0);
        Team_Close();
    else
        Player:SendAgreeJoinTeam_Apply(0);
        DataPool:EraseApply(0);
        Team_Close();
    end
end

function myyaoqing(myg_sq_Leve1, myg_sq_Leve2, myg_sq_NAME_guolv, myg_sq_MENPAI_duolv, myg_sq_FZ_group, myg_sq_type)
    -- 同意被邀请
    setmetatable(_G, { __index = TeamFrame_Env });
    local g_iTeamCount_Invite = DataPool:GetInviteTeamCount();
    if g_iTeamCount_Invite == 0 then
        return;
    end
    if myg_sq_type == 1 then
        -- PushDebugMessage("myyaoqing 邀请 myg_sq_type   "..myg_sq_type)
        if RejectTeam1(myg_sq_Leve1, myg_sq_Leve2, myg_sq_NAME_guolv, myg_sq_MENPAI_duolv) == true then
            return;
        end
    end
    if myg_sq_type == 2 then
        if RejectTeam2(myg_sq_FZ_group) == true then
            return;
        end
    end
    if myg_sq_type == 3 then
        if RejectTeam3() == true then
            return;
        end
    end
    Player:RejectJoinTeam(0);
    Team_Close();
end

function AgreeJoinTeam1(Leve1, Leve2, NAME_guolv, MENPAI_duolv)
    -- 同意全部进组
    setmetatable(_G, { __index = Team_Frame_Env });
    local szNick, iFamily, iLevel, iCapID, iHead, iArmourID, iCuffID, iFootID, iWeaponID, _, sZoneWorldID = DataPool:GetApplyMemberInfo(0);
    local menpai = chaxunmymenpai(tonumber(iFamily));
    local j = string.find(NAME_guolv, szNick);
    local s = string.find(MENPAI_duolv, menpai);
    if (iLevel >= tonumber(Leve1) and iLevel <= tonumber(Leve2) and j == nil and s == nil) then
        Player:SendAgreeJoinTeam_Apply(0);
        DataPool:EraseApply(0);
        Team_Close();
        return true;
    end
    return false;
end

function AgreeJoinTeam2(FZ_group)
    -- 同意好友进组
    setmetatable(_G, { __index = Team_Frame_Env });
    local szNick, iFamily, iLevel, iCapID, iHead, iArmourID, iCuffID, iFootID, iWeaponID, _, sZoneWorldID = DataPool:GetApplyMemberInfo(0);
    local group, index = DataPool:GetFriendByName(szNick);
    if FZ_group == 5 then
        if (tonumber(group) ~= -1 and tonumber(index) ~= -1 and tonumber(group) <= 4) then
            Player:SendAgreeJoinTeam_Apply(0);
            DataPool:EraseApply(0);
            Team_Close();
            return true;
        end
    else
        if (tonumber(group) ~= -1 and tonumber(index) ~= -1 and tonumber(group) == FZ_group) then
            Player:SendAgreeJoinTeam_Apply(0);
            DataPool:EraseApply(0);
            Team_Close();
            return true;
        end
    end
    return false;

end

function AgreeJoinTeam3()
    -- 同意帮内成员进组
    setmetatable(_G, { __index = Team_Frame_Env });
    local szNick, iFamily, iLevel, iCapID, iHead, iArmourID, iCuffID, iFootID, iWeaponID, _, sZoneWorldID = DataPool:GetApplyMemberInfo(0);
    local totalNum = Guild:GetMembersNum(4);
    local i = 0;
    while i < totalNum do
        local guildIdx = Guild:GetShowMembersIdx(i);
        local szMsg = Guild:GetMembersInfo(guildIdx, "Name");
        if szMsg == szNick then
            Player:SendAgreeJoinTeam_Apply(0);
            DataPool:EraseApply(0);
            Team_Close();
            return true;
        end
        i = i + 1;
    end
    return false;
end

function RejectTeam1(Leve1, Leve2, NAME_guolv, MENPAI_duolv)
    -- 同意全部邀请
    setmetatable(_G, { __index = Team_Frame_Env });
    local szNick, iFamily, iLevel, iCapID, iHead, iArmourID, iCuffID, iFootID, iWeaponID, _, sZoneWorldID = DataPool:GetInviteTeamMemberInfo(0, 0);
    local menpai = chaxunmymenpai(tonumber(iFamily));
    local j = string.find(NAME_guolv, szNick);
    local s = string.find(MENPAI_duolv, menpai);
    if (iLevel >= tonumber(Leve1) and iLevel <= tonumber(Leve2) and j == nil and s == nil) then
        Player:AgreeJoinTeam(0);
        Team_Close();
        return true;
    end
    return false;

end

function RejectTeam2(FZ_group)
    -- 同意好友邀请
    setmetatable(_G, { __index = Team_Frame_Env });
    local szNick, iFamily, iLevel, iCapID, iHead, iArmourID, iCuffID, iFootID, iWeaponID, _, sZoneWorldID = DataPool:GetInviteTeamMemberInfo(0, 0);
    local group, index = DataPool:GetFriendByName(szNick);
    if FZ_group == 5 then
        if (tonumber(group) ~= -1 and tonumber(index) ~= -1 and tonumber(group) <= 4) then
            Player:AgreeJoinTeam(0);
            Team_Close();
            return true;
        end
    else
        if (tonumber(group) ~= -1 and tonumber(index) ~= -1 and tonumber(group) == FZ_group) then
            Player:AgreeJoinTeam(0);
            Team_Close();
            return true;
        end
    end
    return false;

end

function RejectTeam3()
    -- 同意帮内成员邀请
    setmetatable(_G, { __index = Team_Frame_Env });
    local szNick, iFamily, iLevel, iCapID, iHead, iArmourID, iCuffID, iFootID, iWeaponID, _, sZoneWorldID = DataPool:GetInviteTeamMemberInfo(0, 0);
    local totalNum = Guild:GetMembersNum(4);
    local i = 0;
    while i < totalNum do
        local guildIdx = Guild:GetShowMembersIdx(i);
        local szMsg = Guild:GetMembersInfo(guildIdx, "Name");
        if szMsg == szNick then
            Player:AgreeJoinTeam(0);
            Team_Close();
            return true;
        end
        i = i + 1;
    end
    return false;
end

-- 主动跟随队长
function mygensui()
    -- 不是队长就主动跟随
    if Player:IsLeader() == 0 and Player:IsInTeam() == 1 then
        setmetatable(_G, { __index = PartyFrame_Env });
        PartyFrame_SelectAsTarget(1);
        Target:Follow();
    end
end

-- 踢人
function myteamkick(kick_name)
    local n = 0;
    n = DataPool:GetTeamMemberCount();
    for i = 1, n do
        local name, iFamily, iLevel, dead, deadlink, bSex, sZoneWorldID = DataPool:GetTeamMemInfoByIndex(i - 1);
        if tostring(name) == kick_name then
            if i == 1 then
                myleaveteam();
                return;
            end
            Player:KickTeamMember(i - 1);
            return;
        end
    end
end

function myteamfollow()
    -- 队长开启组队跟随队列
    local leader = Player:IsLeader();
    if (leader == 1) then
        Player:TeamFrame_AskTeamFollow();
    end
end    

function mystopteamfollow()
    -- 退出组队跟随队列

    Player:StopFollow();

end 

-- 获取队伍信息
function mygetteaminfo()
    local n = 0;
    local info = { ["1"] = "无", ["2"] = "无", ["3"] = "无", ["4"] = "无", ["5"] = "无", ["6"] = "无" };
    local info_1 = { };
    n = DataPool:GetTeamMemberCount();
    for i = 1, n do
        local name, iFamily, iLevel, dead, deadlink, bSex, sZoneWorldID = DataPool:GetTeamMemInfoByIndex(i - 1);
        info[tostring(i)] = name;
    end
    return info;
end
-- 获取队伍人员数
function mygetteamnum()
    return DataPool:GetTeamMemberCount();
end
-- 离开队伍
function myleaveteam()
    Player:LeaveTeam();
end
-- 创建队伍
function mycreatteam()
    Player:CreateTeamSelf();
end
-- 申请队伍
function myaskteam(name)
    -- Friend:InviteTeam( "り夜254り936", -1);
    Friend:AskTeam(name, -1);
end


function SnsGameDo()
    -- 一键祝福
    SnsDataPool:RequestSnsList(-1, 1);
    OpenWindow("Sns");
    SnsGame:DoPray(0);
    for nChannel = 1, 4 do
        local groupCount = DataPool:GetFriendNumber(tonumber(nChannel));
        --  PushDebugMessage("GetFriendNumber groupCount   " .. groupCount)
        for nIndex = 1, groupCount do
            if (DataPool:GetFriend(nChannel, nIndex - 1, "ONLINE")) then
                local Guid = DataPool:GetFriend(nChannel, nIndex - 1, "ID");
                SnsDataPool:RequestSnsList(Guid, 1);
                OpenWindow("Sns");
                SnsGame:DoPray(1);
                -- PushDebugMessage("GetFriendNumber nIndex   " .. nIndex)
            end
        end
    end

    return 1;
end


function snslingqu()
    SnsDataPool:RequestSnsList(-1, 1);
    OpenWindow("Sns");
    local nExp = SnsGame:GetUIData("EXP");
    local nGuid = SnsGame:GetUIData("GUID");
    local myGuid = Player:GetGUID();
    if myGuid == nGuid then
        local nCountDownTime = SnsGame:GetUIData("COUNTDOWN")
        local nGotPrize = SnsGame:GetUIData("GOT");
        if nExp >= 11 and nExp < 20 then
            return 999;
        end
        if nExp == 20 and nGotPrize == 0 and nCountDownTime <= 0 then
            --- 点击按钮，领取20绑定元宝奖励！
            SnsGame:TakePrize();
            return 1;
        elseif nExp == 20 and nGotPrize == 1 then
            --- 今日聚宝盆中的绑定元宝已经被您领走啦
            return 2;
        elseif nExp == 20 and nGotPrize == 0 and nCountDownTime > 0 then
            -- 需要等待
            return -1 * nCountDownTime;
        end
    end

    return -1;
end

my_g_trans = 0;

-- 手动取消BUFF
function mydelbuf(name)
    if my_g_trans == 1 then
        return -2;
    else
        local buff_num = Player:GetBuffNumber();
        local i;
        local bianshen = 0;
        local yinshen = 0;
        local buffer = "";
        for i = 1, buff_num do
            local szToolTips2 = Player:GetBuffToolTipsByIndex(i - 1);
            -- buffer功能
            pos1 = string.find(szToolTips2, "：");
            if pos1 ~= nil then
                str = string.sub(szToolTips2, 0, pos1 - 1);
            else
                str = szToolTips2;
            end
            if str == name then
                Player:DispelBuffByIndex(i - 1);
                return 1;
            end
        end
    end
end

function myhavebuf(name)
    if my_g_trans == 1 then
        return -2;
    else
        local buff_num = Player:GetBuffNumber();
        local i;
        local bianshen = 0;
        local yinshen = 0;
        local buffer = "";
        for i = 1, buff_num do
            local szToolTips2 = Player:GetBuffToolTipsByIndex(i - 1);
            -- buffer功能
            pos1 = string.find(szToolTips2, "：");
            if pos1 ~= nil then
                str = string.sub(szToolTips2, 0, pos1 - 1);
            else
                str = szToolTips2;
            end
            if str == name then
                return 1;
            end
        end
    end

    return 0;
end

function mygettargetbuff()

    local str = "";
    local nBuffNum = Target:GetBuffNumber();
    for jj = 1, nBuffNum do
        local szIconName, szTipInfo = Target:GetBuffIconNameByIndex(jj - 1);
        if str == "" then
            str = szTipInfo;
        else
            str = str .. "|" .. szTipInfo;
        end
    end
    return str;
end

function __DebugListBox_Update2(arg0)
    if (mystarthook == 0) then
        return;
    end
    if ss_str == nil then
    else
        if string.find(arg0, "屏幕调试") == nil then
            if string.sub(ss_str, 0, 1) == "1" then
                local strInfo;
                local ss = string.find(arg0, "{");
                local ls = string.find(arg0, "}");
                if ss ~= nil and ls ~= nil then
                    local strs = string.sub(arg0, ss + 1, ls - 1);
                    strInfo = GetDictionaryString(strs);
                    ss_str = ss_str .. "|" .. strInfo;
                else
                    ss_str = ss_str .. "|" .. arg0
                end;
            end
        end
    end
end

if DebugListBox_Update_ == nil then
    DebugListBox_Update_ = DebugListBox_Update
    function DebugListBox_Update(arg0)
        DebugListBox_Update_(arg0);
        __DebugListBox_Update2(arg0);
    end
end

-- hook打印函数的输出
function myhooktr1()
    ss_str = "1";
end

-- 关闭打印保存
function myhooktr2()
    local ss = ss_str;
    ss_str = "0";
    return ss;
end


-- 摆摊
function mybaitan()
    PlayerPackage:OpenStallSaleFrame();
end

function petxiuxi()

    local ishavepet = Player:IsHaveCurrentPet();
    -- 没宝宝出战就跳出
    if ishavepet then
    else
        return -1;
    end
    local nPetCount = Pet:GetPet_Count();
    local i;
    for i = 1, nPetCount do
        if (Pet:GetIsFighting(i - 1)) then
            Pet:Go_Relax(i - 1);
        end
    end
    return 0
end


function StallBuy_On(button)

    setmetatable(_G, { __index = StallBuy_Env });
    if button == 1 then
        StallBuy_Item1:DoAction();
    elseif button == 2 then
        StallBuy_Item2:DoAction();
    elseif button == 3 then
        StallBuy_Item3:DoAction();
    elseif button == 4 then
        StallBuy_Item4:DoAction();
    elseif button == 5 then
        StallBuy_Item5:DoAction();
    elseif button == 6 then
        StallBuy_Item6:DoAction();
    elseif button == 7 then
        StallBuy_Item7:DoAction();
    elseif button == 8 then
        StallBuy_Item8:DoAction();
    elseif button == 9 then
        StallBuy_Item9:DoAction();
    elseif button == 10 then
        StallBuy_Item10:DoAction();
    elseif button == 11 then
        StallBuy_Item11:DoAction();
    elseif button == 12 then
        StallBuy_Item12:DoAction();
    elseif button == 13 then
        StallBuy_Item13:DoAction();
    elseif button == 14 then
        StallBuy_Item14:DoAction();
    elseif button == 15 then
        StallBuy_Item15:DoAction();
    elseif button == 16 then
        StallBuy_Item16:DoAction();
    elseif button == 17 then
        StallBuy_Item17:DoAction();
    elseif button == 18 then
        StallBuy_Item18:DoAction();
    elseif button == 19 then
        StallBuy_Item19:DoAction();
    elseif button == 20 then
        StallBuy_Item20:DoAction();
    end

end

function myantihd(answer)
    answer = tonumber(answer);
    setmetatable(_G, { __index = AntiRobot_Env });
    AntiRobot_SelAnswer(answer - 1);
    AntiRobot_OnCommit(1);
end

-- hook答题窗口实现 超时时的随机选择
function __AntiRobot_TimeReach()
    if (mystarthook == 0) then
        return;
    end
    setmetatable(_G, { __index = AntiRobot_Env });
    local s1 = AntiRobot_Answer1_Check:GetProperty("Selected")
    local s2 = AntiRobot_Answer2_Check:GetProperty("Selected")
    local s3 = AntiRobot_Answer3_Check:GetProperty("Selected")
    local s4 = AntiRobot_Answer4_Check:GetProperty("Selected")
    if s1 == "False" and s2 == "False" and s3 == "False" and s4 == "False" then
        math.randomseed(os.time());
        math.random()
        math.random()
        local ns = math.floor(math.random() * 4)
        if (ns >= 0 and ns < 4) then
        else
            ns = 0
        end
        AntiRobot_SelAnswer(ns)
    end
end

if AntiRobot_TimeReach_ == nil then
    AntiRobot_TimeReach_ = AntiRobot_TimeReach
    function AntiRobot_TimeReach()
        __AntiRobot_TimeReach();
        AntiRobot_TimeReach_();
    end
end

-- 游戏内验证码（选择）
function myanti()
    setmetatable(_G, { __index = AntiRobot_Env });
    if this:IsVisible() then
        return 1;
    else
        return 0;
    end
end
-- 读取游戏内验证码答案和剩余时间
function myantiinfo()
    setmetatable(_G, { __index = AntiRobot_Env });
    local tim = AntiRobot_StopWatch:GetProperty("Timer");
    return tim;
end

-- 读取游戏内验证码答案和剩余时间
function myantiinfo(typ)

    setmetatable(_G, { __index = AntiRobot_Env });
    if this:IsVisible() then
        if typ == 0 then
            local tim = AntiRobot_StopWatch:GetProperty("Timer");
            return tim;
        end
        if typ == 1 then
            local str = ""
            str = str .. "|" .. AntiRobot_Answer1:GetProperty("Text");
            str = str .. "|" .. AntiRobot_Answer2:GetProperty("Text");
            str = str .. "|" .. AntiRobot_Answer3:GetProperty("Text");
            str = str .. "|" .. AntiRobot_Answer4:GetProperty("Text") .. "|";
            return str;
        end
    end

    return -2;
end

 --SetTimer("mytimewindow_", "mytimewindow_Show()", 1000)

function SelectServer_my(Namestr)
    local iCurAreaCount = GameProduceLogin:GetServerAreaCount();
    for index = 0, iCurAreaCount - 1 do
        local strAreaName = GameProduceLogin:GetServerAreaName(index);
        iLoginServerCount = GameProduceLogin:GetAreaLoginServerCount(index);
        for i = 0, iLoginServerCount - 1 do
            ServerName,
            ServerStatus,
            RecommendLevel,
            IsNew
            , netPro,
            ServerPrizeLevel,
            ServerVersion
            = GameProduceLogin:GetAreaLoginServerInfo(index, i);
            if Namestr == ServerName then
                GameProduceLogin:SelectLoginServer(index, i, 3);
            end
        end
    end
end

function LoginPassWord(username, mail)
    -- local TailName ={
    -- [0] = "@changyou.com",
    -- "@game.sohu.com",
    -- "@Sohu.com",
    -- "@chinaren.com",
    -- "@sogou.com",
    -- "@17173.com",
    -- "手机号码登录",
    -- "输入其他账号后缀"
    -- }
    setmetatable(_G, { __index = LoginLogOn_Env });
    if this:IsVisible() then
        LogOn_LogonMailID_Active()
        LogOn_Region:SetCurrentSelect(tonumber(mail));
    end
    setmetatable(_G, { __index = LoginLogOn_Env });
    if this:IsVisible() then
        LogOn_LogonID_Active();
        LogOn_ID:SetText(tostring(username));
    end
    setmetatable(_G, { __index = LoginLogOn_Env });
    if this:IsVisible() then
        LogOn_LogonPassWord_Active();
        -- LogOn_PassWord:SetText("");
    end
end

function putinmibao(keyone, keytwo, keyse)
    setmetatable(_G, { __index = Pswprotect_Env });
    if this:IsVisible() then
        MiBao_Activated(1)
        Pswprotect_Input1:SetText(tostring(keyone));
        MiBao_Activated(2)
        Pswprotect_Input2:SetText(tostring(keytwo));
        MiBao_Activated(3)
        Pswprotect_Input3:SetText(tostring(keyse));
        MiBao_Click_OK()
    end
end
function loginmibao()
    -- 获取密保
    local strMiBAOtEXT = "";
    setmetatable(_G, { __index = Pswprotect_Env });
    if this:IsVisible() then
        local key1 = GameProduceLogin:GetMiBaoKey(0);
        local key2 = GameProduceLogin:GetMiBaoKey(1);
        local key3 = GameProduceLogin:GetMiBaoKey(2);
        strMiBAOtEXT = key1 .. "|" .. key2 .. "|" .. key3
        return strMiBAOtEXT
    end
    return "-1|-1|-1"
end

function mygethuoyuejindu(str)
    if str == "师门任务" then
        return DataPool:GetPlayerMission_DataCountByte(585.5, 2)
    end
    if str == "幸运快活三" then
        return DataPool:GetPlayerMission_DataCountByte(583.5, 2)
    end
    if str == "剿匪" then
        return DataPool:GetPlayerMission_DataCountByte(583.25, 1)
    end
    return -1;
end