import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import Qt.labs.folderlistmodel 2.15

import StatusQ.Components 1.0
import StatusQ.Core.Theme 1.0

ApplicationWindow {
    id: root
    width: 1024
    height: 768
    visible: true
    title: qsTr("StatusQ2 Sandbox")

    color: Theme.palette.backgroundColor
    Behavior on color { ColorAnimation { duration: 50 } }

    FolderListModel {
        id: folderModel
        folder: "qrc:/pages"
        nameFilters: ["*.qml"]
        showDirs: false
        showDotAndDotDot: false
        sortField: FolderListModel.Name
    }

    header: ToolBar {
        id: toolbar
        leftPadding: 8
        background: Rectangle {
            color: Theme.palette.baseColor
            Behavior on color { ColorAnimation { duration: 50 } }
        }

        contentItem: RowLayout {
            RowLayout {
                Layout.alignment: Qt.AlignLeft
                StatusSwitch {
                    id: themeSwitch
                    checked: Theme.type === Palette.Type.Dark
                    text: checked ? "Dark" : "Light"
                    onToggled: Theme.type = checked ? Palette.Type.Dark : Palette.Type.Light
                    ToolTip.text: "Current theme: %1".arg(Theme.palette.name)
                    ToolTip.visible: themeSwitch.hovered
                }
                StatusLabel {
                    enabled: false
                    text: "(bg color: %1)".arg(Theme.palette.backgroundColor)
                }
            }
            StatusLabel {
                anchors.centerIn: parent
                font.bold: true
                text: pagesListView.currentItem ? folderModel.get(pagesListView.currentIndex, "fileBaseName") : ""
            }
            ToolButton {
                Layout.alignment: Qt.AlignRight
                text: qsTr("⋮")
                onClicked: drawer.visible ? drawer.close() : drawer.open()
            }
        }
    }

    Drawer {
        id: drawer
        edge: Qt.RightEdge
        width: 0.4 * parent.width
        y: toolbar.height
        height: parent.height - y
        background: Rectangle {
            color: Theme.palette.backgroundColor
            Behavior on color { ColorAnimation { duration: 50 } }
        }

        ListView {
            id: pagesListView
            anchors.fill: parent
            anchors.margins: 8
            model: folderModel
            currentIndex: -1

            delegate: ItemDelegate {
                width: ListView.view.width
                text: model.fileBaseName
                highlighted: ListView.isCurrentItem
                font.bold: highlighted
                onClicked: {
                    if (index !== ListView.view.currentIndex) {
                        ListView.view.currentIndex = index
                        stack.push("qrc" + model.filePath)
                    }
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stack
        anchors.fill: parent
        background: Rectangle {
            color: Theme.palette.backgroundColor
            Behavior on color { ColorAnimation { duration: 50 } }
        }
        initialItem: StatusLabel {
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 32
            font.weight: Font.DemiBold
            text: "Welcome to StatusQ Sandbox<br><font size='-2'>Choose the page from the menu in the upper right corner</font>"
        }
    }
}
