import QtQuick 2.14
import QtQuick.Controls 2.14

import StatusQ.Core.Theme 1.0

RadioButton {
    id: root
    padding: 2
    spacing: 4
    opacity: enabled ? 1 : Theme.palette.disabledOpacity

    indicator: Rectangle {
        height: root.height
        width: height
        radius: width/2
        anchors.verticalCenter: parent.verticalCenter
        color: root.checked ? Theme.palette.primaryColor()
                            : Theme.palette.baseColor
        Behavior on color { ColorAnimation { duration: 50 } }

        Rectangle {
            width: parent.width/4
            height: width
            radius: width/2
            anchors.centerIn: parent
            color: Theme.palette.backgroundColor
            opacity: root.checked ? 1 : 0
            visible: opacity
            Behavior on opacity { NumberAnimation { duration: 50 } }
        }
    }

    contentItem: StatusLabel {
        text: root.text
        font: root.font
        leftPadding: root.mirrored ? 0 : root.indicator.width + root.spacing
        rightPadding: root.mirrored ? root.indicator.width + root.spacing : 0
    }
}
