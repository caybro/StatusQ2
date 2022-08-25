#include "darkpalette.h"

#include <array>

namespace {
constexpr QColor kPrimaryDefaultColor{82, 112, 247}; // #5270F7
constexpr std::array<Palette::ColorPair, 11> kPrimaryColors{{
  {Palette::Shade95, {43, 67, 172}}, // #2B43AC
  {Palette::Shade90, {47, 73, 187}}, // #2F49BB
  {Palette::Shade80, {51, 77, 202}}, // #334DCA
  {Palette::Shade70, {54, 83, 217}}, // #3653D9
  {Palette::Shade60, {58, 89, 232}}, // #3A59E8
  {Palette::Shade50, kPrimaryDefaultColor},
  {Palette::Shade40, {113, 137, 248}}, // #7189F8
  {Palette::Shade30, {144, 163, 249}}, // #90A3F9
  {Palette::Shade20, {175, 189, 251}}, // #AFBDFB
  {Palette::Shade10, {206, 214, 252}}, // #CED6FC
  {Palette::Shade5, {237, 240, 254}} // #EDF0FE
}};

constexpr QColor kSuccessDefaultColor{0, 140, 115}; // #008C73
constexpr std::array<Palette::ColorPair, 11> kSuccessColors{{
  {Palette::Shade95, {0, 98, 80}},   // #006250
  {Palette::Shade90, {0, 106, 87}},  // #006A57
  {Palette::Shade80, rgba(0, 114, 94, 1)},
  {Palette::Shade70, rgba(0, 123, 101, 1)},
  {Palette::Shade60, {0, 131, 108}}, // #00836C
  {Palette::Shade50, kSuccessDefaultColor},
  {Palette::Shade40, rgba(45, 160, 140, 1)},
  {Palette::Shade30, rgba(91, 181, 165, 1)},
  {Palette::Shade20, rgba(137, 202, 190, 1)},
  {Palette::Shade10, rgba(183, 222, 215, 1)},
  {Palette::Shade5,  rgba(229, 243, 241, 1)}
}};

constexpr QColor kInfoDefaultColor{13, 136, 158}; // #0D889E
constexpr std::array<Palette::ColorPair, 11> kInfoColors{{
  {Palette::Shade95, {0, 94, 110}},  // #005E6E
  {Palette::Shade90, {0, 102, 120}}, // #006678
  {Palette::Shade80, rgba(0, 109, 129, 1)},
  {Palette::Shade70, rgba(0, 117, 139, 1)},
  {Palette::Shade60, {0, 125, 148}}, // #007D94
  {Palette::Shade50, kInfoDefaultColor},
  {Palette::Shade40, rgba(56, 157, 175, 1)},
  {Palette::Shade30, rgba(100, 178, 192, 1)},
  {Palette::Shade20, rgba(143, 200, 210, 1)},
  {Palette::Shade10, rgba(187, 221, 227, 1)},
  {Palette::Shade5, rgba(230, 243, 245, 1)}
}};

constexpr QColor kWarningDefaultColor{240, 95, 29}; // #F05F1D
constexpr std::array<Palette::ColorPair, 11> kWarningColors{{
  {Palette::Shade95, {168, 57, 7}}, // #A83907
  {Palette::Shade90, {182, 62, 7}}, // #B63E07
  {Palette::Shade80, rgba(196, 67, 8, 1)},
  {Palette::Shade70, rgba(211, 72, 8, 1)},
  {Palette::Shade60, {225, 77, 9}}, // #E14D09
  {Palette::Shade50, kWarningDefaultColor},
  {Palette::Shade40, rgba(242, 123, 69, 1)},
  {Palette::Shade30, rgba(245, 152, 110, 1)},
  {Palette::Shade20, rgba(248, 181, 151, 1)},
  {Palette::Shade10, rgba(250, 210, 191, 1)},
  {Palette::Shade5, rgba(253, 239, 232, 1)}
}};

constexpr QColor kDangerDefaultColor{229, 55, 87}; // #E53757
constexpr std::array<Palette::ColorPair, 11> kDangerColors{{
  {Palette::Shade95, {160, 26, 50}}, // #A01A32
  {Palette::Shade90, {174, 28, 55}}, // #AE1C37
  {Palette::Shade80, rgba(187, 30, 59, 1)},
  {Palette::Shade70, rgba(201, 32, 63, 1)},
  {Palette::Shade60, {215, 34, 67}}, // #D72243
  {Palette::Shade50, kDangerDefaultColor},
  {Palette::Shade40, rgba(233, 91, 117, 1)},
  {Palette::Shade30, rgba(238, 127, 147, 1)},
  {Palette::Shade20, rgba(243, 163, 177, 1)},
  {Palette::Shade10, rgba(247, 199, 207, 1)},
  {Palette::Shade5,  rgba(252, 235, 238, 1)}
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

QVariantMap DarkPalette::customizationColors() const
{
  return {
    {QStringLiteral("blue"), rgba(170, 198, 255, 1)},
    {QStringLiteral("purple"), rgba(136, 122, 249, 1)},
    {QStringLiteral("cyan"), rgba(81, 208, 240, 1)},
    {QStringLiteral("violet"), rgba(211, 126, 244, 1)},
    {QStringLiteral("grep"), rgba(250, 101, 101, 1)},
    {QStringLiteral("yellow"), rgba(255, 202, 15, 1)},
    {QStringLiteral("grass"), rgba(147, 219, 51, 1)},
    {QStringLiteral("moss"), rgba(16, 168, 142, 1)},
    {QStringLiteral("vintage"), rgba(173, 67, 67, 1)},
    {QStringLiteral("khaki"), rgba(234, 210, 123, 1)},
  };
}
