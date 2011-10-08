import QtQuick 1.0

Rectangle {
    width: 360
    height: 360
    QTubeThumbnail{
        id: v1
        video_title_text: "2 boarders in a bot !"
        video_duration: "02:54"
        video_author: "GenYale boarder"
        is_hd: true
            image_src: "../../../QTubeUX/images/hqdefault.2.jpg"
        }
     QTubeThumbnail{
         id: v2
         x: 180
         y: 0

        }
}
