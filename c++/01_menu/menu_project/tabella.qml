import QtQuick 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2

ApplicationWindow {
    id: window
    visible: true
    title: "Table View"

    toolBar: ToolBar {
        TextField {
            id: searchBox

            placeholderText: "Search..."
            inputMethodHints: Qt.ImhNoPredictiveText

            width: window.width / 5 * 2
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    TableView {
        id: tableView

        frameVisible: false
        sortIndicatorVisible: true

        anchors.fill: parent

        Layout.minimumWidth: 400
        Layout.minimumHeight: 240
        Layout.preferredWidth: 800
        Layout.preferredHeight: 600

        TableViewColumn {
            id: titleColumn
            title: "Nome e Cognome"
            role: "nome"
            movable: false
            resizable: true
            width: tableView.viewport.width / 2
        }

        TableViewColumn {
            id: chatID
            title: "ChatID"
            role: "chatid"
            movable: false
            resizable: true
            width: tableView.viewport.width / 3
        }

        TableViewColumn {
            id: authorColumn
            title: "Covid"
            role: "covid"
            movable: false
            resizable: true
            width: tableView.viewport.width / 3
        }

        //questo serve per la searchbox
        /*model: SortFilterProxyModel {
            id: proxyModel
            source: sourceModel.count > 0 ? sourceModel : null

            sortOrder: tableView.sortIndicatorOrder
            sortCaseSensitivity: Qt.CaseInsensitive
            sortRole: sourceModel.count > 0 ? tableView.getColumn(tableView.sortIndicatorColumn).role : ""

            filterString: "*" + searchBox.text + "*"
            filterSyntax: SortFilterProxyModel.Wildcard
            filterCaseSensitivity: Qt.CaseInsensitive*/
        }
    }
}
