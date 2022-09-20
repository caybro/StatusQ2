import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as T

import StatusQ.Core.Theme 1.0

T.ItemDelegate {
    id: root

    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + horizontalPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + verticalPadding,
                             implicitIndicatorHeight + verticalPadding)

    padding: Theme.metrics.smallPadding
    spacing: Theme.metrics.halfPadding

    icon.width: 20
    icon.height: 20
    icon.color: Theme.palette.textColor

    contentItem: Label {
        rightPadding: root.spacing
        text: root.text
        font: root.font
    }

    background: Rectangle {
        implicitWidth: 100
        implicitHeight: 40
        visible: root.down || root.highlighted || root.visualFocus
        color: Theme.palette.baseColor
    }

    HoverHandler {
        cursorShape: parent.hovered ? Qt.PointingHandCursor : undefined
    }
}
