#pragma once

#include <QColor>
#include <QObject>
#include <QmlTypeAndRevisionsRegistration>

#include <utility> // std::pair

// CSS rgba() function (https://developer.mozilla.org/en-US/docs/Web/CSS/color_value/rgba)
// (allows for direct copying from Figma designs)
constexpr QColor rgba(int r, int g, int b, float alpha = 1.f) {
  return {r, g, b, qBound(0, static_cast<int>(alpha * 255), 255)};
}

class Palette : public QObject
{
  Q_OBJECT
  QML_ELEMENT
  QML_UNCREATABLE("Cannot create Palette directly")

  Q_PROPERTY(QString name READ name CONSTANT)
  Q_PROPERTY(Palette::Type type READ type CONSTANT)

  Q_PROPERTY(QColor primaryColor READ primaryColor CONSTANT)
  Q_PROPERTY(QColor successColor READ successColor CONSTANT)
  Q_PROPERTY(QColor dangerColor READ dangerColor CONSTANT)
  Q_PROPERTY(QColor transparent READ transparent CONSTANT)
  Q_PROPERTY(QColor backgroundColor READ backgroundColor CONSTANT)
  Q_PROPERTY(QColor baseColor READ baseColor CONSTANT)
  Q_PROPERTY(QColor secondaryBaseColor READ secondaryBaseColor CONSTANT)
  Q_PROPERTY(QColor textColor READ textColor CONSTANT)
  Q_PROPERTY(QColor secondaryTextColor READ secondaryTextColor CONSTANT)
  Q_PROPERTY(QVariantMap customizationColors READ customizationColors CONSTANT)
  Q_PROPERTY(QList<QColor> identiconColors READ identiconColors CONSTANT)
  Q_PROPERTY(QVariantMap networkColors READ networkColors CONSTANT)

  Q_PROPERTY(float disabledOpacity READ disabledOpacity CONSTANT)
  Q_PROPERTY(float secondaryDisabledOpacity READ secondaryDisabledOpacity CONSTANT)

 public:
  enum class Type {
    Light,
    Dark,
    System,
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
    Shade100,
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

  // common color methods
  Q_INVOKABLE QColor neutralColor(Palette::Shade shade = Palette::Shade50, float alpha = 1.f) const;
  Q_INVOKABLE inline constexpr QColor white(float alpha = 1.f) const
  {
    return {255, 255, 255, qBound(0, static_cast<int>(alpha * 255), 255)};
  }
  Q_INVOKABLE inline QColor alphaColor(const QColor& base, float alpha = 1.f) const {
    QColor color(base);
    color.setAlphaF(qBound(0.f, alpha, 1.f));
    return color;
  }

 protected:
  // helper
  static constexpr auto getColor = [](const QColor &defaultColor, const auto &container, Palette::Shade shade,
                                      float alpha = 1.f) -> QColor {
    const auto colorIt = std::find_if(std::cbegin(container), std::cend(container),
                                      [shade](const Palette::ColorPair &pair) { return shade == pair.first; });

    if (colorIt == std::cend(container))
      return defaultColor;

    if (qFuzzyCompare(alpha, 1.f))
      return colorIt->second;

    QColor color(colorIt->second);
    color.setAlphaF(qBound(0.f, alpha, 1.f));
    return color;
  };

  // theme specific color properties, to be implemented in light/dark palettes
  virtual QColor primaryColor() const = 0;
  virtual QColor successColor() const = 0;
  virtual QColor dangerColor() const = 0;

  virtual QColor backgroundColor() const = 0;
  virtual QColor baseColor() const = 0;
  virtual QColor secondaryBaseColor() const = 0;
  virtual QColor textColor() const = 0;
  virtual QColor secondaryTextColor() const = 0;
  virtual QVariantMap customizationColors() const = 0;

 private:
  // general color properties
  inline constexpr QColor transparent() const { return QColorConstants::Transparent; }
  QList<QColor> identiconColors() const;
  QVariantMap networkColors() const;

  // general palette-related properties
  inline constexpr float disabledOpacity() const { return 0.5; }
  inline constexpr float secondaryDisabledOpacity() const { return 0.2; }
};
