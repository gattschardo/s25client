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
#ifndef CTRLTABLE_H_INCLUDED
#define CTRLTABLE_H_INCLUDED

#pragma once

#include "Window.h"
#include "gameTypes/TextureColor.h"
#include <vector>
#include <cstdarg>
#include <string>

class MouseCoords;
class glArchivItem_Font;
struct KeyEvent;

class ctrlTable : public Window
{
    public:
        ctrlTable(Window* parent, unsigned int id, unsigned short x, unsigned short y, unsigned short width,  unsigned short height, TextureColor tc, glArchivItem_Font* font, unsigned short column_count, va_list liste);
        ~ctrlTable() override;

        /// löscht alle Items.
        void DeleteAllItems();
        /// setzt die Auswahl.
        void SetSelection(unsigned short selection, bool left = true);
        /// fügt eine Zeile hinzu.
        void AddRow(unsigned alwaysnull, ...);
        /// liefert den Wert eines Feldes.
        const std::string& GetItemText(unsigned short row, unsigned short column) const;
        /// sortiert die Zeilen.
        void SortRows(unsigned short column, bool* direction = NULL);
        unsigned short GetSortColumn() { return sort_column; }
        bool GetSortDirection() { return sort_direction; }
        unsigned short GetRowCount() { return static_cast<unsigned short>(rows.size()); }
        unsigned short GetColumnCount() { return static_cast<unsigned short>(columns.size()); }
        unsigned short GetSelection(bool left = true) { return (left ? row_l_selection : row_r_selection); }

        bool Msg_LeftDown(const MouseCoords& mc) override;
        bool Msg_RightDown(const MouseCoords& mc) override;
        bool Msg_LeftUp(const MouseCoords& mc) override;
        bool Msg_WheelUp(const MouseCoords& mc) override;
        bool Msg_WheelDown(const MouseCoords& mc) override;
        bool Msg_MouseMove(const MouseCoords& mc) override;
        void Msg_ButtonClick(const unsigned int ctrl_id) override;
        void Msg_ScrollShow(const unsigned int ctrl_id, const bool visible) override;
        bool Msg_KeyDown(const KeyEvent& ke) override;

        enum SortType
        {
            SRT_STRING,
            SRT_MAPSIZE,
            SRT_NUMBER,
            SRT_DATE,
            SRT_DEFAULT
        };

    protected:

        bool Draw_() override;

        /// Größe ändern
        void Resize_(unsigned short width, unsigned short height) override;
        /// Setzt die Breite und Position der Buttons ohne Scrolleiste
        void ResetButtonWidths();
        unsigned short GetSelectionFromMouse(const MouseCoords &mc);

    private:
        TextureColor tc;
        glArchivItem_Font* font;

        unsigned short header_height;
        unsigned short line_count;

        struct COLUMN
        {
            /// Breite der Spalten in Promille von der Tabellenlänge
            unsigned short width;
            std::string title;
            SortType sortType;
        };
        std::vector<COLUMN> columns;

        unsigned short row_l_selection;
        unsigned short row_r_selection;

        unsigned short sort_column;
        bool sort_direction;

        struct ROW
        {
            std::vector<std::string> columns;
        };
        std::vector<ROW> rows;

        int Compare(const std::string& a, const std::string& b, SortType sortType);
};

#endif // !CTRLTABLE_H_INCLUDED
