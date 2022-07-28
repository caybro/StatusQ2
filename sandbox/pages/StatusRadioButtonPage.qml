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

        StatusRadioButton {
            checked: true
            text: "Checked radio"
        }
        StatusRadioButton {
            text: "Unchecked radio"
        }
        StatusRadioButton {
            enabled: false
            text: "Unchecked radio/disabled"
        }
        StatusRadioButton {
            enabled: false
            checked: true
            text: "Checked radio/disabled"
        }
    }
}
