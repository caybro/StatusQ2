#include "darkpalette.h"

#include <array>

namespace {
constexpr QColor kPrimaryDefaultColor{82, 112, 247}; // #5270F7
constexpr std::array<Palette::ColorPair, 4> kPrimaryColors{{
    {Palette::Shade95, {43, 67, 172}}, // #2B43AC
    {Palette::Shade90, {47, 73, 187}}, // #2F49BB
    {Palette::Shade60, {58, 89, 232}}, // #3A59E8
    {Palette::Shade50, kPrimaryDefaultColor},
    // TODO
}};

constexpr QColor kSuccessDefaultColor{0, 140, 115}; // #008C73
constexpr std::array<Palette::ColorPair, 4> kSuccessColors{{
    {Palette::Shade95, {0, 98, 80}},   // #006250
    {Palette::Shade90, {0, 106, 87}},  // #006A57
    {Palette::Shade60, {0, 131, 108}}, // #00836C
    {Palette::Shade50, kSuccessDefaultColor},
    // TODO
}};

constexpr QColor kInfoDefaultColor{13, 136, 158}; // #0D889E
constexpr std::array<Palette::ColorPair, 4> kInfoColors{{
    {Palette::Shade95, {0, 94, 110}},  // #005E6E
    {Palette::Shade90, {0, 102, 120}}, // #006678
    {Palette::Shade60, {0, 125, 148}}, // #007D94
    {Palette::Shade50, kInfoDefaultColor},
    // TODO
}};

constexpr QColor kWarningDefaultColor{240, 95, 29}; // #F05F1D
constexpr std::array<Palette::ColorPair, 4> kWarningColors{{
    {Palette::Shade95, {168, 57, 7}}, // #A83907
    {Palette::Shade90, {182, 62, 7}}, // #B63E07
    {Palette::Shade60, {225, 77, 9}}, // #E14D09
    {Palette::Shade50, kWarningDefaultColor},
    // TODO
}};

constexpr QColor kDangerDefaultColor{229, 55, 87}; // #E53757
constexpr std::array<Palette::ColorPair, 4> kDangerColors{{
    {Palette::Shade95, {160, 26, 50}}, // #A01A32
    {Palette::Shade90, {174, 28, 55}}, // #AE1C37
    {Palette::Shade60, {215, 34, 67}}, // #D72243
    {Palette::Shade50, kDangerDefaultColor},
    // TODO
}};
} // namespace

DarkPalette::DarkPalette(QObject *parent)
    : Palette{parent}
{}

QString DarkPalette::name() const
{
  return tr("Dark", "dark theme");
}

Palette::Type DarkPalette::type() const
{
  return Palette::Type::Dark;
}

QColor DarkPalette::backgroundColor() const
{
  return neutralColor(Palette::Shade90);
}

QColor DarkPalette::baseColor() const
{
  return white(0.1);
}

QColor DarkPalette::secondaryBaseColor() const
{
  return white(0.05);
}

QColor DarkPalette::textColor() const
{
  return white();
}

QColor DarkPalette::secondaryTextColor() const
{
  return white(0.4);
}

QColor DarkPalette::primaryColor(Shade shade, float alpha) const
{
  return Palette::getColor(kPrimaryDefaultColor, kPrimaryColors, shade, alpha);
}

QColor DarkPalette::successColor(Shade shade, float alpha) const
{
  return Palette::getColor(kSuccessDefaultColor, kSuccessColors, shade, alpha);
}

QColor DarkPalette::infoColor(Shade shade, float alpha) const
{
  return Palette::getColor(kInfoDefaultColor, kInfoColors, shade, alpha);
}

QColor DarkPalette::warningColor(Shade shade, float alpha) const
{
  return Palette::getColor(kWarningDefaultColor, kWarningColors, shade, alpha);
}

QColor DarkPalette::dangerColor(Shade shade, float alpha) const
{
  return Palette::getColor(kDangerDefaultColor, kDangerColors, shade, alpha);
}
