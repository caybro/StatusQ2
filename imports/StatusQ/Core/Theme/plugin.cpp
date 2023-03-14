#include <QFontDatabase>
#include <QQmlEngineExtensionPlugin>

class StatusThemePlugin : public QQmlEngineExtensionPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)

  void initializeEngine(QQmlEngine *engine, const char *uri) override
  {
    QQmlEngineExtensionPlugin::initializeEngine(engine, uri);

    // load & setup default font
    for (const auto &name : {"Inter-BlackItalic.otf", "Inter-Bold.otf", "Inter-ExtraLightItalic.otf",
                             "Inter-LightItalic.otf", "Inter-Medium.otf", "Inter-SemiBold.otf", "Inter-Black.otf",
                             "Inter-ExtraBoldItalic.otf", "Inter-ExtraLight.otf", "Inter-Light.otf", "Inter-Regular.otf",
                             "Inter-ThinItalic.otf", "Inter-BoldItalic.otf", "Inter-ExtraBold.otf", "Inter-Italic.otf",
                             "Inter-MediumItalic.otf", "Inter-SemiBoldItalic.otf", "Inter-Thin.otf"}) {
      QFontDatabase::addApplicationFont(QStringLiteral(":/assets/fonts/Inter/%1").arg(name));
    }

    for (const auto &name :
         {"UbuntuMono-BoldItalic.ttf", "UbuntuMono-Bold.ttf", "UbuntuMono-Italic.ttf", "UbuntuMono-Regular.ttf"}) {
      QFontDatabase::addApplicationFont(QStringLiteral(":/assets/fonts/UbuntuMono/%1").arg(name));
    }
  }
};

#include "plugin.moc"
