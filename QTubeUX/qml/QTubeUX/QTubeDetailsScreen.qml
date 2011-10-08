import QtQuick 1.0

Rectangle {
    width: 800
    height: 600
    color: "#444444"
    border.color: "#000000"

    Rectangle {
        id: video_player
        x: 11
        y: 13
        width: 601
        height: 337
        color: "#ffffff"
    }

    ListView {
        id: related_view
        x: 623
        y: 13
        width: 172
        height: 580
        contentHeight: 580
        flickDeceleration: 1749
        spacing: 10
        clip: true
        snapMode: ListView.NoSnap
        delegate: Item {
            x: 5
            height: 120
            width: 160
            Row {
                id: row1
                spacing: 10
                QTubeThumbnail{
                    image_src: imgsrc
                    video_title_text: title
                    video_duration: duration
                    video_author: author
                    is_hd: hd
                }
            }
        }
        model: ListModel {
            ListElement {
                imgsrc: "../../../QTubeUX/images/hqdefault.1.jpg"
                title: "Item 1"
                duration: "01:01"
                author: "Moi"
                hd: true
            }

            ListElement {
                imgsrc: "../../../QTubeUX/images/hqdefault.2.jpg"
                title: "Item 2"
                duration: "01:01"
                author: "Moi"
                hd: true
            }
            ListElement {
                imgsrc: "../../../QTubeUX/images/hqdefault.1.jpg"
                title: "Item 3"
                duration: "01:01"
                author: "Moi"
                hd: false
            }
            ListElement {
                imgsrc: "../../../QTubeUX/images/hqdefault.2.jpg"
                title: "Item 4"
                duration: "01:01"
                author: "Moi"
                hd: false
            }
            ListElement {
                imgsrc: "../../../QTubeUX/images/hqdefault.1.jpg"
                title: "Item 1"
                duration: "01:01"
                author: "Moi"
                hd: true
            }

            ListElement {
                imgsrc: "../../../QTubeUX/images/hqdefault.2.jpg"
                title: "Item 2"
                duration: "01:01"
                author: "Moi"
                hd: true
            }
            ListElement {
                imgsrc: "../../../QTubeUX/images/hqdefault.1.jpg"
                title: "Item 3"
                duration: "01:01"
                author: "Moi"
                hd: false
            }
            ListElement {
                imgsrc: "../../../QTubeUX/images/hqdefault.2.jpg"
                title: "Item 4"
                duration: "01:01"
                author: "Moi"
                hd: false
            }
        }
    }
}
