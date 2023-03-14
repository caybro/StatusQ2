import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Core.Theme 1.0

Pane {
    id: root

    readonly property string specimen: "The quick brown fox jumped over the lazy dog. 0123456789 .:,;(*!?')"

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

        Label {
            Layout.topMargin: Theme.metrics.padding
            text: "Heading 1"
        }
        Label {
            font: Theme.fonts.heading1
            text: root.specimen
        }

        Label {
            Layout.topMargin: Theme.metrics.padding
            text: "Heading 2"
        }
        Label {
            font: Theme.fonts.heading2
            text: root.specimen
        }

        Label {
            Layout.topMargin: Theme.metrics.padding
            text: "Paragraph 1"
        }
        Label {
            font: Theme.fonts.paragraph1
            text: root.specimen
        }

        Label {
            Layout.topMargin: Theme.metrics.padding
            text: "Paragraph 2"
        }
        Label {
            font: Theme.fonts.paragraph2
            text: root.specimen
        }

        Label {
            Layout.topMargin: Theme.metrics.padding
            text: "Label 1"
        }
        Label {
            font: Theme.fonts.label1
            text: root.specimen
        }

        Label {
            Layout.topMargin: Theme.metrics.padding
            text: "Code 15"
        }
        Label {
            font: Theme.fonts.code
            text: root.specimen
        }

        Label {
            Layout.topMargin: Theme.metrics.padding
            text: "Code 13"
        }
        Label {
            font.family: Theme.fonts.codeFamilyName
            font.pixelSize: 13
            text: root.specimen
        }
    }
}
