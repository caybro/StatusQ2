import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Pane {
    id: root

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
