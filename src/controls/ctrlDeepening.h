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
#ifndef CTRLDEEPENING_H_INCLUDED
#define CTRLDEEPENING_H_INCLUDED

#pragma once

#include "ctrlText.h"
#include "ColorControlInterface.h"
class Window;
class glArchivItem_Font;

class ctrlDeepening : public ctrlText
{
    public:
        ctrlDeepening(Window* parent, unsigned int id, unsigned short x, unsigned short y, unsigned short width, unsigned short height, TextureColor tc, const std::string& text, glArchivItem_Font* font, unsigned int color);

    protected:
        bool Draw_() override;
        /// Derived classes cann draw extended content
        virtual void DrawContent() const{}

    private:
        TextureColor tc;
};

/// Colored Deepening
class ctrlColorDeepening : public ctrlDeepening, public ColorControlInterface
{
    public:
        ctrlColorDeepening(Window* parent, unsigned int id, unsigned short x, unsigned short y, unsigned short width, unsigned short height, TextureColor tc, unsigned int fillColor);

        /// Setzt die Farbe des Controls
        void SetColor(const unsigned int fill_color) override;

    protected:
        void DrawContent() const override;

    protected:
        unsigned int fillColor;
};

#endif // !CTRLDEEPENING_H_INCLUDED

