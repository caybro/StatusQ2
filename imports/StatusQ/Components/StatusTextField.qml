import QtQuick 2.14
import QtQuick.Controls 2.14

import StatusQ.Core.Theme 1.0

TextField {
    id: root
    leftPadding: 16
    rightPadding: 16
    topPadding: 8
    bottomPadding: 8
    opacity: enabled ? 1 : Theme.palette.secondaryDisabledOpacity
    color: Theme.palette.textColor
    placeholderTextColor: Theme.palette.secondaryTextColor
    selectionColor: Theme.palette.primaryColor()
    selectedTextColor: Theme.palette.white()
    selectByMouse: true

    font.weight: Font.Medium

    property int spacing: 8

    enum Type {
        Normal,
        Active,
        Success,
        Warning,
        Danger
    }
    property int type: StatusTextField.Type.Normal

    background: Rectangle {
        implicitWidth: height*10
        height: root.height
        radius: 20 // FIXME calculate it
        color: Theme.palette.secondaryBaseColor
        border.width: 2
        border.color: {
            if (root.type === StatusTextField.Type.Success) {
                return Theme.palette.successColor()
            } else if (root.type === StatusTextField.Type.Warning) {
                return Theme.palette.warningColor()
            } else if (root.type === StatusTextField.Type.Danger) {
                return Theme.palette.dangerColor()
            } else if (root.focus || root.type === StatusTextField.Type.Active) {
                return Theme.palette.primaryColor()
            }

            return "transparent"
        }
        Behavior on border.color { ColorAnimation { duration: 50 } }
    }
}
