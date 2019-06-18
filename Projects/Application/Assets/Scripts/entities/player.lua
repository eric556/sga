Player = {}

function Player.new()
    local entity = entityManager:createEntity()
    local transform = entity:addTransform()
    transform.position = Vector3.new(1920 / 2, 1080 / 2, 0)
    transform.scale = Vector2.new(10, 10)
    local input = entity:addInput()
    input.speed = 500
    local kb = entity:addKineticBody()
    local texture = entity:addAnimatedSprite()
    texture.texture_id = "mini_char"
    texture:setCurrentAnimation("idle")
    texture.currentAnimationFrame = 0
    texture.sprite:setOrigin(8, 8)
    local frame_defs = {}
    i = 1
    for y = 0,7 do
        for x = 0,5 do
            frame_defs[i] = { x=x * 16, y=y * 16, width=16, height=16}
            i = i + 1
        end
    end

    animations = {
        up = {
            {frame=frame_defs[25], time=0.1}, 
            {frame=frame_defs[26], time=0.1}, 
            {frame=frame_defs[27], time=0.1}, 
            {frame=frame_defs[28], time=0.1}, 
            {frame=frame_defs[29], time=0.1}, 
            {frame=frame_defs[30], time=0.1}
        },
        down = {
            {frame=frame_defs[1], time=0.1}, 
            {frame=frame_defs[2], time=0.1}, 
            {frame=frame_defs[3], time=0.1}, 
            {frame=frame_defs[4], time=0.1}, 
            {frame=frame_defs[5], time=0.1},
            {frame=frame_defs[6], time=0.1}
        },
        left = {
            {frame=frame_defs[13], time=0.1}, 
            {frame=frame_defs[14], time=0.1}, 
            {frame=frame_defs[15], time=0.1}, 
            {frame=frame_defs[16], time=0.1}, 
            {frame=frame_defs[17], time=0.1}, 
            {frame=frame_defs[18], time=0.1}
        },
        right = {
            {frame=frame_defs[37], time=0.1}, 
            {frame=frame_defs[38], time=0.1}, 
            {frame=frame_defs[39], time=0.1}, 
            {frame=frame_defs[40], time=0.1}, 
            {frame=frame_defs[41], time=0.1}, 
            {frame=frame_defs[42], time=0.1}
        },
        down_left = {
            {frame=frame_defs[7], time=0.1},
            {frame=frame_defs[8], time=0.1},
            {frame=frame_defs[9], time=0.1},
            {frame=frame_defs[10], time=0.1},
            {frame=frame_defs[11], time=0.1},
            {frame=frame_defs[12], time=0.1},
        },
        down_right = {
            {frame=frame_defs[43], time=0.1},
            {frame=frame_defs[44], time=0.1},
            {frame=frame_defs[45], time=0.1},
            {frame=frame_defs[46], time=0.1},
            {frame=frame_defs[47], time=0.1},
            {frame=frame_defs[48], time=0.1},
        },
        up_right = {
            {frame=frame_defs[31], time=0.1},
            {frame=frame_defs[32], time=0.1},
            {frame=frame_defs[33], time=0.1},
            {frame=frame_defs[34], time=0.1},
            {frame=frame_defs[35], time=0.1},
            {frame=frame_defs[36], time=0.1},
        },
        up_left = {
            {frame=frame_defs[19], time=0.1},
            {frame=frame_defs[20], time=0.1},
            {frame=frame_defs[21], time=0.1},
            {frame=frame_defs[22], time=0.1},
            {frame=frame_defs[23], time=0.1},
            {frame=frame_defs[24], time=0.1},

        },
        idle = {
            {frame=frame_defs[1], time=1}
        }
    }
    texture:setAnimations(animations)

    return entity
end