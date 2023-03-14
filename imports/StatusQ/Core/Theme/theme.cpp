#include "theme.h"

#include "darkpalette.h"
#include "lightpalette.h"

#include <QGuiApplication>
#include <QPalette>

namespace {
static bool qt_is_dark_system_theme()
{
  auto pal = qApp->palette();
  const QColor &textColor = pal.color(QPalette::WindowText);
  return textColor.red() > 128 && textColor.blue() > 128 && textColor.green() > 128;
}
} // namespace

Theme::Theme(QObject *parent)
  : QObject{parent}
  , m_metrics(std::make_unique<Metrics>(this))
  , m_fonts(std::make_unique<Fonts>(this))
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
    m_palette = std::make_unique<DarkPalette>(this);
  } else {
    m_palette = std::make_unique<LightPalette>(this);
  }
  emit themeChanged();
}

Palette *Theme::palette() const
{
  return m_palette.get();
}

Metrics *Theme::metrics() const
{
  return m_metrics.get();
}

Fonts *Theme::fonts() const
{
  return m_fonts.get();
}
