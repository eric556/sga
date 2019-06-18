PKPlayer = {}

function PKPlayer.new()
    local entity = entityManager:createEntity()
    local transform = entity:addTransform()
    transform.position = Vector3.new(1920 / 2, 1080 / 2, 0)
    transform.scale = Vector2.new(1, 1)
    local input = entity:addInput()
    input.speed = 100
    local kb = entity:addKineticBody()
    local texture = entity:addAnimatedSprite()
    texture.texture_id = "pokemon_player_sheet"
    texture:setCurrentAnimation("idle")
    texture.currentAnimationFrame = 0
    texture.sprite:setOrigin(32, 32)
    local frame_defs = {}
    i = 1
    for y = 0,3 do
        for x = 0,3 do
            frame_defs[i] = { x=x * 64, y=y * 64, width=64, height=64}
            i = i + 1
        end
    end

    animations = {
        up = {
            {frame=frame_defs[13], time=0.1}, 
            {frame=frame_defs[14], time=0.1}, 
            {frame=frame_defs[15], time=0.1}, 
            {frame=frame_defs[16], time=0.1}, 
        },
        down = {
            {frame=frame_defs[1], time=0.1}, 
            {frame=frame_defs[2], time=0.1}, 
            {frame=frame_defs[3], time=0.1}, 
            {frame=frame_defs[4], time=0.1}, 
        },
        left = {
            {frame=frame_defs[5], time=0.1}, 
            {frame=frame_defs[6], time=0.1}, 
            {frame=frame_defs[7], time=0.1}, 
            {frame=frame_defs[8], time=0.1},
        },
        right = {
            {frame=frame_defs[9], time=0.1}, 
            {frame=frame_defs[10], time=0.1}, 
            {frame=frame_defs[11], time=0.1}, 
            {frame=frame_defs[12], time=0.1}, 
        },
        idle = {
            {frame=frame_defs[1], time=1}
        }
    }
    texture:setAnimations(animations)

    return entity
end