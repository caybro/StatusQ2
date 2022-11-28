import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Components 1.0
import StatusQ.Core.Theme 1.0

Pane {
    id: root

    GridLayout {
        columns: 5
        width: parent.width

        Repeater {
            model: [StatusTag.Type.Normal, StatusTag.Type.Primary, StatusTag.Type.Success, StatusTag.Type.Error]
            ColumnLayout {
                width: parent.width

                StatusTag {
                    size: StatusTag.Size.TwentyFourPx
                    prefix: "Prefix"
                    text: "Label"
                    removable: true
                    type: modelData
                }

                StatusTag {
                    icon.name: "Close"
                    icon.color: "green"
                    prefix: "Prefix"
                    text: "Green icon"
                    removable: true
                    type: modelData
                }

                StatusTag {
                    enabled: false
                    size: StatusTag.Size.TwentyFourPx
                    prefix: "Prefix"
                    text: "Label"
                    removable: true
                    type: modelData
                }

                StatusTag {
                    prefix: "Prefix"
                    text: "Label"
                    removable: true
                    type: modelData
                }

                StatusTag {
                    size: StatusTag.Size.TwentyFourPx
                    prefix: "Prefix"
                    text: "Label"
                    type: modelData
                }

                StatusTag {
                    prefix: "Prefix"
                    text: "Label"
                    type: modelData
                }

                StatusTag {
                    size: StatusTag.Size.TwentyFourPx
                    prefix: "Prefix"
                    type: modelData
                }

                StatusTag {
                    prefix: "Prefix"
                    type: modelData
                }

                StatusTag {
                    size: StatusTag.Size.TwentyFourPx
                    text: "Label"
                    type: modelData
                }

                StatusTag {
                    text: "Label"
                    type: modelData
                }
            }
        }
    }
}
