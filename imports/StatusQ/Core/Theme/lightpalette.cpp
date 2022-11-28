#include "lightpalette.h"

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
  return neutralColor(Palette::Shade40);
}

QColor LightPalette::secondaryBaseColor() const
{
  return neutralColor(Palette::Shade20);
}

QColor LightPalette::textColor() const
{
  return neutralColor(Palette::Shade100);
}

QColor LightPalette::secondaryTextColor() const
{
  return neutralColor(Palette::Shade40);
}

QColor LightPalette::primaryColor() const
{
  return rgba(67, 96, 223, 1);
}

QColor LightPalette::successColor() const
{
  return rgba(38, 166, 154, 1);
}

QColor LightPalette::dangerColor() const
{
  return rgba(230, 95, 92, 1);
}

QVariantMap LightPalette::customizationColors() const
{
  return {
    {QStringLiteral("purple"), rgba(134, 97, 193, 1)},
    {QStringLiteral("indigo"), rgba(73, 98, 137, 1)},
    {QStringLiteral("turquoise"), rgba(68, 142, 162, 1)},
    {QStringLiteral("blue"), rgba(76, 180, 239, 1)},
    {QStringLiteral("green"), rgba(91, 204, 149, 1)},
    {QStringLiteral("yellow"), rgba(255, 203, 83, 1)},
    {QStringLiteral("orange"), rgba(251, 143, 97, 1)},
    {QStringLiteral("red"), rgba(244, 102, 102, 1)},
    {QStringLiteral("pink"), rgba(252, 123, 171, 1)},
    {QStringLiteral("brown"), rgba(153, 96, 77, 1)},
    {QStringLiteral("beige"), rgba(202, 174, 147, 1)}
  };
}
