import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.impl 2.14 // for ColorImage

import StatusQ.Core.Theme 1.0

CheckBox {
    id: root
    padding: 2
    spacing: 2
    opacity: enabled ? 1 : Theme.palette.disabledOpacity

    indicator: Rectangle {
        height: root.height
        width: height
        radius: width/2
        anchors.verticalCenter: parent.verticalCenter
        color: root.checkState === Qt.Unchecked ? Theme.palette.baseColor
                                                : Theme.palette.primaryColor()
        Behavior on color { ColorAnimation { duration: 50 } }

        // FIXME make a StatusIcon component out of ColorImage ;)
        ColorImage {
            anchors.centerIn: parent
            sourceSize: Qt.size(8,6)
            source: "qrc:/assets/icons/Checkmark.svg"
            visible: root.checked
            color: Theme.palette.backgroundColor
        }

        ColorImage {
            anchors.centerIn: parent
            sourceSize: Qt.size(8,2)
            source: "qrc:/assets/icons/Indeterminate.svg"
            visible: root.checkState === Qt.PartiallyChecked
            color: Theme.palette.backgroundColor
        }
    }

    contentItem: StatusLabel {
        text: root.text
        font: root.font
        leftPadding: root.mirrored ? 0 : root.indicator.width + root.spacing
        rightPadding: root.mirrored ? root.indicator.width + root.spacing : 0
    }
}
