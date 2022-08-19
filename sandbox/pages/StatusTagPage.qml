import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Components 1.0
import StatusQ.Core.Theme 1.0

Pane {
    id: root

    ColumnLayout {
        width: parent.width

        StatusTag {
            size: StatusTag.Size.TwentyFourPx
            prefix: "Prefix"
            text: "Label"
            removable: true
        }

        StatusTag {
            icon.name: "Close"
            icon.color: "green"
            prefix: "Prefix"
            text: "Label"
            removable: true
        }

        StatusTag {
            enabled: false
            size: StatusTag.Size.TwentyFourPx
            prefix: "Prefix"
            text: "Label"
            removable: true
        }

        StatusTag {
            prefix: "Prefix"
            text: "Label"
            removable: true
        }

        StatusTag {
            size: StatusTag.Size.TwentyFourPx
            prefix: "Prefix"
            text: "Label"
        }

        StatusTag {
            prefix: "Prefix"
            text: "Label"
        }

        StatusTag {
            size: StatusTag.Size.TwentyFourPx
            prefix: "Prefix"
        }

        StatusTag {
            prefix: "Prefix"
        }

        StatusTag {
            size: StatusTag.Size.TwentyFourPx
            text: "Label"
        }

        StatusTag {
            text: "Label"
        }
    }
}
