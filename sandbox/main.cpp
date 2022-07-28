#include <QDebug>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
  QGuiApplication app(argc, argv);

  app.setOrganizationName(QStringLiteral("Status"));
  app.setOrganizationDomain(QStringLiteral("status.im"));
  app.setApplicationDisplayName(QStringLiteral("StatusQ Sandbox"));
  app.setApplicationVersion(QStringLiteral("0.1"));

  qputenv("QT_QUICK_CONTROLS_HOVER_ENABLED", QByteArrayLiteral("1"));

  QQmlApplicationEngine engine;
  engine.addImportPath(app.applicationDirPath() + QStringLiteral("/../imports/"));
  engine.addImportPath(QStringLiteral("qrc:/"));
  qWarning() << "Import paths:" << engine.importPathList();

  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(EXIT_FAILURE);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
