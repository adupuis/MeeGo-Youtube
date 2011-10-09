/*************************************************************************
 *
 * Copyright (c) 2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 1.0

Rectangle {
    width: 1366
    height: 768
    color: "black"
    PathView {
        id: view
        focus: true
        width: parent.width
        height: parent.height + y
        y: -100
        model: Menu7 {}
//        delegate: Image {
//            source: iconSource
//            width: 64
//            height: 64
//            scale: 4. * y / parent.height
//            z: y
//            smooth: true
//            opacity: scale / 3.
//        }
        delegate: QTubeThumbnail {
            scale: 4* (x / view.width / 2)
            image_src: src1
            video_title_text: text1
            video_duration: duration1
            video_author: author1
            is_hd: hd1
        }
        path: Ellipse7 {
            width: view.width
            height: view.height
        }
        preferredHighlightBegin: 0
        preferredHighlightEnd: 0
        highlightRangeMode: PathView.StrictlyEnforceRange
        Keys.onLeftPressed: decrementCurrentIndex()
        Keys.onRightPressed: incrementCurrentIndex()
    }
//    Text {
//        id: label
//        text: view.model.title(view.currentIndex)
//        color: "paleturquoise"
//        font.pixelSize: 16
//        font.bold: true
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.bottom: parent.bottom
//    }
}
