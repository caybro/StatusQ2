import QtQuick 2.15
import QtQuick.Templates 2.15 as T

import StatusQ.Core.Theme 1.0

T.AbstractButton {
    implicitWidth: Math.max(implicitBackgroundWidth + leftInset + rightInset,
                            implicitContentWidth + horizontalPadding)
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             implicitContentHeight + verticalPadding)

    padding: 2
    spacing: 4
    opacity: enabled ? 1 : Theme.palette.disabledOpacity
}
