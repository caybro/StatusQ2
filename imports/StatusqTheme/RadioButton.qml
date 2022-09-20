import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as T

import StatusQ.Core.Theme 1.0

T.RadioButton {
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
        width: height
        radius: width/2
        anchors.verticalCenter: parent.verticalCenter
        color: root.checked ? Theme.palette.primaryColor()
                            : Theme.palette.baseColor
        Behavior on color { ColorAnimation { duration: 50 } }

        Rectangle {
            width: height
            height: (parent.height/4).toFixed(0) // try hard to keep it in the real center, avoid rounding errors
            radius: width/2
            anchors.centerIn: parent
            color: Theme.palette.backgroundColor
            opacity: root.checked ? 1 : 0
            visible: opacity
            Behavior on opacity { NumberAnimation { duration: 50 } }
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
