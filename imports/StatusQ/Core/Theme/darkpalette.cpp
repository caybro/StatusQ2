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

QVariantMap DarkPalette::customizationColors() const
{
    return {
        {QStringLiteral("blue"), QLatin1String("#AAC6FF")},
        {QStringLiteral("purple"), QLatin1String("#887AF9")},
        {QStringLiteral("cyan"), QLatin1String("#51D0F0")},
        {QStringLiteral("violet"), QLatin1String("#D37EF4")},
        {QStringLiteral("grep"), QLatin1String("#FA6565")},
        {QStringLiteral("yellow"), QLatin1String("#FFCA0F")},
        {QStringLiteral("grass"), QLatin1String("#93DB33")},
        {QStringLiteral("moss"), QLatin1String("#10A88E")},
        {QStringLiteral("vintage"), QLatin1String("#AD4343")},
        {QStringLiteral("khaki"), QLatin1String("#EAD27B")},
    };
}
