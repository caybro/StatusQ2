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

  QColor primaryColor() const override;
  QColor successColor() const override;
  QColor dangerColor() const override;

  QVariantMap customizationColors() const override;
};
