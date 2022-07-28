import QtQuick 2.15
import QtQuick.Controls 2.15

import StatusQ.Core.Theme 1.0

Label {
    color: Theme.palette.textColor
    opacity: enabled ? 1 : Theme.palette.disabledOpacity
    linkColor: hoveredLink ? Theme.palette.primaryColor(Palette.Shade60) : Theme.palette.primaryColor()
    verticalAlignment: Text.AlignVCenter

    onLinkActivated: {
        if (link)
            Qt.openUrlExternally(link)
    }

    HoverHandler {
        id: hoverHandler
        cursorShape: parent.hoveredLink ? Qt.PointingHandCursor : undefined
    }
}
