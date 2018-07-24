background = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 1500,
        size_y = 768,
        texture = "BACKGROUND",
        layer = "BACK",
        repeated = true;
    }
}

box = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "BOX",
        layer = "BACK",
        repeated = false;
    }
}

cloud_1 = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 128,
        size_y = 71,
        texture = "CLOUD_1",
        layer = "BACK",
        repeated = false;
    }
}

cloud_2 = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 129,
        size_y = 71,
        texture = "CLOUD_2",
        layer = "BACK",
        repeated = false;
    }
}

cloud_3 = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 129,
        size_y = 71,
        texture = "CLOUD_3",
        layer = "BACK",
        repeated = false;
    }
}

water_top = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "WATER_TOP",
        layer = "BACK",
        repeated = false;
    }
}

water_top10 = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 700,
        size_y = 70,
        texture = "WATER_TOP",
        layer = "BACK",
        repeated = true;
    }
}

water = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "WATER",
        layer = "BACK",
        repeated = false;
    }
}

water10 = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 700,
        size_y = 70,
        texture = "WATER",
        layer = "BACK",
        repeated = true;
    }
}

grass_left = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "GRASS_LEFT",
        layer = "BACK",
        repeated = false;
    }
}

grass_right = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "GRASS_RIGHT",
        layer = "BACK",
        repeated = false;
    }
}

grass_mid = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "GRASS_MID",
        layer = "BACK",
        repeated = false;
    }
}

grass_mid2 = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 140,
        size_y = 70,
        texture = "GRASS_MID",
        layer = "BACK",
        repeated = true;
    }
}

grass_mid3 = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 210,
        size_y = 70,
        texture = "GRASS_MID",
        layer = "BACK",
        repeated = true;
    }
}

plant = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "PLANT",
        layer = "BACK",
        repeated = false;
    }
}

star = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "STAR",
        layer = "BACK",
        repeated = false;
    }
}

bridge = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "BRIDGE",
        layer = "BACK",
        repeated = false;
    }
}

bridge2 = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 140,
        size_y = 70,
        texture = "BRIDGE",
        layer = "BACK",
        repeated = true;
    }
}

bridge3 = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 210,
        size_y = 70,
        texture = "BRIDGE",
        layer = "BACK",
        repeated = true;
    }
}

fence_broken = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "FENCE_BROKEN",
        layer = "BACK",
        repeated = false;
    }
}

sign_right = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "SIGN_RIGHT",
        layer = "BACK",
        repeated = false;
    }
}

bush = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "BUSH",
        layer = "BACK",
        repeated = false;
    }
}

mushroom_red = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "MUSHROOM_RED",
        layer = "BACK",
        repeated = false;
    }
}

rock = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "ROCK",
        layer = "BACK",
        repeated = false;
    }
}

sign_exit = {
    PositionComponent = {},
    SpriteComponent = {
        size_x = 70,
        size_y = 70,
        texture = "SIGN_EXIT",
        layer = "BACK",
        repeated = false;
    }
}

fly = {
    PositionComponent = {},
    AnimationComponent = {
        animation = "FLY",
        layer = "MIDDLE"
    }
}

fly = {
    PositionComponent = {},
    AnimationComponent = {
        animations = {"FLY"},
        layer = "MIDDLE",
        activeAnimation = "FLY"
    }
}

player = {
    PositionComponent = {},
    AnimationComponent = {
        animations = {"PLAYER_WALK", "PLAYER_IDDLE"},
        layer = "FRONT",
        activeAnimation = "PLAYER_IDDLE"
    },
    InputComponent = {
        ARROW_RIGHT = "right_pressed",
        ARROW_LEFT = "left_pressed",
        NO_KEY_PRESSED = "no_pressed"
    },
    StateComponent = {
        IDDLE = "player_states",
        MOVE_LEFT = "player_states",
        MOVE_RIGHT = "player_states"
    },
    MovementComponent = {
        speedValue = 2,
        accValue = 0
    },
    CameraComponent = {
        xOffset = 300,
        yOffset = 100
    }
}


