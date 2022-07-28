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

        StatusLabel {
            text: "Plain text label"
        }
        StatusLabel {
            enabled: false
            text: "Disabled plain text label"
        }
        StatusLabel {
             text: "<b>Bold</b> <i>italic</i> <u>underline</u>"
        }
        StatusLabel {
             text: "With a <a href='https://status.im'>hypertext link</a>"
        }
    }
}
