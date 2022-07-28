#pragma once

#include <QFont>
#include <QObject>
#include <QmlTypeAndRevisionsRegistration>

#include <memory>

#include "basepalette.h"

class Theme : public QObject
{
  Q_OBJECT
  QML_ELEMENT
  QML_SINGLETON
  Q_DISABLE_COPY_MOVE(Theme)

  Q_PROPERTY(Palette::Type type READ type WRITE setType NOTIFY themeChanged)
  Q_PROPERTY(Palette *palette READ palette NOTIFY themeChanged)
  Q_PROPERTY(QFont font READ font CONSTANT)

  // TODO metrics

 public:
  explicit Theme(QObject *parent = nullptr);

 signals:
  void themeChanged();

 private:
  Palette::Type type() const;
  void setType(Palette::Type type);

  Palette *palette() const;
  std::unique_ptr<Palette> m_palette;

  // fonts are setup/loaded in plugin.cpp
  QFont font() const;
};
