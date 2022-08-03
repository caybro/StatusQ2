import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Core.Theme 1.0

Pane {
    id: root

    ColumnLayout {
        width: parent.width

        Label {
            text: "Plain text label"
        }
        Label {
            enabled: false
            text: "Disabled plain text label"
        }
        Label {
             text: "<b>Bold</b> <i>italic</i> <u>underline</u>"
        }
        Label {
             text: "With a <a href='https://status.im'>hypertext link</a>"
        }
    }
}
