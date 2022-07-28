import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Components 1.0
import StatusQ.Core.Theme 1.0

Pane {
    id: root

    background: Rectangle {
        color: Theme.palette.backgroundColor
        Behavior on color { ColorAnimation { duration: 50 } }
    }

    ColumnLayout {
        width: parent.width

        StatusSwitch {
            text: "Switch control, unchecked"
        }
        StatusSwitch {
            checked: true
            text: "Switch control, checked"
        }
        StatusSwitch {
            enabled: false
            text: "Switch control, unchecked, disabled"
        }
        StatusSwitch {
            checked: true
            enabled: false
            text: "Switch control, checked, disabled"
        }
    }
}
