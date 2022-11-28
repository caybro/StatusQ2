import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Core.Theme 1.0

Pane {
    id: root

    ColumnLayout {
        width: parent.width
        TextField {
            placeholderText: "Edit me placeholder"
        }
        TextField {
            text: "This is actual text"
        }
        TextField {
            enabled: false
            text: "Disabled Text Field"
        }
        TextField {
            readOnly: true
            text: "Readonly Text Field"
        }
        TextField {
            type: TextField.Type.Success
            placeholderText: "Success :)"
        }
        TextField {
            type: TextField.Type.Danger
            placeholderText: "Danger!"
        }
    }
}
