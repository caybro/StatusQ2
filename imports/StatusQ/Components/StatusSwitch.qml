import QtQuick 2.14
import QtQuick.Controls 2.14

import StatusQ.Core.Theme 1.0

Switch {
    id: root
    padding: 2
    spacing: 2
    opacity: enabled ? 1 : Theme.palette.disabledOpacity

    readonly property int gap: 2

    indicator: Rectangle {
        height: root.height
        width: root.height*2 - root.gap*2
        radius: height/2
        anchors.verticalCenter: parent.verticalCenter
        color: root.checked ? Theme.palette.primaryColor() : Theme.palette.baseColor
        Behavior on color { ColorAnimation { duration: 50 } }

        Rectangle {
            width: parent.width/2 - root.gap
            height: width
            x: root.visualPosition * (parent.width - width) + (root.checked ? -root.gap : root.gap)
            Behavior on x { PropertyAnimation { duration: 100 } }
            anchors.verticalCenter: parent.verticalCenter
            radius: width/2
            color: Theme.palette.white()
        }
    }

    contentItem: StatusLabel {
        text: root.text
        font: root.font
        leftPadding: root.mirrored ? 0 : root.indicator.width + root.spacing
        rightPadding: root.mirrored ? root.indicator.width + root.spacing : 0
    }
}
