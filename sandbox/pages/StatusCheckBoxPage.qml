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

        CheckBox {
            //Layout.preferredHeight: 70
            text: "Unchecked"
        }
        CheckBox {
            tristate: true
            checkState: Qt.PartiallyChecked
            text: "Tristate"
        }
        CheckBox {
            checked: true
            text: "Checked"
        }

        CheckBox {
            enabled: false
            text: "Unchecked/disabled"
        }
        CheckBox {
            enabled: false
            tristate: true
            checkState: Qt.PartiallyChecked
            text: "Tristate/disabled"
        }
        CheckBox {
            enabled: false
            checked: true
            text: "Checked/disabled"
        }
    }
}
