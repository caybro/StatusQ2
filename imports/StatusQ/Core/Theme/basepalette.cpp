#include "basepalette.h"

namespace {
constexpr QColor kNeutralSolidColor{rgba(100, 112, 132, 1)};

// common neutral colors, for both themes
constexpr std::array<Palette::ColorPair, 12> kNeutralColors = {{
  {Palette::Shade100, rgba(9, 16, 28, 1)},
  {Palette::Shade95, rgba(13, 22, 37, 1)},
  {Palette::Shade90, rgba(19, 29, 47, 1)},
  {Palette::Shade80, rgba(27, 39, 61, 1)},
  {Palette::Shade70, rgba(32, 44, 66, 1)},
  {Palette::Shade60, rgba(48, 61, 85, 1)},
  {Palette::Shade50, kNeutralSolidColor},
  {Palette::Shade40, rgba(161, 171, 189, 1)},
  {Palette::Shade30, rgba(220, 224, 229, 1)},
  {Palette::Shade20, rgba(231, 234, 238, 1)},
  {Palette::Shade10, rgba(240, 242, 245, 1)},
  {Palette::Shade5, rgba(245, 246, 248, 1)}
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
    QColorConstants::Cyan, rgba(114, 111, 111, 1), rgba(0, 152, 0, 1), rgba(168, 172, 0, 1),
    rgba(154, 0, 0, 1), rgba(144, 0, 144, 1), rgba(0, 0, 134, 1), rgba(0, 134, 148, 1),
    rgba(196, 196, 196, 1), rgba(184, 255, 187, 1), rgba(255, 255, 176, 1), rgba(255, 157, 157, 1),
    rgba(255, 176, 255, 1), rgba(155, 129, 255, 1), rgba(194, 255, 255, 1), rgba(231, 231, 231, 1),
    rgba(255, 196, 19, 1), rgba(255, 87, 51, 1), rgba(255, 0, 153, 1), rgba(158, 0, 255, 1),
    rgba(63, 174, 249, 1), rgba(0, 240, 182, 1), QColorConstants::White, rgba(159, 89, 71, 1),
    rgba(200, 0, 120, 1), rgba(154, 102, 0, 1)
  };
}

QVariantMap Palette::networkColors() const
{
  return {
    {QStringLiteral("ethereum"), rgba(117, 142, 235, 1)},
    {QStringLiteral("optimism"), rgba(231, 110, 110, 1)},
    {QStringLiteral("arbitrum"), rgba(107, 213, 240, 1)},
    {QStringLiteral("zkSync"), rgba(159, 160, 254, 1)},
    {QStringLiteral("hermez"), rgba(235, 132, 98, 1)},
    {QStringLiteral("xDAI"), rgba(63, 192, 189, 1)},
    {QStringLiteral("polygon"), rgba(173, 113, 243, 1)},
    {QStringLiteral("unknown"), rgba(238, 242, 245, 1)}
  };
}
