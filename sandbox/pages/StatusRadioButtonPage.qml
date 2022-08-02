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

        RadioButton {
            text: "Unchecked radio"
        }
        RadioButton {
            checked: true
            text: "Checked radio"
        }
        RadioButton {
            enabled: false
            text: "Unchecked radio/disabled"
        }
        RadioButton {
            enabled: false
            checked: true
            text: "Checked radio/disabled"
        }
    }
}
