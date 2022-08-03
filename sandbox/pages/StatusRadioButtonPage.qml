import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Core.Theme 1.0

Pane {
    id: root

    ColumnLayout {
        width: parent.width

        RadioButton {
        }
        RadioButton {
            text: "Unchecked radio"
        }
        RadioButton {
            checked: true
            text: "Checked radio"
        }
        RadioButton {
            enabled: false
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
