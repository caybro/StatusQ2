import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as T

import StatusQ.Core.Theme 1.0

T.Switch {
    id: root

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + horizontalPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + verticalPadding,
                             implicitIndicatorHeight + verticalPadding)

    padding: Theme.metrics.tinyPadding
    spacing: Theme.metrics.controlSpacing
    opacity: enabled ? 1 : Theme.palette.disabledOpacity

    indicator: Rectangle {
        height: root.height
        width: root.height*2 - Theme.metrics.tinyPadding*2
        radius: height/2
        anchors.verticalCenter: parent.verticalCenter
        color: root.checked ? Theme.palette.primaryColor : Theme.palette.secondaryBaseColor
        Behavior on color { ColorAnimation { duration: 50 } }

        Rectangle {
            width: parent.width/2 - Theme.metrics.tinyPadding
            height: width
            x: root.visualPosition * (parent.width - width) + (root.checked ? -Theme.metrics.tinyPadding : Theme.metrics.tinyPadding)
            Behavior on x { PropertyAnimation { duration: 100 } }
            anchors.verticalCenter: parent.verticalCenter
            radius: width/2
            color: Theme.palette.white()
        }
    }

    contentItem: Label {
        text: root.text
        font: root.font
        leftPadding: root.mirrored ? 0 : root.indicator.width + root.spacing
        rightPadding: root.mirrored ? root.indicator.width + root.spacing : 0
    }

    HoverHandler {
        cursorShape: parent.hovered ? Qt.PointingHandCursor : undefined
    }
}
