#include "lightpalette.h"

#include <array>

namespace {
constexpr QColor kPrimaryDefaultColor{67, 96, 223}; // #4360DF
constexpr std::array<Palette::ColorPair, 4> kPrimaryColors{{
    {Palette::Shade95, {33, 56, 156}}, // #21389C
    {Palette::Shade90, {37, 62, 169}}, // #253EA9
    {Palette::Shade60, {46, 77, 209}}, // #2E4DD1
    {Palette::Shade50, kPrimaryDefaultColor},
    // TODO
}};

constexpr QColor kSuccessDefaultColor{8, 133, 110}; // #08856E
constexpr std::array<Palette::ColorPair, 4> kSuccessColors{{
    {Palette::Shade95, {0, 93, 76}},   // #005D4C
    {Palette::Shade90, {0, 101, 82}},  // #006552
    {Palette::Shade60, {0, 125, 102}}, // #007D66
    {Palette::Shade50, kSuccessDefaultColor},
    // TODO
}};

constexpr QColor kInfoDefaultColor{11, 156, 181}; // #0B9CB5
constexpr std::array<Palette::ColorPair, 4> kInfoColors{{
    {Palette::Shade95, {0, 108, 126}}, // #006C7E
    {Palette::Shade90, {0, 117, 137}}, // #007589
    {Palette::Shade60, {0, 144, 170}}, // #0090AA
    {Palette::Shade50, kInfoDefaultColor},
    // TODO
}};

constexpr QColor kWarningDefaultColor{229, 98, 37}; // #E56225
constexpr std::array<Palette::ColorPair, 4> kWarningColors{{
    {Palette::Shade95, {160, 60, 13}}, // #A03C0D
    {Palette::Shade90, {174, 64, 14}}, // #AE400E
    {Palette::Shade60, {215, 81, 17}}, // #D75111
    {Palette::Shade50, kWarningDefaultColor},
    // TODO
}};

constexpr QColor kDangerDefaultColor{217, 35, 68}; // #D92344
constexpr std::array<Palette::ColorPair, 4> kDangerColors{{
    {Palette::Shade95, {151, 12, 37}}, // #970C25
    {Palette::Shade90, {164, 13, 40}}, // #A40D28
    {Palette::Shade60, {203, 16, 50}}, // #CB1032
    {Palette::Shade50, kDangerDefaultColor},
    // TODO
}};
} // namespace

LightPalette::LightPalette(QObject *parent)
    : Palette{parent}
{}

QString LightPalette::name() const
{
  return tr("Light", "light theme");
}

Palette::Type LightPalette::type() const
{
  return Palette::Type::Light;
}

QColor LightPalette::backgroundColor() const
{
  return white();
}

QColor LightPalette::baseColor() const
{
  return neutralColor(Palette::Shade50, 0.1);
}

QColor LightPalette::secondaryBaseColor() const
{
  return neutralColor(Palette::Shade50, 0.05);
}

QColor LightPalette::textColor() const
{
  return neutralColor(Palette::Shade90);
}

QColor LightPalette::secondaryTextColor() const
{
  return neutralColor(Palette::Shade90, 0.4);
}

QColor LightPalette::primaryColor(Shade shade, float alpha) const
{
  return Palette::getColor(kPrimaryDefaultColor, kPrimaryColors, shade, alpha);
}

QColor LightPalette::successColor(Shade shade, float alpha) const
{
  return Palette::getColor(kSuccessDefaultColor, kSuccessColors, shade, alpha);
}

QColor LightPalette::infoColor(Shade shade, float alpha) const
{
  return Palette::getColor(kInfoDefaultColor, kInfoColors, shade, alpha);
}

QColor LightPalette::warningColor(Shade shade, float alpha) const
{
  return Palette::getColor(kWarningDefaultColor, kWarningColors, shade, alpha);
}

QColor LightPalette::dangerColor(Shade shade, float alpha) const
{
  return Palette::getColor(kDangerDefaultColor, kDangerColors, shade, alpha);
}
