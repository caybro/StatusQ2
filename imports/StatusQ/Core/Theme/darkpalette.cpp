#include "darkpalette.h"

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
  return neutralColor(Palette::Shade60);
}

QColor DarkPalette::secondaryBaseColor() const
{
  return neutralColor(Palette::Shade80);
}

QColor DarkPalette::textColor() const
{
  return white();
}

QColor DarkPalette::secondaryTextColor() const
{
  return neutralColor();
}

QColor DarkPalette::primaryColor() const
{
  return rgba(53, 77, 178, 1);
}

QColor DarkPalette::successColor() const
{
  return rgba(32, 139, 129, 1);
}

QColor DarkPalette::dangerColor() const
{
  return rgba(193, 80, 77, 1);
}

QVariantMap DarkPalette::customizationColors() const
{
  return {
    {QStringLiteral("purple"), rgba(94, 71, 140, 1)},
    {QStringLiteral("indigo"), rgba(61, 82, 115, 1)},
    {QStringLiteral("turquoise"), rgba(57, 119, 136, 1)},
    {QStringLiteral("blue"), rgba(64, 151, 201, 1)},
    {QStringLiteral("green"), rgba(76, 171, 125, 1)},
    {QStringLiteral("yellow"), rgba(214, 170, 70, 1)},
    {QStringLiteral("orange"), rgba(211, 120, 81, 1)},
    {QStringLiteral("red"), rgba(205, 86, 86, 1)},
    {QStringLiteral("pink"), rgba(212, 103, 144, 1)},
    {QStringLiteral("brown"), rgba(128, 81, 65, 1)},
    {QStringLiteral("beige"), rgba(170, 146, 124, 1)}
  };
}
