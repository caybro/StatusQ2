import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Templates 2.15 as T

import StatusQ.Core.Theme 1.0

T.TextField {
    id: root

    implicitWidth: implicitBackgroundWidth + leftInset + rightInset
                   || Math.max(contentWidth, placeholder.implicitWidth) + leftPadding + rightPadding
    implicitHeight: Math.max(implicitBackgroundHeight + topInset + bottomInset,
                             contentHeight + topPadding + bottomPadding,
                             placeholder.implicitHeight + topPadding + bottomPadding)

    leftPadding: Theme.metrics.padding
    rightPadding: Theme.metrics.padding
    topPadding: Theme.metrics.halfPadding
    bottomPadding: Theme.metrics.halfPadding
    opacity: enabled ? 1 : Theme.palette.secondaryDisabledOpacity
    color: Theme.palette.textColor
    placeholderTextColor: Theme.palette.secondaryTextColor
    selectionColor: Theme.palette.primaryColor
    selectedTextColor: Theme.palette.white()
    selectByMouse: true

    font.weight: Font.Medium

    enum Type {
        Normal,
        Active,
        Success,
        Danger
    }
    property int type: TextField.Type.Normal // FIXME remove me

    Label {
        id: placeholder
        x: root.leftPadding
        y: root.topPadding
        width: root.width - (root.leftPadding + root.rightPadding)
        height: root.height - (root.topPadding + root.bottomPadding)
        text: root.placeholderText
        font: root.font
        color: root.placeholderTextColor
        verticalAlignment: root.verticalAlignment
        elide: Text.ElideRight
        renderType: root.renderType
        visible: !root.length && !root.preeditText && (!root.activeFocus || root.horizontalAlignment !== Qt.AlignHCenter)
    }

    background: Rectangle {
        implicitWidth: height*10
        height: root.height
        radius: 12 // FIXME calculate it
        //color: Theme.palette.secondaryBaseColor
        border.width: 1
        border.color: {
            if (root.type === TextField.Type.Success) {
                return Theme.palette.successColor
            } else if (root.type === TextField.Type.Danger) {
                return Theme.palette.dangerColor
            } else if (root.type === TextField.Type.Active) {
                return Theme.palette.primaryColor
            }

            if (root.focus)
                return Theme.palette.baseColor

            return Theme.palette.secondaryBaseColor
        }
        Behavior on border.color { ColorAnimation { duration: 50 } }
    }
}
