import QtQuick 2.15
import QtQuick.Templates 2.15 as T

import StatusQ.Core.Theme 1.0

T.Label {
    opacity: enabled ? 1 : Theme.palette.disabledOpacity
    color: Theme.palette.textColor
    linkColor: hoveredLink ? Qt.lighter(Theme.palette.primaryColor, 1.3) : Theme.palette.primaryColor // FIXME provide a universal Theme.hoverColor(color)
    verticalAlignment: Text.AlignVCenter

    onLinkActivated: if (link) Qt.openUrlExternally(link)

    HoverHandler {
        cursorShape: parent.hoveredLink ? Qt.PointingHandCursor : undefined
    }
}
