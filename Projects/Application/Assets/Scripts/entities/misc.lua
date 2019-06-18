Misc = {
    Mailbox = {}
}

function Misc.Mailbox.new(position)
    local entity = entityManager:createEntity()
    local transform = entity:addTransform()
    transform.scale = Vector2.new(3, 3)
    if position ~= nil then
        transform.position = position
    end
    local sprite = entity:addSprite()
    sprite.texture_id = "pokemon_sheet"
    sprite.useTextureRect = true
    sprite.textureRect = IntRect.new(32, 128, 16, 32)
    
    return entity
end