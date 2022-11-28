#pragma once

#include <QObject>
#include <QmlTypeAndRevisionsRegistration>

class Metrics : public QObject
{
  Q_OBJECT
  QML_ELEMENT
  QML_UNCREATABLE("Cannot create Metrics directly")

  Q_PROPERTY(int xlPadding READ xlPadding NOTIFY metricsChanged)
  Q_PROPERTY(int bigPadding READ bigPadding NOTIFY metricsChanged)
  Q_PROPERTY(int padding READ padding NOTIFY metricsChanged)
  Q_PROPERTY(int halfPadding READ halfPadding NOTIFY metricsChanged)
  Q_PROPERTY(int smallPadding READ smallPadding NOTIFY metricsChanged)
  Q_PROPERTY(int tinyPadding READ tinyPadding NOTIFY metricsChanged)

  Q_PROPERTY(int controlSpacing READ controlSpacing NOTIFY metricsChanged)

 public:
  explicit Metrics(QObject *parent = nullptr);

 signals:
  void metricsChanged(); // TODO recalc metrics on app zoom change

 private:
  constexpr inline int xlPadding() const { return m_xlPadding; };
  int m_xlPadding{32};
  constexpr inline int bigPadding() const { return m_bigPadding; };
  int m_bigPadding{24};
  constexpr inline int padding() const { return m_padding; };
  int m_padding{16};
  constexpr inline int halfPadding() const { return m_halfPadding; };
  int m_halfPadding{8};
  constexpr inline int smallPadding() const { return m_smallPadding; };
  int m_smallPadding{6};
  constexpr inline int tinyPadding() const { return m_tinyPadding; };
  int m_tinyPadding{2};

  constexpr inline int controlSpacing() const { return m_controlSpacing; };
  int m_controlSpacing{4};
};
