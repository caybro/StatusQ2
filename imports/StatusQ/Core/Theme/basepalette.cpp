#include "basepalette.h"

namespace {
constexpr QColor kNeutralSolidColor{100, 112, 132}; // #647084

// common neutral colors, for both themes
constexpr std::array<Palette::ColorPair, 11> kNeutralColors = {{
    {Palette::Shade95, {9, 16, 28}},  // #09101C
    {Palette::Shade90, {13, 22, 37}}, // #0D1625
    {Palette::Shade80, {19, 29, 47}}, // #131D2F
    {Palette::Shade70, {25, 36, 56}}, // #192438
    {Palette::Shade60, {48, 61, 85}}, // #303D55
    {Palette::Shade50, kNeutralSolidColor},
    {Palette::Shade40, {161, 171, 189}}, // #A1ABBD
    {Palette::Shade30, {231, 234, 238}}, // #E7EAEE
    {Palette::Shade20, {236, 238, 241}}, // #ECEEF1
    {Palette::Shade10, {240, 242, 245}}, // #F0F2F5
    {Palette::Shade5, {245, 246, 248}}, // #F5F6F8
}};
} // namespace

Palette::Palette(QObject *parent)
    : QObject{parent}
{}

QColor Palette::neutralColor(Palette::Shade shade, float alpha) const
{
    return Palette::getColor(kNeutralSolidColor, kNeutralColors, shade, alpha);
}

QList<QColor> Palette::identiconColors() const
{
    return {
        QColorConstants::Black, QColorConstants::Green, QColorConstants::Yellow,
        QColorConstants::Red, QColorConstants::Magenta, QColorConstants::Blue,
        QColorConstants::Cyan, //TODO
    };
}
