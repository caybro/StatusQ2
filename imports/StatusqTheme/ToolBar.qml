import QtQuick 2.15
import QtQuick.Templates 2.15 as T

import StatusQ.Core.Theme 1.0

T.ToolBar {
    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            contentWidth + horizontalPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             contentHeight + verticalPadding)

    horizontalPadding: 8
    verticalPadding: 0

    background: Rectangle {
        color: Theme.palette.baseColor
        Behavior on color { ColorAnimation { duration: 50 } }
    }
}
