#include "theme.h"

#include "lightpalette.h"
#include "darkpalette.h"

#include <QGuiApplication>

Theme::Theme(QObject *parent)
    : QObject{parent}
{
  setType(Palette::Type::Light);
}

Palette::Type Theme::type() const
{
  return m_palette->type();
}

void Theme::setType(Palette::Type type)
{
  if (type == Palette::Type::Dark) {
    m_palette.reset(new DarkPalette(this));
  } else {
    m_palette.reset(new LightPalette(this));
  }
  emit themeChanged();
}

Palette* Theme::palette() const
{
  return m_palette.get();
}

QFont Theme::font() const
{
  return qApp->font();
}
