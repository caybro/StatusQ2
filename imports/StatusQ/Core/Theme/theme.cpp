#include "theme.h"

#include "darkpalette.h"
#include "lightpalette.h"

#include <QGuiApplication>
#include <QPalette>

namespace {
static bool qt_is_dark_system_theme()
{
  auto pal = qApp->palette();
  const QColor textColor = pal.color(QPalette::WindowText);
  return textColor.red() > 128 && textColor.blue() > 128 && textColor.green() > 128;
}
}

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
  if (type == Palette::Type::Dark || qt_is_dark_system_theme()) {
    m_palette.reset(new DarkPalette(this));
  } else {
    m_palette.reset(new LightPalette(this));
  }
  emit themeChanged();
}

Palette *Theme::palette() const
{
  return m_palette.get();
}

QFont Theme::font() const
{
  return qApp->font();
}
