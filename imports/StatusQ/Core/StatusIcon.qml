import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.impl 2.15 // for ColorImage

import StatusQ.Core.Theme 1.0

ColorImage {
    property string icon
    property bool small

    source: icon ? "qrc:/assets/icons/%1/%2.svg".arg(small ? "small" : "").arg(icon) : ""
    width: small ? 16 : 20
    height: small ? 16 : 20
    sourceSize: source.toString().endsWith(".svg") ? Qt.size(width, height) : undefined
    Behavior on color { ColorAnimation { duration: 50 } }
}
