import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.impl 2.15 // for ColorImage
import QtQuick.Templates 2.15 as T

import StatusQ.Core.Theme 1.0

T.CheckBox {
    id: root

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + horizontalPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + verticalPadding,
                             implicitIndicatorHeight + verticalPadding)

    padding: 2
    spacing: 4
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
            visible: root.checkState === Qt.Checked
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

    contentItem: Label {
        text: root.text
        font: root.font
        leftPadding: root.mirrored ? 0 : root.indicator.width + root.spacing
        rightPadding: root.mirrored ? root.indicator.width + root.spacing : 0
    }
}
