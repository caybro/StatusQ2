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
        TextField {
            placeholderText: "Edit me"
        }
        TextField {
            enabled: false
            text: "Disabled Text Field"
        }
        TextField {
            type: TextField.Type.Success
            placeholderText: "Success!!!"
        }
        TextField {
            type: TextField.Type.Warning
            placeholderText: "Warning!!!"
        }
    }
}
