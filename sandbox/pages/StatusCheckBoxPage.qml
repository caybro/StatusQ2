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

        StatusCheckBox {
            //Layout.preferredHeight: 70
            text: "Unchecked"
        }
        StatusCheckBox {
            tristate: true
            text: "Tristate"
        }
        StatusCheckBox {
            checked: true
            text: "Checked"
        }

        StatusCheckBox {
            enabled: false
            text: "Unchecked/disabled"
        }
        StatusCheckBox {
            enabled: false
            tristate: true
            text: "Tristate/disabled"
        }
        StatusCheckBox {
            enabled: false
            checked: true
            text: "Checked/disabled"
        }
    }
}
