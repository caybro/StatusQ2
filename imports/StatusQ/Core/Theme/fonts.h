#pragma once

#include <QFont>
#include <QGuiApplication>
#include <QmlTypeAndRevisionsRegistration>

class Fonts : public QObject
{
  Q_OBJECT
  QML_ELEMENT
  QML_UNCREATABLE("Cannot create Fonts directly")

  Q_PROPERTY(QFont heading1 READ heading1 NOTIFY fontsChanged)
  Q_PROPERTY(QFont heading2 READ heading2 NOTIFY fontsChanged)
  Q_PROPERTY(QFont paragraph1 READ paragraph1 NOTIFY fontsChanged)
  Q_PROPERTY(QFont paragraph2 READ paragraph2 NOTIFY fontsChanged)
  Q_PROPERTY(QFont label1 READ label1 NOTIFY fontsChanged)
  Q_PROPERTY(QFont code READ code NOTIFY fontsChanged)

  Q_PROPERTY(QString familyName READ familyName CONSTANT)
  Q_PROPERTY(QString codeFamilyName READ codeFamilyName CONSTANT)

 public:
  explicit Fonts(QObject *parent = nullptr)
    : QObject{parent}
  {
    qApp->setFont(paragraph1()); // default app font
  };

 signals:
  void fontsChanged(); // TODO recalc fonts on app zoom change

 private:
  inline QString familyName() const { return QStringLiteral("Inter"); }

  inline QFont heading1() const
  {
    QFont result(familyName());
    result.setPixelSize(m_heading1PxSize);
    result.setLetterSpacing(QFont::PercentageSpacing, 100 - 2.1);
    return result;
  };
  int m_heading1PxSize{27};

  inline QFont heading2() const
  {
    QFont result(familyName());
    result.setPixelSize(m_heading2PxSize);
    result.setLetterSpacing(QFont::PercentageSpacing, 100 - 1.6);
    return result;
  };
  int m_heading2PxSize{19};

  inline QFont paragraph1() const
  {
    QFont result(familyName());
    result.setPixelSize(m_paragraph1PxSize);
    result.setLetterSpacing(QFont::PercentageSpacing, 100 - 0.9);
    return result;
  };
  int m_paragraph1PxSize{15};

  inline QFont paragraph2() const
  {
    QFont result(familyName());
    result.setPixelSize(m_paragraph2PxSize);
    result.setLetterSpacing(QFont::PercentageSpacing, 100 - 0.3);
    return result;
  };
  int m_paragraph2PxSize{13};

  inline QFont label1() const
  {
    QFont result(familyName());
    result.setPixelSize(m_label1PxSize);
    return result;
  };
  int m_label1PxSize{11};

  inline QString codeFamilyName() const { return QStringLiteral("Ubuntu Mono"); }
  inline QFont code() const
  {
    QFont result(codeFamilyName());
    result.setPixelSize(m_codePxSize);
    return result;
  };
  int m_codePxSize{15};
};
