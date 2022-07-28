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
        StatusTextField {
            placeholderText: "Edit me"
        }
        StatusTextField {
            enabled: false
            text: "Disabled Text Field"
        }
        StatusTextField {
            type: StatusTextField.Type.Success
            placeholderText: "Success!!!"
        }
        StatusTextField {
            type: StatusTextField.Type.Warning
            placeholderText: "Warning!!!"
        }
    }
}
