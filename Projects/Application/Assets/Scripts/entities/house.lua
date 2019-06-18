Houses = {
    Blue = {},
    Green = {}
}

function Houses.Blue.new(position)
    local entity = entityManager:createEntity()
    local transform = entity:addTransform()
    transform.position = position
    transform.scale = Vector2.new(3, 3)
    local sprite = entity:addSprite()
    sprite.textureRect = IntRect.new(240, 64, 80, 96)
    sprite.useTextureRect = true
    sprite.texture_id = "pokemon_sheet"
    return entity
end

House_green = {}

function Houses.Green.new(position)
    local entity = entityManager:createEntity()
    local transform = entity:addTransform()
    transform.position = position
    transform.scale = Vector2.new(3, 3)
    local sprite = entity:addSprite()
    sprite.textureRect = IntRect.new(336, 64, 80, 96)
    sprite.useTextureRect = true
    sprite.texture_id = "pokemon_sheet"
    return entity
end
