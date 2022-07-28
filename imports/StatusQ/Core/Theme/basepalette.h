#pragma once

#include <QColor>
#include <QObject>
#include <QmlTypeAndRevisionsRegistration>

#include <utility> // std::pair

class Palette : public QObject
{
  Q_OBJECT
  QML_ELEMENT
  QML_UNCREATABLE("Cannot create Palette directly")

  Q_PROPERTY(QString name READ name CONSTANT)
  Q_PROPERTY(Palette::Type type READ type CONSTANT)

  Q_PROPERTY(QColor transparent READ transparent CONSTANT)
  Q_PROPERTY(QColor backgroundColor READ backgroundColor CONSTANT)
  Q_PROPERTY(QColor baseColor READ baseColor CONSTANT)
  Q_PROPERTY(QColor secondaryBaseColor READ secondaryBaseColor CONSTANT)
  Q_PROPERTY(QColor textColor READ textColor CONSTANT)
  Q_PROPERTY(QColor secondaryTextColor READ secondaryTextColor CONSTANT)

  Q_PROPERTY(float disabledOpacity READ disabledOpacity CONSTANT)
  Q_PROPERTY(float secondaryDisabledOpacity READ secondaryDisabledOpacity CONSTANT)

 public:
  enum class Type {
    Light,
    Dark,
    System, // FIXME
  };
  Q_ENUM(Type)

  enum Shade {
    Shade5,
    Shade10,
    Shade20,
    Shade30,
    Shade40,
    Shade50,
    Shade60,
    Shade70,
    Shade80,
    Shade90,
    Shade95,
  };
  Q_ENUM(Shade)

  enum class ControlState {
    Normal,
    Hover,
    Active, // active,pressed,selected,focused
  };
  Q_ENUM(ControlState)

  using ColorPair = std::pair<Palette::Shade, QColor>;

  explicit Palette(QObject *parent = nullptr);

  // generic properties
  virtual QString name() const = 0;
  virtual Palette::Type type() const = 0;

  // common colors
  Q_INVOKABLE QColor neutralColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const;
  Q_INVOKABLE inline constexpr QColor white(float alpha = 1.f) const
  {
    return {255, 255, 255, static_cast<int>(alpha * 255)};
  }

  // theme specific colors, to be implemented in light/dark palettes
  Q_INVOKABLE virtual QColor primaryColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const = 0;
  Q_INVOKABLE virtual QColor successColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const = 0;
  Q_INVOKABLE virtual QColor infoColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const = 0;
  Q_INVOKABLE virtual QColor warningColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const = 0;
  Q_INVOKABLE virtual QColor dangerColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const = 0;

 protected:
  // helper
  static constexpr auto getColor = [](const QColor &defaultColor, const auto &container, Palette::Shade shade,
                                      float alpha = 1.f) -> QColor {
    const auto colorIt = std::find_if(std::cbegin(container), std::cend(container),
                                      [shade](const Palette::ColorPair &pair) { return shade == pair.first; });

    if (colorIt == std::cend(container))
      return defaultColor;

    if (qFuzzyCompare(alpha, 1.f)) {
      return colorIt->second;
    }

    QColor color(colorIt->second);
    color.setAlphaF(alpha);
    return color;
  };

  // theme specific color properties, to be implemented in light/dark palettes
  virtual QColor backgroundColor() const = 0;
  virtual QColor baseColor() const = 0;
  virtual QColor secondaryBaseColor() const = 0;
  virtual QColor textColor() const = 0;
  virtual QColor secondaryTextColor() const = 0;

 private:
  // general color properties
  inline constexpr QColor transparent() const { return QColorConstants::Transparent; }

  // general palette-related properties
  inline constexpr float disabledOpacity() const { return 0.5; }
  inline constexpr float secondaryDisabledOpacity() const { return 0.2; }
};
