#pragma once

#include "basepalette.h"

class DarkPalette final : public Palette
{
  Q_OBJECT

 public:
  explicit DarkPalette(QObject *parent = nullptr);

  QString name() const override;
  Palette::Type type() const override;

  QColor backgroundColor() const override;
  QColor baseColor() const override;
  QColor secondaryBaseColor() const override;
  QColor textColor() const override;
  QColor secondaryTextColor() const override;

  QColor primaryColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const override;
  QColor successColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const override;
  QColor infoColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const override;
  QColor warningColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const override;
};
