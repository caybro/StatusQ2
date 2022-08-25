#include "lightpalette.h"

#include <array>

namespace {
constexpr QColor kPrimaryDefaultColor{67, 96, 223}; // #4360DF
constexpr std::array<Palette::ColorPair, 11> kPrimaryColors{{
  {Palette::Shade95, {33, 56, 156}}, // #21389C
  {Palette::Shade90, {37, 62, 169}}, // #253EA9
  {Palette::Shade80, {40, 67, 182}}, // #2843B6
  {Palette::Shade70, {43, 72, 196}}, // #2B48C4
  {Palette::Shade60, {46, 77, 209}}, // #2E4DD1
  {Palette::Shade50, kPrimaryDefaultColor},
  {Palette::Shade40, {100, 124, 228}}, // #647CE4
  {Palette::Shade30, {134, 153, 234}}, // #8699EA
  {Palette::Shade20, {168, 181, 240}}, // #A8B5F0
  {Palette::Shade10, {202, 210, 246}}, // #CAD2F6
  {Palette::Shade5, {236, 239, 251}} // #ECEFFB
}};

constexpr QColor kSuccessDefaultColor{8, 133, 110}; // #08856E
constexpr std::array<Palette::ColorPair, 11> kSuccessColors{{
  {Palette::Shade95, {0, 93, 76}},   // #005D4C
  {Palette::Shade90, {0, 101, 82}},  // #006552
  {Palette::Shade80, rgba(0, 109, 89, 1)},
  {Palette::Shade70, rgba(0, 117, 95, 1)},
  {Palette::Shade60, {0, 125, 102}}, // #007D66
  {Palette::Shade50, kSuccessDefaultColor},
  {Palette::Shade40, rgba(52, 154, 136, 1)},
  {Palette::Shade30, rgba(96, 176, 162, 1)},
  {Palette::Shade20, rgba(141, 198, 188, 1)},
  {Palette::Shade10, rgba(185, 220, 214, 1)},
  {Palette::Shade5, rgba(230, 242, 240, 1)}
}};

constexpr QColor kInfoDefaultColor{11, 156, 181}; // #0B9CB5
constexpr std::array<Palette::ColorPair, 11> kInfoColors{{
  {Palette::Shade95, {0, 108, 126}}, // #006C7E
  {Palette::Shade90, {0, 117, 137}}, // #007589
  {Palette::Shade80, rgba(0, 126, 148, 1)},
  {Palette::Shade70, rgba(0, 136, 159, 1)},
  {Palette::Shade60, {0, 144, 170}}, // #0090AA
  {Palette::Shade50, kInfoDefaultColor},
  {Palette::Shade40, rgba(54, 173, 194, 1)},
  {Palette::Shade30, rgba(98, 191, 207, 1)},
  {Palette::Shade20, rgba(142, 209, 220, 1)},
  {Palette::Shade10, rgba(186, 227, 234, 1)},
  {Palette::Shade5, rgba(230, 245, 247, 1)}
}};

constexpr QColor kWarningDefaultColor{229, 98, 37}; // #E56225
constexpr std::array<Palette::ColorPair, 11> kWarningColors{{
  {Palette::Shade95, {160, 60, 13}}, // #A03C0D
  {Palette::Shade90, {174, 64, 14}}, // #AE400E
  {Palette::Shade80, rgba(187, 70, 15, 1)},
  {Palette::Shade70, rgba(201, 75, 16, 1)},
  {Palette::Shade60, {215, 81, 17}}, // #D75111
  {Palette::Shade50, kWarningDefaultColor},
  {Palette::Shade40, rgba(233, 126, 76, 1)},
  {Palette::Shade30, rgba(238, 154, 115, 1)},
  {Palette::Shade20, rgba(243, 182, 154, 1)},
  {Palette::Shade10, rgba(247, 211, 193, 1)},
  {Palette::Shade5, rgba(252, 239, 233, 1)}
}};

constexpr QColor kDangerDefaultColor{217, 35, 68}; // #D92344
constexpr std::array<Palette::ColorPair, 11> kDangerColors{{
  {Palette::Shade95, {151, 12, 37}}, // #970C25
  {Palette::Shade90, {164, 13, 40}}, // #A40D28
  {Palette::Shade80, rgba(177, 14, 44, 1)},
  {Palette::Shade70, rgba(190, 15, 47, 1)},
  {Palette::Shade60, {203, 16, 50}}, // #CB1032
  {Palette::Shade50, kDangerDefaultColor},
  {Palette::Shade40, rgba(223, 74, 101, 1)},
  {Palette::Shade30, rgba(230, 114, 135, 1)},
  {Palette::Shade20, rgba(237, 153, 168, 1)},
  {Palette::Shade10, rgba(244, 193, 202, 1)},
  {Palette::Shade5, rgba(251, 233, 236, 1)}
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

QVariantMap LightPalette::customizationColors() const
{
  return {
    {QStringLiteral("blue"), rgba(41, 70, 196, 1)},
    {QStringLiteral("purple"), rgba(136, 122, 249, 1)},
    {QStringLiteral("cyan"), rgba(81, 208, 240, 1)},
    {QStringLiteral("violet"), rgba(211, 126, 244, 1)},
    {QStringLiteral("grep"), rgba(250, 101, 101, 1)},
    {QStringLiteral("yellow"), rgba(250, 101, 101, 1)},
    {QStringLiteral("grass"), rgba(124, 218, 0, 1)},
    {QStringLiteral("moss"), rgba(38, 166, 154, 1)},
    {QStringLiteral("vintage"), rgba(139, 49, 49, 1)},
    {QStringLiteral("khaki"), rgba(155, 131, 47, 1)},
  };
}
