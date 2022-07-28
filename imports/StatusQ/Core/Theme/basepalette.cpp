#include "basepalette.h"

namespace {
constexpr QColor kNeutralSolidColor{100, 112, 132}; // #647084

// common neutral colors, for both themes
constexpr std::array<Palette::ColorPair, 3> kNeutralColors = {{
    {Palette::Shade95, {9, 16, 28}}, // #09101C
    {Palette::Shade90, {13, 22, 37}}, // #0D1625
    {Palette::Shade50, kNeutralSolidColor}, // #647084
    // TODO
}};
}

Palette::Palette(QObject *parent)
    : QObject{parent}
{
}

QColor Palette::neutralColor(Palette::Shade shade, float alpha) const
{
  return Palette::getColor(kNeutralSolidColor, kNeutralColors, shade, alpha);
}
