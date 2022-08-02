import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Core.Theme 1.0

Pane {
    id: root

    background: Rectangle {
        color: Theme.palette.backgroundColor
        Behavior on color { ColorAnimation { duration: 50 } }
    }

    ColumnLayout {
        width: parent.width

        Switch {
            text: "Switch control, unchecked"
        }
        Switch {
            checked: true
            text: "Switch control, checked"
        }
        Switch {
            enabled: false
            text: "Switch control, unchecked, disabled"
        }
        Switch {
            checked: true
            enabled: false
            text: "Switch control, checked, disabled"
        }
    }
}
