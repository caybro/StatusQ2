import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as T

import StatusQ.Core 1.0
import StatusQ.Core.Theme 1.0

T.CheckBox {
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
        color: root.checkState === Qt.Unchecked ? Theme.palette.baseColor
                                                : Theme.palette.primaryColor()
        Behavior on color { ColorAnimation { duration: 50 } }

        StatusIcon {
            anchors.centerIn: parent
            small: true
            icon: "Checkmark"
            visible: root.checkState === Qt.Checked
            color: Theme.palette.backgroundColor
        }

        StatusIcon {
            anchors.centerIn: parent
            width: 8
            height: 2
            small: true
            icon: "Indeterminate"
            visible: root.checkState === Qt.PartiallyChecked
            color: Theme.palette.backgroundColor
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
