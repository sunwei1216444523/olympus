// Copyright (C) 2023 Olympus Corporation. All rights reserved.

#ifndef EDGE_H
#define EDGE_H

namespace athena {
    enum class TurnDirection {
        kForward = 0,
        kRevease = 1,
        kGoLeft = 2,
        kGoRight = 3,
    }

    struct Edge {
        bool isLaneChange;
        // 在这里添加其他的字段

        /** 假设A能到B，但是B不能到A，即：AB之间单向通行
            NodeA                NodeB
            |--------Edge1----------->|
            |<-------Edge2---X--------|
            Edge1:
                forwardAccess = true
                reverseAccess = false
            Edge2:
                forwardAccess = false
                reverseAccess = true
        bi-direction search 的时候，正向扩展的就只有forwardAccess = true的边
        反向扩展的就只有reverseAccess = true的边
        */
        // bool forwardDirection; // 这里不区分forward，因为没有意义，单纯就是看谁先被遍历而已
        bool forwardAccess = false;     // 正向是否可通行，这个和forward没关系
        bool reverseAccess = false;     // 反向是否可通行，其实就是表示opposite的edge是否可通行
    };
}

#endif // EDGE_H