// Copyright (c) 2005 - 2015 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.
#ifndef dskLAN_H_INCLUDED
#define dskLAN_H_INCLUDED

#pragma once

#include "Desktop.h"
#include "LANDiscoveryClient.h"
#include "gameTypes/LanGameInfo.h"
#include <vector>

class dskLAN : public Desktop
{
public:
    struct GameInfo {
        std::string ip;
        LanGameInfo info;
    };
    dskLAN();


protected:
    void Msg_Timer(const unsigned int ctrl_id) override;
    void Msg_PaintBefore() override;
    void Msg_ButtonClick(const unsigned int ctrl_id) override;
    void Msg_TableChooseItem(const unsigned ctrl_id, const unsigned short selection) override;

    /**
        * Connects to the currently selected game and returns true on success
        */
    bool ConnectToSelectedGame();

private:
    LANDiscoveryClient discovery;
    std::vector<GameInfo> openGames;

    void UpdateServerList();
    void ReadOpenGames();
};

#endif // dskLAN_H_INCLUDED
